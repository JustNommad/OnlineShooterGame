#include "ClientS.h"
#include <iostream>

	namespace server
	{
		int X_ = 0, Y_ = 0;
		int dX_ = 0, dY_ = 0;
		int fx_ = 0, fy_ = 0;
		int fdx_ = 0, fdy_ = 0;
		int HP = 0;
		bool GameState = false;
		bool right = false;
		bool left = false;
		bool hit = false;
		SOCKET Connection;
		PlayerData playerdata_;

		bool ProcessPacket(Packet packettype) {
			ZeroMemory(&playerdata_, sizeof(playerdata_));
			switch (packettype) {
			case P_PlayerData:
			{
				recv(Connection, (char*)&playerdata_, sizeof(playerdata_), NULL);
				X_ = playerdata_.Col_x;
				Y_ = playerdata_.Col_y;
				dX_ = playerdata_.Pic_x;
				dY_ = playerdata_.Pic_y;
				fx_ = playerdata_.Fire_x;
				fy_ = playerdata_.Fire_y;
				fdx_ = playerdata_.FirePic_x;
				fdy_ = playerdata_.FirePic_y;
				GameState = playerdata_.gamestate;
				right = playerdata_.right_c;
				left = playerdata_.left_c;
				hit = playerdata_.hit;
				HP = playerdata_.health;

				break;
			}
			default:
				std::cout << "Unrecognized packet: " << packettype << std::endl;
				break;
			}

			return true;
		}

		void ClientHandler() {
			Packet packettype;
			while (true) {
				recv(Connection, (char*)& packettype, sizeof(Packet), NULL);

				if (!ProcessPacket(packettype)) {
					break;
				}
			}
			closesocket(Connection);
		}

		int ClientS()
		{
			WSAData wsaData;
			WORD DLLVersion = MAKEWORD(2, 1);
			if (WSAStartup(DLLVersion, &wsaData) != 0)
			{
				std::cout << "Error lib" << std::endl;
				exit(1);
			}
			SOCKADDR_IN addr;
			int sizeofaddr = sizeof(addr);
			addr.sin_addr.s_addr = inet_addr("192.168.31.192");
			addr.sin_port = htons(1234);
			addr.sin_family = AF_INET;

			Connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (connect(Connection, (SOCKADDR*)& addr, sizeof(addr)) != 0)
			{
				std::cout << "Error connect" << std::endl;
				return 1;
			}
			else
			{
				std::cout << "Connected" << std::endl;
				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
			}
			return 0;
		}
		void SendingPos(Packet packettype, PlayerData x)
		{
		
			PlayerData pd_ = x;

			Packet Packettype = packettype;
			send(Connection, (char*)& Packettype, sizeof(Packet), NULL);
			//send(Connection, (char*)& msg_size, sizeof(int), NULL);
			send(Connection, (char*)&pd_, sizeof(pd_), NULL);
		}

		int Get_x() { return X_; }
		int Get_y() { return Y_; }
		int Get_dx() { return dX_; }
		int Get_dy() { return dY_; }
		int Get_fx() { return fx_; }
		int Get_fy() { return fy_; }
		int Get_fdx() { return fdx_; }
		int Get_fdy() { return fdy_; }
		bool Get_gamestate() { return GameState; }
		bool Get_Hit() { return hit; }
		bool Get_Left() { return left; }
		bool Get_Right() { return right; }
		int Get_HP() { return HP; }
	}