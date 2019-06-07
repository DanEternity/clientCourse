#pragma once
#include "MainHeader.h"

std::string getStringFromSystemString(System::String ^st)
{
	return msclr::interop::marshal_as<std::string>(st);
}