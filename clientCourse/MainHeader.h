#pragma once

#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <vector>
#include <string>
#include <WinSock2.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>

#include "Actions.h"

const int
MESSAGE_STATE_UNREAD = 1,
MESSAGE_STATE_READ = 2,
MESSAGE_STATE_ACCEPT = 3,
MESSAGE_STATE_DENIED = 4;

const int
RETURN_STATE_NONE = 0,
RETURN_STATE_UPDATE_CONFS = 1,
RETURN_STATE_UPDATE_MESSAGES = 2;

const int
ACCOUNT_TYPE_SCIENTIST = 0,
ACCOUNT_TYPE_ADMINISTRATOR = 1;

const int
MESSAGE_INFORMATION = 1,
MESSAGE_INVITE = 2,
MESSAGE_REQUEST = 3;

const int
ALREADY_IN = 1,
NOT_ALREADY_IN = 2;

extern __int64 accountID;
extern std::string login;

extern std::vector<std::vector<char>> ServerMessageQueue;

extern SOCKET _socket;

int getHeaderSize();

std::string getStringFromSystemString(System::String ^st);
void writeHeader(std::vector<char> &mass, DataFormat d);
void writeDataToMessage(std::vector<char> &mass, std::string st, int &offset);
void writeIntToMessage(std::vector<char> &mass, int value, int &offset);
void writeInt64ToMessage(std::vector<char> &mass, __int64 value, int &offset);
void writeStringToMessage(std::vector<char> &mass, std::string st, int &offset);

void readHeader(std::vector<char> mass, DataFormat &d);
void readDataFromMessage(std::vector<char> mass, std::string &st, int size, int &offset);
void readIntFromMessage(std::vector<char> mass, int &value, int &offset);
void readInt64FromMessage(std::vector<char> mass, __int64 &value, int &offset);
void readStringFromMessage(std::vector<char> mass, std::string &st, int &offset);

void printCharMass(std::vector<char> mass);

Microsoft::Office::Interop::Excel::Application^ createExcelFile();
void writeToExcel(Microsoft::Office::Interop::Excel::Application^ excelApp, std::vector<std::vector<std::string> > matr);
void saveAndExitExcel(Microsoft::Office::Interop::Excel::Application^ excelApp, System::String ^path);
#endif