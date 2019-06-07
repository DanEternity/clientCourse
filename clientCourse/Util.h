#pragma once

#include <vector>
#include <algorithm>
#include <string>

#undef min;
struct tBuff
{
	char SIG[5] = "PAC1";
	__int32 size = 0; // сколько всего должно быть пакетов
	__int32 number = 0; // номер пакета
	__int32 id = 0; // индекс группы пакетов

	char data[200];

	__int32 stop = INT_MAX;
};

std::vector<std::vector<char>> RawToBuff(char * rawData, int size, int id);
std::vector<char> BuffToRaw(std::vector<std::vector<char>> &d);
