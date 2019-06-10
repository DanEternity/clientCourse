#pragma once

#include "Network.h"

const int
SIGN_IN_STATE_NONE = 0,
SIGN_IN_STATE_ACCESS = 1,
SIGN_IN_STATE_DENIED = 2,
SIGN_IN_STATE_SIGN_UP = 3,
SIGN_IN_STATE_ERROR = -1;

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл¤ SignIn
	/// </summary>
	public ref class SignIn : public System::Windows::Forms::Form
	{
	public: int state;
	private: System::Windows::Forms::Timer^  timer1;
	public: int type;

		SignIn(void)
		{
			InitializeComponent();

			state = SIGN_IN_STATE_NONE;
			
			timer1->Start();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SignIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  signInLogin;
	private: System::Windows::Forms::TextBox^  signInPassword;
	private: System::Windows::Forms::Label^  signInLabelLogin;
	private: System::Windows::Forms::Label^  signInLabelPassword;
	private: System::Windows::Forms::Button^  signInButtonOK;
	private: System::Windows::Forms::Button^  signInButtonRegistration;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ќб¤зательна¤ переменна¤ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл¤ поддержки конструктора Ч не измен¤йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->signInLogin = (gcnew System::Windows::Forms::TextBox());
			this->signInPassword = (gcnew System::Windows::Forms::TextBox());
			this->signInLabelLogin = (gcnew System::Windows::Forms::Label());
			this->signInLabelPassword = (gcnew System::Windows::Forms::Label());
			this->signInButtonOK = (gcnew System::Windows::Forms::Button());
			this->signInButtonRegistration = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(74, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Авторизация";
			// 
			// signInLogin
			// 
			this->signInLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signInLogin->Location = System::Drawing::Point(113, 59);
			this->signInLogin->Name = L"signInLogin";
			this->signInLogin->Size = System::Drawing::Size(190, 32);
			this->signInLogin->TabIndex = 1;
			// 
			// signInPassword
			// 
			this->signInPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signInPassword->Location = System::Drawing::Point(113, 103);
			this->signInPassword->Name = L"signInPassword";
			this->signInPassword->Size = System::Drawing::Size(190, 32);
			this->signInPassword->TabIndex = 2;
			this->signInPassword->UseSystemPasswordChar = true;
			// 
			// signInLabelLogin
			// 
			this->signInLabelLogin->AutoSize = true;
			this->signInLabelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signInLabelLogin->Location = System::Drawing::Point(12, 65);
			this->signInLabelLogin->Name = L"signInLabelLogin";
			this->signInLabelLogin->Size = System::Drawing::Size(78, 26);
			this->signInLabelLogin->TabIndex = 3;
			this->signInLabelLogin->Text = L"Логин:";
			// 
			// signInLabelPassword
			// 
			this->signInLabelPassword->AutoSize = true;
			this->signInLabelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signInLabelPassword->Location = System::Drawing::Point(12, 103);
			this->signInLabelPassword->Name = L"signInLabelPassword";
			this->signInLabelPassword->Size = System::Drawing::Size(95, 26);
			this->signInLabelPassword->TabIndex = 4;
			this->signInLabelPassword->Text = L"Пароль:";
			// 
			// signInButtonOK
			// 
			this->signInButtonOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->signInButtonOK->Location = System::Drawing::Point(174, 158);
			this->signInButtonOK->Name = L"signInButtonOK";
			this->signInButtonOK->Size = System::Drawing::Size(129, 39);
			this->signInButtonOK->TabIndex = 5;
			this->signInButtonOK->Text = L"Войти";
			this->signInButtonOK->UseVisualStyleBackColor = true;
			this->signInButtonOK->Click += gcnew System::EventHandler(this, &SignIn::signInButtonOK_Click);
			// 
			// signInButtonRegistration
			// 
			this->signInButtonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signInButtonRegistration->Location = System::Drawing::Point(17, 158);
			this->signInButtonRegistration->Name = L"signInButtonRegistration";
			this->signInButtonRegistration->Size = System::Drawing::Size(151, 39);
			this->signInButtonRegistration->TabIndex = 6;
			this->signInButtonRegistration->Text = L"Регистрация";
			this->signInButtonRegistration->UseVisualStyleBackColor = true;
			this->signInButtonRegistration->Click += gcnew System::EventHandler(this, &SignIn::signInButtonRegistration_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &SignIn::timer1_Tick);
			// 
			// SignIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 209);
			this->Controls->Add(this->signInButtonRegistration);
			this->Controls->Add(this->signInButtonOK);
			this->Controls->Add(this->signInLabelPassword);
			this->Controls->Add(this->signInLabelLogin);
			this->Controls->Add(this->signInPassword);
			this->Controls->Add(this->signInLogin);
			this->Controls->Add(this->label1);
			this->Name = L"SignIn";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SignIn";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void createMessage(std::vector<char> &mass, int &offset)
{
	std::string login = getStringFromSystemString(this->signInLogin->Text);
	std::string password = getStringFromSystemString(this->signInPassword->Text);

	__int64 Account = 0;
	Actions ActionID = action_auth;
	int PacketID = 0;
	int PacketCountExpected = 0;

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
	int start = 3 * sizeof(int);
	int sizeLogin = login.size();
	int sizePassword = password.size();
	writeIntToMessage(mass, start, offset);
	writeIntToMessage(mass, sizeLogin, offset);
	writeIntToMessage(mass, sizePassword, offset);
	writeDataToMessage(mass, login, offset);
	writeDataToMessage(mass, password, offset);
}

//OK_button
	private: System::Void signInButtonOK_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//запуск процесса проверки логина и пароля
		std::vector<char> mass;
		mass.resize(200);

		int offset = 0;
		createMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);

		while (ServerMessageQueue.empty())
		{
			UpdateSocket(_socket);
			Sleep(0);
		}

		if (!ServerMessageQueue.empty())
		{
			std::vector<char> q = ServerMessageQueue.front();
			ServerMessageQueue.erase(ServerMessageQueue.begin());

			printCharMass(q);
			DataFormat d;
			readHeader(q, d);
			int offset = getHeaderSize();

			if (d.ActionID == action_auth_fail)
			{
				MessageBox::Show(
					"Неправильный логин/пароль",
					"Предупреждение",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning,
					MessageBoxDefaultButton::Button1,
					MessageBoxOptions::DefaultDesktopOnly
				);

				this->Activate();
				return;
			}
			else if (d.ActionID == action_auth_success)
			{
				int t;
				readIntFromMessage(q, t, offset);
				type = t - 1;
				accountID = d.Account;
				login = getStringFromSystemString(this->signInLogin->Text);
			}
		}

	state = SIGN_IN_STATE_ACCESS;
	this->Close();
}

//SignUp_button
private: System::Void signInButtonRegistration_Click(System::Object^  sender, System::EventArgs^  e) 
{
	state = SIGN_IN_STATE_SIGN_UP;
	this->Close();
}

//timer
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	UpdateSocket(_socket);
}
};
}