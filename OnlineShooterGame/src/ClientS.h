#pragma once
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma warning(disable:4996)

enum Packet {
	P_PlayerData
};

namespace server
{
	struct PlayerData
	{
		int Col_x, Col_y;
		int Pic_x, Pic_y;
		int Fire_x, Fire_y;
		int FirePic_x, FirePic_y;
		int health;
		bool gamestate;
		bool right_c, left_c;
	};
	bool ProcessPacket(Packet packettype);
	void ClientHandler();
	int ClientS();
	void SendingPos(Packet packettype, PlayerData x);

	int Get_x();
	int Get_y() ;
	int Get_dx();
	int Get_dy();
	int Get_fx();
	int Get_fy();
	int Get_fdx();
	int Get_fdy();
	bool Get_gamestate();
	bool Get_Left();
	bool Get_Right();
	int Get_HP();
}
