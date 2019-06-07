#pragma once
#include <vector>

const int
ACCOUNT_TYPE_ADMINISTRATOR = 0,
ACCOUNT_TYPE_SCIENTIST = 1;

const int
MESSAGE_INFORMATION = 0,
MESSAGE_INVITE = 1,
MESSAGE_REQUEST = 2;

static std::vector<std::vector<char>> ServerMessageQueue = std::vector<std::vector<char>>();