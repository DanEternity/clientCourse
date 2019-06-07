#pragma once

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Util.h"
#include "MainHeader.h"

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
	//char recvbuf[DEFAULT_BUFLEN];
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

static int iResult;
static struct addrinfo *result = NULL;
static struct addrinfo hints;

static int iSendResult;
static char recvbuf[DEFAULT_BUFLEN];
static int recvbuflen = DEFAULT_BUFLEN;

static std::vector<std::pair<int, std::vector<std::vector<char>>>> que;
static std::vector<std::pair<int, int>> status;

#define DEFAULT_BUFF_TIME 10000

int AddToQueue(std::vector<char> rBuff, std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status)
{
	int bufId;
	memcpy(&bufId, &rBuff[12], sizeof(int));
	bool found = false;
	for (int i(0); i < bf.size(); i++)
	{
		if (bufId == bf[i].first)
		{
			//std::vector<char> t;
			//t.resize(DEFAULT_BUFLEN);
			//memcpy(rBuff[0], &t[0], DEFAULT_BUFLEN);
			bf[i].second.push_back(rBuff);
			return 0;
		}
	}

	std::pair<int, std::vector<std::vector<char>>> elem;

	elem.first = bufId;
	//std::vector<char> t;
	//t.resize(DEFAULT_BUFLEN);
	//memcpy(recvbuf, &t[0], DEFAULT_BUFLEN);
	elem.second.push_back(rBuff);
	bf.push_back(elem);
	status.push_back(std::make_pair(0, 0));

	return 0;
}

int CheckBufferStatus(std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status)
{

	for (int i(0); i < bf.size(); i++)
	{
		int size;
		memcpy(&size, &bf[i].second[0][4], sizeof(int));
		std::vector<bool> parts(size, false);
		for (int j(0); j < bf[i].second.size(); j++)
		{
			int num;
			memcpy(&num, &bf[i].second[j][8], sizeof(int));
			parts[num] = true;
		}

		bool ready = true;

		for (int j(0); j<parts.size(); j++)
			if (parts[j] == false)
			{
				status[i].first++;
				ready = false;
				break;
			}

		if (ready)
		{
			status[i].first = DEFAULT_BUFF_TIME + 1;
			return i;
		}
	}

	return -1;
}

int ClearBuffer(std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status)
{
	for (int i(0); i < bf.size(); i++)
	{
		if (status[i].first > DEFAULT_BUFF_TIME)
		{
			bf.erase(bf.begin() + i);
			status.erase(status.begin() + i);
			i--;
		}
	}

	return 0;
}

void UpdateSocket(SOCKET socket)
{
	iResult = recv(socket, recvbuf, recvbuflen, 0);
	if (iResult > 0) {
		printf("Bytes received: %d\n", iResult);
		printf("%.*s\n", iResult, recvbuf);

		// Handle buffer
		if (iResult != 512)
			return;

		std::vector<char> rBuff(512);
		memcpy(&rBuff[0], recvbuf, 512);

		AddToQueue(rBuff, que, status);

		//HandleBuffer(recvbuf, iResult, ClientSocket); // data / size / socket

	}
	else if (iResult == 0)
		printf("Connection closing...\n");
	else {
		auto err = WSAGetLastError();
		if (err == 10035)
		{

			int id = CheckBufferStatus(que, status);
			if (id != -1)
			{
				std::vector<char> buff;
				buff = BuffToRaw(que[id].second);

			//	HandleBuffer(buff, ClientSocket);
				ServerMessageQueue.push_back(buff);

			}


			ClearBuffer(que, status);
			iResult = 1;
			return;
		}
		printf("recv failed with error: %d\n", err);
		//closesocket(ClientSocket);
		//WSACleanup();
		//return 1;
	}
}