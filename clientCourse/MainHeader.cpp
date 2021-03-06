#pragma once

#include "MainHeader.h"

using namespace Microsoft::Office::Interop;

__int64 accountID;
std::string login;

std::vector<std::vector<char> > ServerMessageQueue;

SOCKET _socket;

int getHeaderSize()
{
	return sizeof(__int64) + sizeof(Actions) + sizeof(int) + sizeof(int);
}

std::string getStringFromSystemString(System::String ^st)
{
	return msclr::interop::marshal_as<std::string>(st);
}

void writeHeader(std::vector<char> &mass, DataFormat d)
{
	__int64 Account = d.Account;
	Actions ActionID = d.ActionID;
	int PacketID = d.PacketID;
	int PacketCountExpected = d.PacketCountExpected;

	int offset = 0;
	mass.resize(100);
	memcpy(&mass[offset], &Account, sizeof(__int64));
	offset += sizeof(__int64);

	memcpy(&mass[offset], &ActionID, sizeof(Actions));
	offset += sizeof(Actions);

	memcpy(&mass[offset], &PacketID, sizeof(int));
	offset += sizeof(int);

	memcpy(&mass[offset], &PacketCountExpected, sizeof(int));
	offset += sizeof(int);
}

void resizeIfNeed(std::vector<char> &mass, int offset, int size)
{
	if (mass.size() - offset - 5 < size)
		mass.resize(mass.size() + size);
}

void writeDataToMessage(std::vector<char> &mass, std::string st, int &offset)
{
	resizeIfNeed(mass, offset, st.size());

	memcpy(&mass[offset], &st[0], st.size());
	offset += st.size();
}

void writeIntToMessage(std::vector<char> &mass, int value, int &offset)
{
	resizeIfNeed(mass, offset, sizeof(int));

	memcpy(&mass[offset], &value, sizeof(int));
	offset += sizeof(int);
}

void writeInt64ToMessage(std::vector<char> &mass, __int64 value, int &offset)
{
	resizeIfNeed(mass, offset, sizeof(__int64));

	memcpy(&mass[offset], &value, sizeof(__int64));
	offset += sizeof(__int64);
}

void writeStringToMessage(std::vector<char> &mass, std::string st, int &offset)
{
	int size = st.size();
	writeIntToMessage(mass, size, offset);
	writeDataToMessage(mass, st, offset);
}

void readHeader(std::vector<char> mass, DataFormat &d)
{
	__int64 Account;
	Actions ActionID;
	int PacketID;
	int PacketCountExpected;

	int offset = 0;
	memcpy(&Account, &mass[offset], sizeof(__int64));
	offset += sizeof(__int64);

	memcpy(&ActionID, &mass[offset], sizeof(Actions));
	offset += sizeof(Actions);

	memcpy(&PacketID, &mass[offset], sizeof(int));
	offset += sizeof(int);

	memcpy(&PacketCountExpected, &mass[offset], sizeof(int));
	offset += sizeof(int);

	d.Account = Account;
	d.ActionID = ActionID;
	d.PacketID = PacketID;
	d.PacketCountExpected = PacketCountExpected;
}

void readDataFromMessage(std::vector<char> mass, std::string &st, int size, int &offset)
{
	st.resize(size);

	memcpy(&st[0], &mass[offset], size);
	offset += size;
}

void readIntFromMessage(std::vector<char> mass, int &value, int &offset)
{
	memcpy(&value, &mass[offset], sizeof(int));
	offset += sizeof(int);
}

void readInt64FromMessage(std::vector<char> mass, __int64 &value, int &offset)
{
	memcpy(&value, &mass[offset], sizeof(__int64));
	offset += sizeof(__int64);
}

void readStringFromMessage(std::vector<char> mass, std::string &st, int &offset)
{
	int size;
	readIntFromMessage(mass, size, offset);
	readDataFromMessage(mass, st, size, offset);
}

void printCharMass(std::vector<char> mass)
{
	for (int i(0); i < mass.size(); i++)
	{
		if (mass[i] >= 'a' && mass[i] <= 'z' || mass[i] >= 'A' && mass[i] <= 'Z')
			std::cout << mass[i];
		else std::cout << '%' << (int)mass[i];
	}

	std::cout << std::endl;
}

Microsoft::Office::Interop::Excel::Application^ createExcelFile()
{
	Microsoft::Office::Interop::Excel::Application^ ExcelApp = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();

	return ExcelApp;
}

void writeToExcel(Microsoft::Office::Interop::Excel::Application^ excelApp, std::vector<std::vector<std::string> > matr)
{
	System::Object ^missing = System::Type::Missing;
	excelApp->Workbooks->Add(missing);
	Excel::Worksheet ^sheet = (Excel::Worksheet^)excelApp->ActiveSheet;
	
	//headers
	for (int j(0); j < matr[0].size(); j++)
	{
		sheet->Cells[1, j + 1] = gcnew System::String(matr[0][j].c_str());
		//safe_cast<Microsoft::Office::Interop::Excel::Range^>(excelApp->Cells[0, j + 1]);
	}

	//cells
	for (int i(1); i < matr.size(); i++)
	{
		for (int j(0); j < matr[i].size(); j++)
		{
			sheet->Cells[i + 1, j + 1] = gcnew System::String(matr[i][j].c_str());
			safe_cast<Microsoft::Office::Interop::Excel::Range^>(excelApp->Cells[i + 1, j + 1]);
		}
	}
}

void saveAndExitExcel(Microsoft::Office::Interop::Excel::Application^ excelApp, System::String ^path)
{
	excelApp->ActiveWorkbook->SaveAs(path, System::Type::Missing, System::Type::Missing,
		System::Type::Missing, System::Type::Missing, System::Type::Missing, Excel::XlSaveAsAccessMode::xlExclusive,
		System::Type::Missing, System::Type::Missing, System::Type::Missing, System::Type::Missing, System::Type::Missing);
	//excelApp->ActiveWorkbook->Saved = true;
	excelApp->Quit();
}