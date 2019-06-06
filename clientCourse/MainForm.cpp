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

int authorization()
{
	//Создание окна авторизации
	while (true)
	{
		SignIn ^sIn = gcnew SignIn();
		Application::Run(sIn);

		if (sIn->state == SIGN_IN_STATE_NONE)
			exit(0);

		if (sIn->state == SIGN_IN_STATE_ACCESS)
			return sIn->type;

		if (sIn->state == SIGN_IN_STATE_SIGN_UP)
		{
			SignUp ^sUp = gcnew SignUp();
			Application::Run(sUp);

			if (sUp->state == SIGN_UP_STATE_NONE)
				exit(0);

			if (sUp->state == SIGN_UP_STATE_ACCESS)
				return sUp->type;

			if (sUp->state == SIGN_UP_STATE_SIGN_IN)
				continue;
		}
	}
}

[STAThreadAttribute]
int main(array<System::String^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	/**/
	SOCKET socket;
	if (NetworkSetup(socket) != 0)
	{
		WSACleanup();
		return 0; // error
	}
	else
	{
		printf("Connected!\n");
		char test[2000] = "TEST TEST TEST TEST TEST TEST";
		for (int i(0); i < 1960; i += 5) { test[i] = 'T'; test[i+1] = 'E'; test[i+2] = 'S'; test[i+3] = 'T'; test[i+4] = '_'; }
		SendToServer(test, 1970, socket);
	}
	//Создание окна авторизации
	//Application::Run(gcnew SignIn());
	
	int nodeType = authorization();
	
	// Создание главного окна и его запуск
	Application::Run(gcnew MainForm(nodeType));

	WSACleanup();
	return 0;
}