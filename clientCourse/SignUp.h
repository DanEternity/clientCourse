#pragma once

#include "MainHeader.h"

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
	public:

		int state;
		int type;

		SignUp(void)
		{
			InitializeComponent();

			state = SIGN_UP_STATE_NONE;
			//
			//TODO: добавьте код конструктора
			//
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
	protected:

	protected:

	private: System::Windows::Forms::Label^  signUpLabelPassword;
	private: System::Windows::Forms::Label^  signUpLabelLogin;


	private: System::Windows::Forms::TextBox^  signUpPassword;

	private: System::Windows::Forms::TextBox^  signUpLogin;

	private: System::Windows::Forms::Label^  SignUpLabel;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->signUpButtonRegistration = (gcnew System::Windows::Forms::Button());
			this->signUpButtonSignIn = (gcnew System::Windows::Forms::Button());
			this->signUpLabelPassword = (gcnew System::Windows::Forms::Label());
			this->signUpLabelLogin = (gcnew System::Windows::Forms::Label());
			this->signUpPassword = (gcnew System::Windows::Forms::TextBox());
			this->signUpLogin = (gcnew System::Windows::Forms::TextBox());
			this->SignUpLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// signUpButtonRegistration
			// 
			this->signUpButtonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpButtonRegistration->Location = System::Drawing::Point(17, 153);
			this->signUpButtonRegistration->Name = L"signUpButtonRegistration";
			this->signUpButtonRegistration->Size = System::Drawing::Size(317, 39);
			this->signUpButtonRegistration->TabIndex = 13;
			this->signUpButtonRegistration->Text = L"Зарегистрироваться";
			this->signUpButtonRegistration->UseVisualStyleBackColor = true;
			this->signUpButtonRegistration->Click += gcnew System::EventHandler(this, &SignUp::signUpButtonRegistration_Click);
			// 
			// signUpButtonSignIn
			// 
			this->signUpButtonSignIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->signUpButtonSignIn->Location = System::Drawing::Point(17, 198);
			this->signUpButtonSignIn->Name = L"signUpButtonSignIn";
			this->signUpButtonSignIn->Size = System::Drawing::Size(317, 27);
			this->signUpButtonSignIn->TabIndex = 12;
			this->signUpButtonSignIn->Text = L"У меня уже есть учетная запись";
			this->signUpButtonSignIn->UseVisualStyleBackColor = true;
			this->signUpButtonSignIn->Click += gcnew System::EventHandler(this, &SignUp::signUpButtonSignIn_Click);
			// 
			// signUpLabelPassword
			// 
			this->signUpLabelPassword->AutoSize = true;
			this->signUpLabelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpLabelPassword->Location = System::Drawing::Point(12, 101);
			this->signUpLabelPassword->Name = L"signUpLabelPassword";
			this->signUpLabelPassword->Size = System::Drawing::Size(95, 26);
			this->signUpLabelPassword->TabIndex = 11;
			this->signUpLabelPassword->Text = L"Пароль:";
			// 
			// signUpLabelLogin
			// 
			this->signUpLabelLogin->AutoSize = true;
			this->signUpLabelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->signUpLabelLogin->Location = System::Drawing::Point(12, 62);
			this->signUpLabelLogin->Name = L"signUpLabelLogin";
			this->signUpLabelLogin->Size = System::Drawing::Size(78, 26);
			this->signUpLabelLogin->TabIndex = 10;
			this->signUpLabelLogin->Text = L"Логин:";
			// 
			// signUpPassword
			// 
			this->signUpPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signUpPassword->Location = System::Drawing::Point(126, 101);
			this->signUpPassword->Name = L"signUpPassword";
			this->signUpPassword->Size = System::Drawing::Size(208, 32);
			this->signUpPassword->TabIndex = 9;
			// 
			// signUpLogin
			// 
			this->signUpLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signUpLogin->Location = System::Drawing::Point(126, 59);
			this->signUpLogin->Name = L"signUpLogin";
			this->signUpLogin->Size = System::Drawing::Size(208, 32);
			this->signUpLogin->TabIndex = 8;
			// 
			// SignUpLabel
			// 
			this->SignUpLabel->AutoSize = true;
			this->SignUpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SignUpLabel->Location = System::Drawing::Point(92, 9);
			this->SignUpLabel->Name = L"SignUpLabel";
			this->SignUpLabel->Size = System::Drawing::Size(174, 31);
			this->SignUpLabel->TabIndex = 7;
			this->SignUpLabel->Text = L"Регистрация";
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(346, 239);
			this->Controls->Add(this->signUpButtonRegistration);
			this->Controls->Add(this->signUpButtonSignIn);
			this->Controls->Add(this->signUpLabelPassword);
			this->Controls->Add(this->signUpLabelLogin);
			this->Controls->Add(this->signUpPassword);
			this->Controls->Add(this->signUpLogin);
			this->Controls->Add(this->SignUpLabel);
			this->Name = L"SignUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SignUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void signUpButtonRegistration_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//Запрос на добавление учетной записи

	//Тип учетной записи

	type = ACCOUNT_TYPE_SCIENTIST;
	state = SIGN_UP_STATE_ACCESS;
	this->Close();
}

private: System::Void signUpButtonSignIn_Click(System::Object^  sender, System::EventArgs^  e) 
{
	state = SIGN_UP_STATE_SIGN_IN;
	this->Close();
}

};
}
