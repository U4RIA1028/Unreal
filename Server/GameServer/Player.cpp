#include "pch.h"
#include "Player.h"

Player::Player()
{
	objectInfo = new Protocol::ObjectInfo();
	moveInfo = objectInfo->mutable_move_info();
}

Player::~Player()
{
	delete objectInfo;
}

void Player::SetObjectInfo(const Protocol::ObjectInfo info)
{
	objectInfo->CopyFrom(info);
	moveInfo = objectInfo->mutable_move_info();
}

