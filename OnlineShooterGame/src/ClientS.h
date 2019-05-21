#pragma once
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma warning(disable:4996)

enum Packet {
	P_PlayerPos_X,
	P_PlayerPos_Y,
	P_PlayerPosCol_X,
	P_PlayerPosCol_Y,
	P_FirePos_X,
	P_FirePos_Y,
	P_FirePosCol_X,
	P_FirePosCol_Y,
	P_GameState
};

namespace server
{
	bool ProcessPacket(Packet packettype);
	void ClientHandler();
	int ClientS();
	void SendingPos(Packet packettype, int x);

	int Get_x();
	int Get_y();
	int Get_dx();
	int Get_dy();
	bool Get_gamestate();
}
