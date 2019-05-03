#include "MainForm.h"
#include "SignIn.h"
#include "SignUp.h"

using namespace clientCourse;

[STAThreadAttribute]
int main(array<System::String^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Создание окна авторизации
	Application::Run(gcnew SignIn());

	// Создание главного окна и его запуск
	Application::Run(gcnew MainForm());
	return 0;
}