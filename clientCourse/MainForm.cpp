#include "MainForm.h"
#include "SignIn.h"
#include "SignUp.h"

using namespace clientCourse;

int authorization()
{
	//�������� ���� �����������
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
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	int nodeType = authorization();

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MainForm(nodeType));

	return 0;
}