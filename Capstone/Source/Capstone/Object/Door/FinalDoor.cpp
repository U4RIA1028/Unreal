// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Door/FinalDoor.h"
#include "CapstoneMyPlayer.h"
#include "Capstone.h"

AFinalDoor::AFinalDoor()
{
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));

	Door->SetupAttachment(RootComponent);

}


void AFinalDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AFinalDoor::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_DOOR);

	Super::Init();
}

void AFinalDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AFinalDoor::OnClicked(class ACapstoneMyPlayer* Player)
{
	UE_LOG(LogTemp, Warning, TEXT("Interact!"));

	// Key를 가지고 있는 로직

		if (Player->HasFinalKey())
		{
			Player->SetFinalKey(false);
			Player->ResetRoomCount();
			SendPacket(Player);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Need Final Key"));
			UE_LOG(LogTemp, Warning, TEXT("RoomCount %d"),Player->GetRoomCount());
		}

		return true;
}

void AFinalDoor::SendPacket(ACapstoneMyPlayer* Player)
{
	Protocol::C_GAME_END EndPkt;
	Protocol::ObjectInfo* Info = EndPkt.mutable_player();
	Info->CopyFrom(*Player->GetPlayerInfo());

	SEND_PACKET(EndPkt);
}