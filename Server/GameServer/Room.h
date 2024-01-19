#pragma once
#include "JobQueue.h"

struct Point
{
	float x;
	float y;
	float z;
};

class Room : public JobQueue
{
public:
	Room(string roomId);
	virtual ~Room();

	void HandleEnterHostPlayer(PlayerRef player);
	void HandleEnterPlayer(PlayerRef player);
	void HandleLeavePlayer(PlayerRef player);

	void PlayerMove(Protocol::C_MOVE pkt);

private:
	bool EnterPlayer(PlayerRef player);
	bool LeavePlayer(uint64 id);

private:
	void Broadcast(SendBufferRef sendBuffer, uint64 expectedId = 0);

private:
	string								_roomId = 0;
	atomic<bool>						_isStart = false;
	PlayerRef							_hostPlayer = nullptr;
	unordered_map<uint64, PlayerRef>	_players;
	vector<Point>						_spawnPoint;
};

