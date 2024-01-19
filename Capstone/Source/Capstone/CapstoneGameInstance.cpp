// Fill out your copyright notice in the Description page of Project Settings.


#include "CapstoneGameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "PacketSession.h"
#include "Protocol.pb.h"
#include "ClientPacketHandler.h"
#include "Player/CapstonePlayer.h"
#include "Player/CapstoneMyPlayer.h"
#include "Widget/BaseUserWidget.h"
#include "Widget/PlayerBaseWidget.h"
#include "ObjectBase.h"
#include "Door/DoorObject.h"

void UCapstoneGameInstance::CreateToGameRoom(FString PlayerName)
{
	Protocol::C_CREATE_GAME CreateGamePkt;
	std::string StdString(TCHAR_TO_UTF8(*PlayerName));
	CreateGamePkt.set_name(StdString);

	SEND_INSTANCE_PACKET(CreateGamePkt);
}

void UCapstoneGameInstance::InsideToGameRoom(FString PlayerName, FString RoomId)
{
	Protocol::C_ENTER_GAME InsideGamePkt;
	std::string NameString(TCHAR_TO_UTF8(*PlayerName));
	std::string RoomString(TCHAR_TO_UTF8(*RoomId));

	InsideGamePkt.set_name(NameString);
	InsideGamePkt.set_room_id(RoomString);

	SEND_INSTANCE_PACKET(InsideGamePkt);
}

void UCapstoneGameInstance::ConnectToGameServer()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));

	FIPv4Address Ip;
	FIPv4Address::Parse(IpAddress, Ip);

	TSharedRef<FInternetAddr> InternetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddr->SetIp(Ip.Value);
	InternetAddr->SetPort(Port);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connecting To Server...")));

	bool Connected = Socket->Connect(*InternetAddr);

	if (Connected)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Success")));

		// Session
		GameServerSession = MakeShared<PacketSession>(Socket);
		GameServerSession->Run();

		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		MainWidget = Cast<UBaseUserWidget>(CreateWidget(GetWorld(), MainWidgetClass, FName("MainWidget")));
		PlayerWidget = Cast<UPlayerBaseWidget>(CreateWidget(GetWorld(), PlayerWidgetClass, FName("PlayerWidget")));

		if (IsValid(MainWidget) && PlayerController)
		{
			MainWidget->AddToViewport();
			PlayerController->SetInputMode(FInputModeUIOnly());
			PlayerController->bShowMouseCursor = true;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Failed")));
	}
}

void UCapstoneGameInstance::DisconnectFromGameServer()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	Protocol::C_LEAVE_GAME LeavePkt;
	SEND_PACKET(LeavePkt);

	/*if (Socket)
	{
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket(Socket);
		Socket = nullptr;
	}*/
}

void UCapstoneGameInstance::HandleRecvPackets()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->HandleRecvPackets();
}

void UCapstoneGameInstance::SendPacket(SendBufferRef SendBuffer)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->SendPacket(SendBuffer);
}

void UCapstoneGameInstance::WriteObjectInfo(const Protocol::ObjectInfo* ObjectInfo)
{
	if (Writer == nullptr)
	{
		Writer = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		Writer->WriteObjectStart();
	}

	Writer->WriteValue(TEXT("Type"), ObjectInfo->object_type());
	FString MyString = FString::Printf(TEXT("%d"), ObjectInfo->object_id());
	Writer->WriteValue(TEXT("ObjectId"), MyString);
	/*Writer->WriteArrayStart(TEXT("Position"));
	{
		Writer->WriteObjectStart();
		Writer->WriteValue(TEXT("x"), ObjectInfo->move_info().x());
		Writer->WriteValue(TEXT("y"), ObjectInfo->move_info().y());
		Writer->WriteValue(TEXT("z"), ObjectInfo->move_info().z());
		Writer->WriteValue(TEXT("yaw"), ObjectInfo->move_info().yaw());
		Writer->WriteObjectEnd();
	}
	Writer->WriteArrayEnd();*/
}

