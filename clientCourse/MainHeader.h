#pragma once

#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <vector>
#include <WinSock2.h>
#include <msclr\marshal_cppstd.h>

const int
ACCOUNT_TYPE_ADMINISTRATOR = 0,
ACCOUNT_TYPE_SCIENTIST = 1;

const int
MESSAGE_INFORMATION = 0,
MESSAGE_INVITE = 1,
MESSAGE_REQUEST = 2;

static std::vector<std::vector<char>> ServerMessageQueue;

static SOCKET _socket;

std::string getStringFromSystemString();

#endif