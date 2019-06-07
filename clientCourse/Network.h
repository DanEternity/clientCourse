#pragma once
#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "Util.h"
#include "MainHeader.h"

#define DEFAULT_BUFLEN 512

static int PacketID = 0;

int NetworkSetup(SOCKET & client_socket);
int SendToServer(char * buffer, int size, SOCKET socket);
int RecieveFromServer(std::vector<char> &t);
int AddToQueue(std::vector<char> rBuff, std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status);
int CheckBufferStatus(std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status);
void UpdateSocket(SOCKET socket);
int ClearBuffer(std::vector<std::pair<int, std::vector<std::vector<char>>>> &bf, std::vector<std::pair<int, int>> &status);


#endif