void UCapstoneGameInstance::TeleportPlayer(ACapstonePlayer* Player, FVector Location, FRotator Rotator)
{
	Player->SetActorLocation(Location);
	Player->SetActorRotation(Rotator);
}

void UCapstoneGameInstance::CloseWriteObjectInfo()
{
	if (Writer != nullptr)
	{
		Writer->WriteObjectEnd();
		Writer->Close();

		//UE_LOG(LogTemp, Warning, TEXT("%s"), FPaths::ProjectDir().
		FString FilePath = FPaths::ProjectDir() + "\\..\\Server\\GameServer" + "Temp.json";

		if (FFileHelper::SaveStringToFile(*JsonStr, *FilePath))
		{
			UE_LOG(LogTemp, Warning, TEXT("Is Success : true"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Is Success : False"));
		}

		Writer = nullptr;
	}
}

void UCapstoneGameInstance::SetObject(AObjectBase* ObjectBase)
{
	uint64 ObjectId = ObjectBase->ObjectId;
	Protocol::ObjectType ObjectType = ObjectBase->ObjectInfo->object_type();

	ObjectItems.Add({ ObjectId, ObjectType }, ObjectBase);

	WriteObjectInfo(ObjectBase->ObjectInfo);
}

void  UCapstoneGameInstance::HandleSpawn(const Protocol::ObjectInfo& PlayerInfo, bool IsMine)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = PlayerInfo.object_id();
	if (Players.Find(ObjectId) != nullptr)
		return;

	if (!PlayerInfo.has_move_info())
		return;

	Protocol::MoveInfo MoveInfo = PlayerInfo.move_info();
	FVector SpawnLocation(MoveInfo.x(), MoveInfo.y(), MoveInfo.z());

	if (IsMine)
	{
		ACapstoneMyPlayer* Player = Cast<ACapstoneMyPlayer>(World->SpawnActor(MyPlayerClass, &SpawnLocation));
		if (Player == nullptr)
			return;
		Player->SetPlayerInfo(PlayerInfo);
		Player->SetDestInfo(PlayerInfo);
		Player->SetIsMine(true);
		MyPlayer = Player;
		Players.Add(PlayerInfo.object_id(), Player);
	}
	else
	{
		ACapstonePlayer* Player = Cast<ACapstonePlayer>(World->SpawnActor(OtherPlayerClass, &SpawnLocation));
		if (Player == nullptr)
			return;
		Player->SetPlayerInfo(PlayerInfo);
		Player->SetDestInfo(PlayerInfo);
		Player->SetIsMine(false);
		Player->SpawnDefaultController();
		Players.Add(PlayerInfo.object_id(), Player);
	}
}

void UCapstoneGameInstance::HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt)
{
	HandleSpawn(EnterGamePkt.player(), true);

	if (MainWidget)
	{
		MyRoomId = FString(EnterGamePkt.room_id().c_str());
		MyPlayerName = FString(EnterGamePkt.player_name().c_str());

		SettingMyPlayer(MyPlayerName, MyRoomId);
	}
}

void UCapstoneGameInstance::HandleSpawn(const Protocol::S_CREATE_GAME& CreateGamePkt)
{
	HandleSpawn(CreateGamePkt.player(), true);

	if (MainWidget)
	{
		MyRoomId = FString(CreateGamePkt.room_id().c_str());
		MyPlayerName = FString(CreateGamePkt.player_name().c_str());

		SettingMyPlayer(MyPlayerName, MyRoomId);
	}
}

void UCapstoneGameInstance::HandleSpawn(const Protocol::S_SPAWN& SpawnPacket)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	for (auto& PlayerInfo : SpawnPacket.players())
	{
		HandleSpawn(PlayerInfo, false);
	}
}

