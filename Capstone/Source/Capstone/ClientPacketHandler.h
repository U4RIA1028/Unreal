#pragma once

#include "Protocol.pb.h"
#include <map>

#if UE_BUILD_DEBUG + UE_BUILD_DEVELOPMENT + UE_BUILD_TEST + UE_BUILD_SHIPPING >= 1
#include "Capstone.h"
#endif

using handleFunction = std::function<bool(PacketSessionRef&, BYTE*, uint16)>;
extern std::map<uint16, handleFunction> _packetHandler;
template<typename PacketData, typename handleFunc>
inline bool ParsingPacket(handleFunc func, PacketSessionRef& ref, BYTE* buffer, uint16 len);

bool Handle_ENTER_GAME(PacketSessionRef& ref, Protocol::S_ENTER_GAME pkt);
bool Handle_CREATE_GAME(PacketSessionRef& ref, Protocol::S_CREATE_GAME pkt);
bool Handle_GAME_START(PacketSessionRef& ref, Protocol::S_GAME_START pkt);
bool Handle_LEAVE_GAME(PacketSessionRef& ref, Protocol::S_LEAVE_GAME pkt);
bool Handle_GAME_END(PacketSessionRef& ref, Protocol::S_GAME_END pkt);
bool Handle_SPAWN(PacketSessionRef& ref, Protocol::S_SPAWN pkt);
bool Handle_DESPAWN(PacketSessionRef& ref, Protocol::S_DESPAWN pkt);
bool Handle_MOVE(PacketSessionRef& ref, Protocol::S_MOVE pkt);
bool Handle_PLAYER_ACTION(PacketSessionRef& ref, Protocol::S_PLAYER_ACTION pkt);
bool Handle_CHAT(PacketSessionRef& ref, Protocol::S_CHAT pkt);
bool Handle_PICK_UP_ITEM(PacketSessionRef& ref, Protocol::S_PICK_UP_ITEM pkt);


class ClientPacketHandler
{
public:
	static void Init()
	{
		_packetHandler[Protocol::INGAME::ENTER_GAME] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_ENTER_GAME>(Handle_ENTER_GAME, ref, buf, size); };
		_packetHandler[Protocol::INGAME::CREATE_GAME] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_CREATE_GAME>(Handle_CREATE_GAME, ref, buf, size); };
		_packetHandler[Protocol::INGAME::GAME_START] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_GAME_START>(Handle_GAME_START, ref, buf, size); };
		_packetHandler[Protocol::INGAME::LEAVE_GAME] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_LEAVE_GAME>(Handle_LEAVE_GAME, ref, buf, size); };
		_packetHandler[Protocol::INGAME::GAME_END] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_GAME_END>(Handle_GAME_END, ref, buf, size); };
		_packetHandler[Protocol::INGAME::SPAWN] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_SPAWN>(Handle_SPAWN, ref, buf, size); };
		_packetHandler[Protocol::INGAME::DESPAWN] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_DESPAWN>(Handle_DESPAWN, ref, buf, size); };
		_packetHandler[Protocol::INGAME::MOVE] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_MOVE>(Handle_MOVE, ref, buf, size); };
		_packetHandler[Protocol::INGAME::PLAYER_ACTION] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_PLAYER_ACTION>(Handle_PLAYER_ACTION, ref, buf, size); };
		_packetHandler[Protocol::INGAME::CHAT] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_CHAT>(Handle_CHAT, ref, buf, size); };
		_packetHandler[Protocol::INGAME::PICK_UP_ITEM] = [](PacketSessionRef& ref, BYTE* buf, uint16 size) { return ParsingPacket<Protocol::S_PICK_UP_ITEM>(Handle_PICK_UP_ITEM, ref, buf, size); };

	}
	static bool PakcetHandle(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* head = reinterpret_cast<PacketHeader*>(buffer);

		if (_packetHandler.find(head->type) == _packetHandler.end())
			return false;
		return _packetHandler[head->type](session, buffer, head->size);
	}

public:
	static SendBufferRef MakeSendBuffer(Protocol::C_ENTER_GAME pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::ENTER_GAME); }
	static SendBufferRef MakeSendBuffer(Protocol::C_CREATE_GAME pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::CREATE_GAME); }
	static SendBufferRef MakeSendBuffer(Protocol::C_GAME_START pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::GAME_START); }
	static SendBufferRef MakeSendBuffer(Protocol::C_LEAVE_GAME pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::LEAVE_GAME); }
	static SendBufferRef MakeSendBuffer(Protocol::C_GAME_END pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::GAME_END); }
	static SendBufferRef MakeSendBuffer(Protocol::C_SPAWN pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::SPAWN); }
	static SendBufferRef MakeSendBuffer(Protocol::C_DESPAWN pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::DESPAWN); }
	static SendBufferRef MakeSendBuffer(Protocol::C_MOVE pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::MOVE); }
	static SendBufferRef MakeSendBuffer(Protocol::C_PLAYER_ACTION pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::PLAYER_ACTION); }
	static SendBufferRef MakeSendBuffer(Protocol::C_CHAT pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::CHAT); }
	static SendBufferRef MakeSendBuffer(Protocol::C_PICK_UP_ITEM pkt) { return _MakeSendBuffer(pkt, Protocol::INGAME::PICK_UP_ITEM); }


	template<typename PacketData, typename PacketType>
	static SendBufferRef _MakeSendBuffer(PacketData& pkt, PacketType type);
};

template<typename PacketData, typename PacketType>
inline SendBufferRef ClientPacketHandler::_MakeSendBuffer(PacketData& pkt, PacketType type)
{
	const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
	const uint16 packetSize = dataSize + sizeof(PacketHeader);

#if UE_BUILD_DEBUG + UE_BUILD_DEVELOPMENT + UE_BUILD_TEST + UE_BUILD_SHIPPING >= 1
	SendBufferRef sendBuffer = MakeShared<SendBuffer>(packetSize);
#else
	SendBufferRef sendBuffer = make_shared<SendBuffer>(packetSize);
#endif

	PacketHeader* head = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
	head->type = type;
	head->size = packetSize;

	pkt.SerializeToArray(&head[1], dataSize);
	sendBuffer->Close(packetSize);

	return sendBuffer;
}

template<typename PacketData, typename handleFunc>
inline bool ParsingPacket(handleFunc func, PacketSessionRef& ref, BYTE* buffer, uint16 len)
{
	PacketData pkt;
	pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader));

	return func(ref, pkt);
}
