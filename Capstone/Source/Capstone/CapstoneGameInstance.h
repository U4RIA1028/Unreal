// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Capstone.h"
#include "CapstoneGameInstance.generated.h"

class ACapstonePlayer;
class UBaseUserWidget;
class UPlayerBaseWidget;
class AObjectBase;

/**
 *
 */
UCLASS()
class CAPSTONE_API UCapstoneGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CreateToGameRoom(FString PlayerName);

	UFUNCTION(BlueprintCallable)
	void InsideToGameRoom(FString PlayerName, FString RoomNum);

	UFUNCTION(BlueprintCallable)
	void ConnectToGameServer();

	UFUNCTION(BlueprintCallable)
	void DisconnectFromGameServer();

	UFUNCTION(BlueprintCallable)
	void CloseWriteObjectInfo();

	UFUNCTION(BlueprintCallable)
	void HandleRecvPackets();

	UFUNCTION(BlueprintCallable)
	void HandleClearActor();

	void SendPacket(SendBufferRef SendBuffer);

public:
	// TODO
	void SetObject(AObjectBase* ObjectBase);

	void HandleSpawn(const Protocol::ObjectInfo& PlayerInfo, bool IsMine);
	void HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt);
	void HandleSpawn(const Protocol::S_CREATE_GAME& CreateGamePkt);
	void HandleSpawn(const Protocol::S_SPAWN& SpawnPkt);

	void HandleMove(const Protocol::S_MOVE& MovePkt);
	void HandleAnotherPlayerAction(const Protocol::S_PLAYER_ACTION& ActionPkt);

	void HandleDespawn(uint64 ObjectId);
	void HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt);

	void HandleGameStart(const Protocol::S_GAME_START& StartPkt);
	void HandleGameEnd(const Protocol::S_GAME_END& GameEndPkt);

private:
	void ActionLightOn(uint64 PlayerId, bool IsRight);
	void ActionDoorOpen(uint64 PlayerId, uint64 ObjectId, bool IsClosedDoor);
	void SettingMyPlayer(FString PlayerName, FString RoomId);
	void WriteObjectInfo(const Protocol::ObjectInfo* ObjectInfo);

	void TeleportPlayer(ACapstonePlayer* Player, FVector Location, FRotator Rotator);

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT("127.0.0.1");
	int16 Port = 4000;
	TSharedPtr<class PacketSession> GameServerSession;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACapstonePlayer>	OtherPlayerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACapstonePlayer>	MyPlayerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget>		MainWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget>		PlayerWidgetClass;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBaseUserWidget>		MainWidget;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPlayerBaseWidget>	PlayerWidget;

	FString		MyPlayerName;
	FString		MyRoomId;
	bool		bIsStart = false;

	TObjectPtr<ACapstonePlayer>				MyPlayer;
	TMap<uint64, class ACapstonePlayer*>	Players;

private:
	FString JsonStr;
	TSharedPtr<TJsonWriter<TCHAR>>	Writer;
	TMap<TPair<uint64, Protocol::ObjectType>, AObjectBase*>			ObjectItems;
};
