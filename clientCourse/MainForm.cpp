#include "MainForm.h"
#include "SignIn.h"
#include "SignUp.h"

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
	
	int nodeType = authorization();

	// Создание главного окна и его запуск
	Application::Run(gcnew MainForm(nodeType));

	return 0;
}