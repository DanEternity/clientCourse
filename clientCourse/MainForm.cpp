#define WIN32_LEAN_AND_MEAN

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include "MainForm.h"
#include "SignIn.h"
#include "SignUp.h"
#include "Network.h"


//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdlib.h>
//#include <stdio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib


using namespace clientCourse;

[STAThreadAttribute]
int main(array<System::String^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SOCKET socket;
	if (NetworkSetup(socket) != 0)
	{
		WSACleanup();
		return 0; // error
	}

	//�������� ���� �����������
	Application::Run(gcnew SignIn());

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MainForm());


	WSACleanup();
	return 0;
}