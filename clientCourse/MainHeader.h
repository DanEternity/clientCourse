#pragma once

#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <vector>
#include <WinSock2.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>

#include "Actions.h"

const int
ACCOUNT_TYPE_SCIENTIST = 0,
ACCOUNT_TYPE_ADMINISTRATOR = 1;

const int
MESSAGE_INFORMATION = 0,
MESSAGE_INVITE = 1,
MESSAGE_REQUEST = 2;

extern __int64 accountID;

extern std::vector<std::vector<char>> ServerMessageQueue;

extern SOCKET _socket;

int getHeaderSize();

std::string getStringFromSystemString(System::String ^st);
void writeHeader(std::vector<char> &mass, DataFormat d);
void writeDataToMessage(std::vector<char> &mass, std::string st, int &offset);
void writeIntToMessage(std::vector<char> &mass, int value, int &offset);
void writeInt64ToMessage(std::vector<char> &mass, __int64 value, int &offset);

void readHeader(std::vector<char> mass, DataFormat &d);
void readDataFromMessage(std::vector<char> mass, std::string &st, int size, int &offset);
void readIntFromMessage(std::vector<char> mass, int &value, int &offset);
void readInt64FromMessage(std::vector<char> mass, __int64 &value, int &offset);

void printCharMass(std::vector<char> mass);
#endif