#include "ClientS.h"
#include <iostream>

	namespace server
	{
		int X_ = 0, Y_ = 0;
		int dX_ = 0, dY_ = 0;
		int xf_ = 0, yf_ = 0;
		int xdf_ = 0, ydf_ = 0;
		bool GameState = false;
		SOCKET Connection;
		bool ProcessPacket(Packet packettype) {
			switch (packettype) {
			case P_PlayerPos_X:
			{
				int data;
				recv(Connection, (char*)&data, sizeof(int), NULL);
				dX_ = data;
				break;
			}
			case P_PlayerPos_Y:
			{
				int data;
				recv(Connection, (char*)&data, sizeof(int), NULL);
				dY_ = data;
				break;
			}
			case P_PlayerPosCol_X:
			{
				int data;
				recv(Connection, (char*)&data, sizeof(int), NULL);
				X_ = data;
				break;
			}
			case P_PlayerPosCol_Y:
			{
				int data;
				recv(Connection, (char*)&data, sizeof(int), NULL);
				Y_ = data;
				break;
			}
			case P_FirePos_X:
			{
				int data;
				recv(Connection, (char*)& data, sizeof(int), NULL);
				xdf_ = data;
				break;
			}
			case P_FirePos_Y:
			{
				int data;
				recv(Connection, (char*)& data, sizeof(int), NULL);
				ydf_ = data;
				break;
			}
			case P_FirePosCol_X:
			{
				int data;
				recv(Connection, (char*)& data, sizeof(int), NULL);
				xf_ = data;
				break;
			}
			case P_FirePosCol_Y:
			{
				int data;
				recv(Connection, (char*)& data, sizeof(int), NULL);
				yf_ = data;
				break;
			}
			case P_GameState:
			{
				int data;
				recv(Connection, (char*)&data, sizeof(int), NULL);
				if (data == 1)
				{
					GameState = true;
				}
				else
				{
					GameState = false;
				}
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
			addr.sin_addr.s_addr = inet_addr("127.0.0.1");
			addr.sin_port = htons(1111);
			addr.sin_family = AF_INET;

			Connection = socket(AF_INET, SOCK_STREAM, NULL);
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
		void SendingPos(Packet packettype, int x)
		{
		
			int X = x;

			Packet Packettype = packettype;
			send(Connection, (char*)& Packettype, sizeof(Packet), NULL);
			//send(Connection, (char*)& msg_size, sizeof(int), NULL);
			send(Connection, (char*)&X, sizeof(int), NULL);
			Sleep(10);
		}

		int Get_x() { return X_; }
		int Get_y() { return Y_; }
		int Get_dx() { return dX_; }
		int Get_dy() { return dY_; }
		bool Get_gamestate() { return GameState; }
	}