void UCapstoneGameInstance::HandleMove(const Protocol::S_MOVE& MovePkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = MovePkt.player().object_id();
	ACapstonePlayer** FindActor = Players.Find(ObjectId);
	if (FindActor == nullptr)
		return;

	ACapstonePlayer* Player = (*FindActor);
	if (Player->GetIsMine())
		return;

	Player->SetDestInfo(MovePkt.player());
}

void UCapstoneGameInstance::HandleAnotherPlayerAction(const Protocol::S_PLAYER_ACTION& ActionPkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	switch (ActionPkt.action_type())
	{
	case Protocol::ActionType::LIGHT_ON:
		ActionLightOn(ActionPkt.player_id(), ActionPkt.is_right_on());
		break;
	case Protocol::ActionType::DOOR_OPEN:
		ActionDoorOpen(ActionPkt.player_id(), ActionPkt.object_id(), ActionPkt.is_open_door());
		break;
	default:
		break;
	}
}

void UCapstoneGameInstance::HandleDespawn(uint64 ObjectId)
{
	// TODO
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	ACapstonePlayer** FindActor = Players.Find(ObjectId);
	if (FindActor == nullptr)
		return;

	World->DestroyActor(*FindActor);
}

void UCapstoneGameInstance::HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt)
{
	for (uint64 ObjectId : DespawnPkt.object_ids())
	{
		HandleDespawn(ObjectId);
	}
}

void UCapstoneGameInstance::HandleGameStart(const Protocol::S_GAME_START& StartPkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	for (int i = 0; i < StartPkt.player_size(); i++)
	{
		const Protocol::MoveInfo& MoveInfo = StartPkt.player(i);
		ACapstonePlayer** FindActor = Players.Find(MoveInfo.object_id());
		if (FindActor == nullptr)
			return;

		ACapstonePlayer* Player = *(FindActor);

		TeleportPlayer(
			Player,
			FVector(MoveInfo.x(), MoveInfo.y(), MoveInfo.z()),
			FRotator(0.f, MoveInfo.yaw(), 0.f)
		);
	}
}

void UCapstoneGameInstance::HandleGameEnd(const Protocol::S_GAME_END& GameEndPkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	ACapstonePlayer** FindActor = Players.Find(GameEndPkt.player().object_id());
	if (FindActor == nullptr)
		return;

	ACapstonePlayer* Player = *(FindActor);

	FVector Location = {
		GameEndPkt.player().move_info().x(),
		GameEndPkt.player().move_info().y(),
		GameEndPkt.player().move_info().z()
	};

	TeleportPlayer(
		Player,
		Location,
		FRotator(0.f, GameEndPkt.player().move_info().yaw(), 0.f)
	);
}

void UCapstoneGameInstance::HandleClearActor()
{
	ObjectItems.Empty();
}

void UCapstoneGameInstance::ActionLightOn(uint64 PlayerId, bool IsRight)
{
	ACapstonePlayer** FindActor = Players.Find(PlayerId);
	if (FindActor == nullptr)
		return;

	ACapstonePlayer* Player = (*FindActor);
	Player->OnSpotLight(IsRight);
}

void UCapstoneGameInstance::ActionDoorOpen(uint64 PlayerId, uint64 ObjectId, bool IsClosedDoor)
{
	// TODO
	AObjectBase** FindObject = ObjectItems.Find({ ObjectId, Protocol::ObjectType::OBJECT_DOOR });

	if (*FindObject == nullptr)
		return;

	ADoorObject* Door = Cast<ADoorObject>(*FindObject);
	Door->OpenClosedDoor(IsClosedDoor);
}

void UCapstoneGameInstance::SettingMyPlayer(FString PlayerName, FString RoomId)
{
	MainWidget->RemoveFromViewport();
	PlayerWidget->AddToViewport();
	PlayerWidget->Init();

	if (MyPlayer)
		Cast<ACapstoneMyPlayer>(MyPlayer)->PlayerWidget = PlayerWidget;
}
