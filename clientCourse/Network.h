#pragma once

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Util.h"

#define DEFAULT_BUFLEN 512

static int PacketID = 0;


int NetworkSetup(SOCKET & client_socket)
{
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	char inet_addr[50] = "";
	int port = 27015;

	std::ifstream fin("config.txt");
	if (!fin.is_open())
	{
		return 1; // config not found;
	}

	while (!fin.eof() && !fin.fail())
	{
		std::string st;
		fin >> st;

		if (st == "#default_ip")
			fin >> inet_addr;
		
		if (st == "#default_port")
			fin >> port;
	}

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;


	char serv_ip[50] = "", serv_port[50] = "";
	memcpy(&serv_ip, &inet_addr, 48U);

	std::string t_port = std::to_string(port);
	memcpy(&serv_port, t_port.c_str(), t_port.size());

	// Resolve the server address and port
	iResult = getaddrinfo(serv_ip, serv_port, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	printf("Connecting...\n");
	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}



		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		DWORD nonBlocking = 1;
		if (ioctlsocket(ConnectSocket, FIONBIO, &nonBlocking) != 0)
		{
			printf("failed to set non-blocking socket\n");
			return false;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	client_socket = ConnectSocket;
}

int SendToServer(char * buffer, int size, SOCKET socket)
{
	/**/
	std::vector<std::vector<char>> r = RawToBuff(buffer, size, ++PacketID);

	for (int i(0); i < r.size(); i++)
	{
		char * q = &r[i][0];
		send(socket, q, 512, 0);
	}
	return 0;
}

int RecieveFromServer(std::vector<char> &t)
{
	t.clear();

	return 0;

}