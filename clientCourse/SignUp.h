#pragma once

#include "Network.h"

const int
SIGN_UP_STATE_NONE = 0,
SIGN_UP_STATE_ACCESS = 1,
SIGN_UP_STATE_DENIED = 2,
SIGN_UP_STATE_SIGN_IN = 3,
SIGN_UP_STATE_ERROR = -1;

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	public: int state;
	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::Label^  labelLastName;
	private: System::Windows::Forms::Label^  labelCityName;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  textBoxPasswordAgain;
	private: System::Windows::Forms::Label^  labelPasswordAgain;
	private: System::Windows::Forms::Label^  labelThemeName;
	private: System::Windows::Forms::TextBox^  textBoxThemeName;
	private: System::Windows::Forms::TextBox^  textBoxCityName;
	private: System::Windows::Forms::TextBox^  textBoxLastName;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Timer^  timer;

	public: int type;

	public: SignUp(void)
	{
		InitializeComponent();

		state = SIGN_UP_STATE_NONE;

		timer->Start();
	}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  signUpButtonRegistration;
	private: System::Windows::Forms::Button^  signUpButtonSignIn;
	private: System::Windows::Forms::Label^  signUpLabelPassword;
	private: System::Windows::Forms::Label^  signUpLabelLogin;
	private: System::Windows::Forms::TextBox^  signUpPassword;
	private: System::Windows::Forms::TextBox^  signUpLogin;
	private: System::Windows::Forms::Label^  SignUpLabel;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->signUpButtonRegistration = (gcnew System::Windows::Forms::Button());
			this->signUpButtonSignIn = (gcnew System::Windows::Forms::Button());
			this->signUpLabelPassword = (gcnew System::Windows::Forms::Label());
			this->signUpLabelLogin = (gcnew System::Windows::Forms::Label());
			this->signUpPassword = (gcnew System::Windows::Forms::TextBox());
			this->signUpLogin = (gcnew System::Windows::Forms::TextBox());
			this->SignUpLabel = (gcnew System::Windows::Forms::Label());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->labelCityName = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxPasswordAgain = (gcnew System::Windows::Forms::TextBox());
			this->labelPasswordAgain = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBoxThemeName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCityName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelThemeName = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// signUpButtonRegistration
			// 
			this->signUpButtonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpButtonRegistration->Location = System::Drawing::Point(17, 210);
			this->signUpButtonRegistration->Name = L"signUpButtonRegistration";
			this->signUpButtonRegistration->Size = System::Drawing::Size(335, 39);
			this->signUpButtonRegistration->TabIndex = 8;
			this->signUpButtonRegistration->Text = L"Зарегистрироваться";
			this->signUpButtonRegistration->UseVisualStyleBackColor = true;
			this->signUpButtonRegistration->Click += gcnew System::EventHandler(this, &SignUp::signUpButtonRegistration_Click);
			// 
			// signUpButtonSignIn
			// 
			this->signUpButtonSignIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->signUpButtonSignIn->Location = System::Drawing::Point(17, 255);
			this->signUpButtonSignIn->Name = L"signUpButtonSignIn";
			this->signUpButtonSignIn->Size = System::Drawing::Size(630, 33);
			this->signUpButtonSignIn->TabIndex = 9;
			this->signUpButtonSignIn->Text = L"У меня уже есть учетная запись";
			this->signUpButtonSignIn->UseVisualStyleBackColor = true;
			this->signUpButtonSignIn->Click += gcnew System::EventHandler(this, &SignUp::signUpButtonSignIn_Click);
			// 
			// signUpLabelPassword
			// 
			this->signUpLabelPassword->AutoSize = true;
			this->signUpLabelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpLabelPassword->Location = System::Drawing::Point(3, 61);
			this->signUpLabelPassword->Name = L"signUpLabelPassword";
			this->signUpLabelPassword->Size = System::Drawing::Size(95, 26);
			this->signUpLabelPassword->TabIndex = 11;
			this->signUpLabelPassword->Text = L"Пароль:";
			// 
			// signUpLabelLogin
			// 
			this->signUpLabelLogin->AutoSize = true;
			this->signUpLabelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpLabelLogin->Location = System::Drawing::Point(3, 12);
			this->signUpLabelLogin->Name = L"signUpLabelLogin";
			this->signUpLabelLogin->Size = System::Drawing::Size(78, 26);
			this->signUpLabelLogin->TabIndex = 10;
			this->signUpLabelLogin->Text = L"Логин:";
			// 
			// signUpPassword
			// 
			this->signUpPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signUpPassword->Location = System::Drawing::Point(117, 55);
			this->signUpPassword->Name = L"signUpPassword";
			this->signUpPassword->Size = System::Drawing::Size(208, 32);
			this->signUpPassword->TabIndex = 2;
			// 
			// signUpLogin
			// 
			this->signUpLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signUpLogin->Location = System::Drawing::Point(117, 6);
			this->signUpLogin->Name = L"signUpLogin";
			this->signUpLogin->Size = System::Drawing::Size(208, 32);
			this->signUpLogin->TabIndex = 1;
			// 
			// SignUpLabel
			// 
			this->SignUpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SignUpLabel->Location = System::Drawing::Point(17, 9);
			this->SignUpLabel->Name = L"SignUpLabel";
			this->SignUpLabel->Size = System::Drawing::Size(630, 31);
			this->SignUpLabel->TabIndex = 7;
			this->SignUpLabel->Text = L"Регистрация";
			this->SignUpLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelFirstName->Location = System::Drawing::Point(3, 9);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(62, 26);
			this->labelFirstName->TabIndex = 14;
			this->labelFirstName->Text = L"Имя:";
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelLastName->Location = System::Drawing::Point(4, 61);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(114, 26);
			this->labelLastName->TabIndex = 15;
			this->labelLastName->Text = L"Фамилия:";
			// 
			// labelCityName
			// 
			this->labelCityName->AutoSize = true;
			this->labelCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelCityName->Location = System::Drawing::Point(4, 113);
			this->labelCityName->Name = L"labelCityName";
			this->labelCityName->Size = System::Drawing::Size(79, 26);
			this->labelCityName->TabIndex = 16;
			this->labelCityName->Text = L"Город:";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBoxPasswordAgain);
			this->panel1->Controls->Add(this->labelPasswordAgain);
			this->panel1->Controls->Add(this->signUpLabelLogin);
			this->panel1->Controls->Add(this->signUpLogin);
			this->panel1->Controls->Add(this->signUpPassword);
			this->panel1->Controls->Add(this->signUpLabelPassword);
			this->panel1->Location = System::Drawing::Point(17, 43);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(335, 161);
			this->panel1->TabIndex = 18;
			// 
			// textBoxPasswordAgain
			// 
			this->textBoxPasswordAgain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxPasswordAgain->Location = System::Drawing::Point(8, 119);
			this->textBoxPasswordAgain->Name = L"textBoxPasswordAgain";
			this->textBoxPasswordAgain->Size = System::Drawing::Size(317, 32);
			this->textBoxPasswordAgain->TabIndex = 3;
			// 
			// labelPasswordAgain
			// 
			this->labelPasswordAgain->AutoSize = true;
			this->labelPasswordAgain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelPasswordAgain->Location = System::Drawing::Point(3, 90);
			this->labelPasswordAgain->Name = L"labelPasswordAgain";
			this->labelPasswordAgain->Size = System::Drawing::Size(205, 26);
			this->labelPasswordAgain->TabIndex = 12;
			this->labelPasswordAgain->Text = L"Повторить пароль:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->textBoxThemeName);
			this->panel2->Controls->Add(this->textBoxCityName);
			this->panel2->Controls->Add(this->textBoxLastName);
			this->panel2->Controls->Add(this->textBoxFirstName);
			this->panel2->Controls->Add(this->labelThemeName);
			this->panel2->Controls->Add(this->labelFirstName);
			this->panel2->Controls->Add(this->labelLastName);
			this->panel2->Controls->Add(this->labelCityName);
			this->panel2->Location = System::Drawing::Point(358, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(289, 206);
			this->panel2->TabIndex = 19;
			// 
			// textBoxThemeName
			// 
			this->textBoxThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxThemeName->Location = System::Drawing::Point(117, 160);
			this->textBoxThemeName->Name = L"textBoxThemeName";
			this->textBoxThemeName->Size = System::Drawing::Size(167, 32);
			this->textBoxThemeName->TabIndex = 7;
			// 
			// textBoxCityName
			// 
			this->textBoxCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxCityName->Location = System::Drawing::Point(117, 107);
			this->textBoxCityName->Name = L"textBoxCityName";
			this->textBoxCityName->Size = System::Drawing::Size(167, 32);
			this->textBoxCityName->TabIndex = 6;
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxLastName->Location = System::Drawing::Point(117, 55);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(167, 32);
			this->textBoxLastName->TabIndex = 5;
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxFirstName->Location = System::Drawing::Point(117, 6);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(167, 32);
			this->textBoxFirstName->TabIndex = 4;
			// 
			// labelThemeName
			// 
			this->labelThemeName->AutoSize = true;
			this->labelThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelThemeName->Location = System::Drawing::Point(4, 166);
			this->labelThemeName->Name = L"labelThemeName";
			this->labelThemeName->Size = System::Drawing::Size(70, 26);
			this->labelThemeName->TabIndex = 18;
			this->labelThemeName->Text = L"Тема:";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &SignUp::timer_Tick);
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 291);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->signUpButtonRegistration);
			this->Controls->Add(this->signUpButtonSignIn);
			this->Controls->Add(this->SignUpLabel);
			this->Name = L"SignUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SignUp";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region SIGN_UP_SECTION
