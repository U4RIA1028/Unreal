#include "pch.h"
#include "Room.h"
#include "Player.h"

Room::Room(string roomId) : _roomId(roomId)
{
	_spawnPoint.push_back(Point(0.f, 0.f, 0.f));

	for (int i = -3; i <= 4 ; i++)
	{
		_spawnPoint.push_back(Point(0.f, i * 100.f, 88.f ));
	}
}

Room::~Room()
{

}

void Room::HandleEnterHostPlayer(PlayerRef player)
{
	bool success = EnterPlayer(player);
	if (success == false)
	{
		GRoom->DoAsync(&RoomManager::GameDelete, _roomId);

		return;
	}
	player->objectInfo->set_is_host(true);
	uint64 count = _players.size() - 1;

	player->moveInfo->set_x(_spawnPoint[count].x);
	player->moveInfo->set_y(_spawnPoint[count].y);
	player->moveInfo->set_z(_spawnPoint[count].z);

	player->moveInfo->set_yaw(Utils::GetRandom(0.f, 100.f));

	{
		Protocol::S_CREATE_GAME createGamePkt;
		createGamePkt.set_success(success);
		createGamePkt.set_room_id(_roomId);
		createGamePkt.set_player_name(player->name);

		Protocol::ObjectInfo* objectInfo = createGamePkt.mutable_player();
		objectInfo->CopyFrom(*player->objectInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(createGamePkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	_hostPlayer = player;
}

void Room::HandleEnterPlayer(PlayerRef player)
{
	bool success = EnterPlayer(player);
	if (success == false)
		return;

	player->objectInfo->set_is_host(false);
	uint64 count = _players.size() - 1;

	player->moveInfo->set_x(_spawnPoint[count].x);
	player->moveInfo->set_y(_spawnPoint[count].y);
	player->moveInfo->set_z(_spawnPoint[count].z);

	player->moveInfo->set_yaw(Utils::GetRandom(0.f, 100.f));

	{
		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.set_success(success);
		enterGamePkt.set_room_id(_roomId);
		enterGamePkt.set_player_name(player->name);

		Protocol::ObjectInfo* objectInfo = enterGamePkt.mutable_player();
		objectInfo->CopyFrom(*player->objectInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	{
		Protocol::S_SPAWN spawnPkt;

		Protocol::ObjectInfo* objectInfo = spawnPkt.add_players();
		objectInfo->CopyFrom(*player->objectInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
		Broadcast(sendBuffer, player->objectInfo->object_id());
	}

	{
		Protocol::S_SPAWN spawnPkt;

		for (auto& [key, value] : _players)
		{
			Protocol::ObjectInfo* objectInfo = spawnPkt.add_players();
			objectInfo->CopyFrom(*value->objectInfo);
		}

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}
}

void Room::HandleLeavePlayer(PlayerRef player)
{
	if (player == nullptr)
		return;

	if (player == _hostPlayer)
	{
		// TODO
		cout << "Host Player Is Leave" << endl;
	}

	const uint64 objectId = player->objectInfo->object_id();
	bool success = LeavePlayer(objectId);

	if (success == false)
		return;

	{
		Protocol::S_LEAVE_GAME leaveGamePkt;

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(leaveGamePkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	{
		Protocol::S_DESPAWN despawnPkt;
		despawnPkt.add_object_ids(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(despawnPkt);
		Broadcast(sendBuffer, objectId);

		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}
}

void Room::PlayerMove(Protocol::C_MOVE pkt)
{
	auto playerPair = _players.find(pkt.player().object_id());
	if (playerPair == _players.end())
		return;

	PlayerRef player = playerPair->second;
	player->SetObjectInfo(pkt.player());

	{
		Protocol::S_MOVE movePkt;
		Protocol::ObjectInfo* objectInfo = movePkt.mutable_player();
		objectInfo->CopyFrom(pkt.player());

		SendBufferRef SendBuffer = ServerPacketHandler::MakeSendBuffer(movePkt);
		Broadcast(SendBuffer);
	}
}

bool Room::EnterPlayer(PlayerRef player)
{
	uint64 playerId = player->objectInfo->object_id();

	if (_players.find(playerId) != _players.end())
		return false;

	_players.insert(make_pair(playerId, player));

	player->room.store(static_pointer_cast<Room>(shared_from_this()));
	
	return true;
}

bool Room::LeavePlayer(uint64 objectId)
{
	if (_players.find(objectId) == _players.end())
		return false;

	PlayerRef player = _players[objectId];
	player->room.store(weak_ptr<Room>());

	_players.erase(objectId);

	//if (_players.size() == 0)

	return true;
}

void Room::Broadcast(SendBufferRef sendBuffer, uint64 expectedId)
{
	for (auto& [key, value] : _players)
	{
		if (key == expectedId)
			continue;

		if (auto session = value->session.lock())
			session->Send(sendBuffer);
	}
}
