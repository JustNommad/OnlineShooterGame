#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma warning(disable:4996)

SOCKET Connections[100];
int Counter = 0;

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

bool ProcessPacket(int index, Packet packettype) {
	switch (packettype) {
	case P_PlayerPos_X:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_PlayerPos_X;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)&x, sizeof(int), NULL);
		}
		break;
	}
	case P_PlayerPos_Y:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_PlayerPos_Y;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)&x, sizeof(int), NULL);
		}
		break;
	}
	case P_PlayerPosCol_X:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_PlayerPosCol_X;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_PlayerPosCol_Y:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_PlayerPosCol_Y;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_FirePos_X:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_FirePos_X;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_FirePos_Y:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_FirePos_Y;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_FirePosCol_X:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_PlayerPos_X;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_FirePosCol_Y:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_FirePosCol_Y;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& x, sizeof(int), NULL);
		}
		break;
	}
	case P_GameState:
	{
		int x;
		recv(Connections[index], (char*)& x, sizeof(int), NULL);

		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			Packet msgtype = P_GameState;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)&x, sizeof(int), NULL);
		}
		break;
	}
	default:
		std::cout << "Unrecognized packet: " << packettype << std::endl;
		break;
	}
	return true;
}

void ClientHandler(int index) {
	Packet packettype;
	while (true) {
		recv(Connections[index], (char*)& packettype, sizeof(Packet), NULL);

		if (!ProcessPacket(index, packettype)) {
			break;
		}
	}
	closesocket(Connections[index]);
}

int main(int argc, char* argv[])
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)& addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	for (int i = 0; i < 100; i++) {
		newConnection = accept(sListen, (SOCKADDR*)& addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			std::cout << "Client Connected!\n";
			Connections[i] = newConnection;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
		}
	}

	system("pause");
	return 0;
}