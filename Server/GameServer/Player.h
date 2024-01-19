#pragma once

class GameSession;
class Room;

class Player : public enable_shared_from_this<Player>
{
public:
	Player();
	virtual ~Player();

	void SetObjectInfo(const Protocol::ObjectInfo info);

public:
	Protocol::ObjectInfo*	objectInfo;
	Protocol::MoveInfo*		moveInfo;

	weak_ptr<GameSession>	session;
	std::string				name;

public:
	atomic<weak_ptr<Room>> room;
};