private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = 0;
	Actions ActionID = action_create_account;
	int PacketID = 0;
	int PacketCountExpected = 0;

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	std::string login = getStringFromSystemString(this->signUpLogin->Text);
	std::string password = getStringFromSystemString(this->signUpPassword->Text);
	std::string firstName = getStringFromSystemString(this->textBoxFirstName->Text);
	std::string lastName = getStringFromSystemString(this->textBoxLastName->Text);
	std::string cityName = getStringFromSystemString(this->textBoxCityName->Text);
	std::string themeName = getStringFromSystemString(this->textBoxThemeName->Text);

	writeStringToMessage(mass, login, offset);
	writeStringToMessage(mass, password, offset);
	writeStringToMessage(mass, firstName, offset);
	writeStringToMessage(mass, lastName, offset);
	writeStringToMessage(mass, cityName, offset);
	writeStringToMessage(mass, themeName, offset);
}

private: System::Void signUpButtonRegistration_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (this->signUpPassword->Text != this->textBoxPasswordAgain->Text)
	{
		MessageBox::Show(
			"фыв",
			"Успех",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button1,
			MessageBoxOptions::DefaultDesktopOnly
		);

		return;
	}
	

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
	
	std::vector<char> q = ServerMessageQueue.front();
	ServerMessageQueue.erase(ServerMessageQueue.begin());

	printCharMass(q);
	DataFormat d;
	readHeader(q, d);
	offset = getHeaderSize();

	if (d.ActionID == action_create_account_response)
	{
		MessageBox::Show(
			"Аккаунт успешно создан",
			"Успех",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button1,
			MessageBoxOptions::DefaultDesktopOnly
		);

		state = SIGN_UP_STATE_SIGN_IN;
		this->Close();
	}
}
#pragma endregion SIGN_UP_SECTION

private: System::Void signUpButtonSignIn_Click(System::Object^  sender, System::EventArgs^  e) 
{
	state = SIGN_UP_STATE_SIGN_IN;
	this->Close();
}

//timer
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	UpdateSocket(_socket);
}
};
}
