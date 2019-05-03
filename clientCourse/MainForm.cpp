#include "MainForm.h"
#include "SignIn.h"
#include "SignUp.h"

using namespace clientCourse;

[STAThreadAttribute]
int main(array<System::String^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//�������� ���� �����������
	Application::Run(gcnew SignIn());

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MainForm());
	return 0;
}