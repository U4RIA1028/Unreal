#include "ClientPacketHandler.h"
#include "BufferReader.h"
#include "Network/PacketSession.h"
#include "Kismet/GameplayStatics.h"

std::map<uint16, handleFunction> _packetHandler;

bool Handle_ENTER_GAME(PacketSessionRef& ref, Protocol::S_ENTER_GAME pkt)
{
	UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance());

	if (pkt.success())
		GameIntance->HandleSpawn(pkt);

	return true;
}

bool Handle_CREATE_GAME(PacketSessionRef& ref, Protocol::S_CREATE_GAME pkt)
{
	// Room Number
	UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance());

	if (pkt.success())
		GameIntance->HandleSpawn(pkt);

	return true;
}

bool Handle_GAME_START(PacketSessionRef& ref, Protocol::S_GAME_START pkt)
{
	if (UCapstoneGameInstance* GameInstance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameInstance->HandleGameStart(pkt);
	return false;
}

bool Handle_LEAVE_GAME(PacketSessionRef& ref, Protocol::S_LEAVE_GAME pkt)
{
	return false;
}

bool Handle_GAME_END(PacketSessionRef& ref, Protocol::S_GAME_END pkt)
{
	if (UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameIntance->HandleGameEnd(pkt);

	return true;
}

bool Handle_SPAWN(PacketSessionRef& ref, Protocol::S_SPAWN pkt)
{
	if (UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameIntance->HandleSpawn(pkt);

	return true;
}

bool Handle_DESPAWN(PacketSessionRef& ref, Protocol::S_DESPAWN pkt)
{
	if (UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameIntance->HandleDespawn(pkt);

	return true;
}

bool Handle_MOVE(PacketSessionRef& ref, Protocol::S_MOVE pkt)
{
	if (UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameIntance->HandleMove(pkt);

	return true;
}

bool Handle_PLAYER_ACTION(PacketSessionRef& ref, Protocol::S_PLAYER_ACTION pkt)
{
	if (UCapstoneGameInstance* GameIntance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
		GameIntance->HandleAnotherPlayerAction(pkt);

	return true;
}

bool Handle_CHAT(PacketSessionRef& ref, Protocol::S_CHAT pkt)
{
	return false;
}

bool Handle_PICK_UP_ITEM(PacketSessionRef& ref, Protocol::S_PICK_UP_ITEM pkt)
{
	return true;
}