#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma warning(disable:4996)

SOCKET Connections[2];
int Counter = 0;

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

enum Packet {
	P_PlayerData
};

bool ProcessPacket(int index, Packet packettype) {
	PlayerData playerdata_;
	switch (packettype) {
	case P_PlayerData:
	{
		ZeroMemory(&playerdata_, sizeof(playerdata_));

		recv(Connections[index], (char*)& playerdata_, sizeof(playerdata_), NULL);
		for (int i = 0; i <= Counter; i++) {
			if (i == index) {
				continue;
			}
			Packet msgtype = P_PlayerData;
			send(Connections[i], (char*)& msgtype, sizeof(Packet), NULL);
			send(Connections[i], (char*)& playerdata_, sizeof(playerdata_), NULL);
			break;
		}
	default:
		std::cout << "Unrecognized packet: " << packettype << std::endl;
		break;
	}
	return true;
	}
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
	addr.sin_addr.s_addr = inet_addr("192.168.31.192");
	addr.sin_port = htons(1234);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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