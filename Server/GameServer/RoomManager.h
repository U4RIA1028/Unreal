#pragma once
#include "JobQueue.h"
class Room;

class RoomManager : public JobQueue
{
public:
	RoomManager();
	~RoomManager();

	void GameCreate(PlayerRef player);
	void GameDelete(string  roomId);

	void GameInside(PlayerRef player, string  roomId);

	RoomManagerRef GetRef() { return static_pointer_cast<RoomManager>(shared_from_this()); }

private:
	// RoomId�� String������ �ξ��µ�,��û ���� ���� �����͸� �˻��ϴ� ���� �ƴϸ� �׷��� �ӵ����̰�
	// ���� �ʴ� �ٴ� ������ ���� ����.
	// https://blog.naver.com/PostView.naver?blogId=kal9107&logNo=223044041516

	map<string, RoomRef>	_rooms;
};

extern RoomManagerRef GRoom;