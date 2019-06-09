#pragma once

#include "Network.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ProfileForm
	/// </summary>
	public ref class ProfileForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	public: ProfileForm(int accountType)
		{
			InitializeComponent();

			this->accountType = accountType;

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
			{
				this->labelFirstName->Visible = false;
				this->labelLastName->Visible = false;
				this->labelCityName->Visible = false;
				this->labelThemeName->Visible = false;

				this->textBoxCity->Visible = false;
				this->textBoxFirstName->Visible = false;
				this->textBoxLastName->Visible = false;
				this->textBoxThemeName->Visible = false;

				this->labelAccountType->Text = L"Администратор";

				this->buttonAddCityName->Visible = true;
				this->buttonAddThemeName->Visible = true;

				loadData();
			}
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
			{
				this->labelAccountType->Text = L"Ученый";

				this->buttonAddCityName->Visible = false;
				this->buttonAddThemeName->Visible = false;
				this->textBoxAddCityName->Visible = false;
				this->textBoxAddThemeName->Visible = false;

				loadData();
			}

			timer->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ProfileForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  labelAccountType;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  labelCityName;
	private: System::Windows::Forms::TextBox^  textBoxThemeName;
	private: System::Windows::Forms::Label^  labelThemeName;
	private: System::Windows::Forms::TextBox^  textBoxLastName;
	private: System::Windows::Forms::Label^  labelLastName;
	private: System::Windows::Forms::TextBox^  textBoxCity;
	private: System::Windows::Forms::Button^  buttonDeleteAccount;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::TextBox^  textBoxLogin;
	private: System::Windows::Forms::Label^  labelLogin;
	private: System::Windows::Forms::Button^  buttonAddThemeName;
	private: System::Windows::Forms::Button^  buttonAddCityName;
	private: System::Windows::Forms::TextBox^  textBoxAddCityName;
	private: System::Windows::Forms::TextBox^  textBoxAddThemeName;
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
			this->labelAccountType = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonAddThemeName = (gcnew System::Windows::Forms::Button());
			this->buttonAddCityName = (gcnew System::Windows::Forms::Button());
			this->textBoxAddCityName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddThemeName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->textBoxCity = (gcnew System::Windows::Forms::TextBox());
			this->labelCityName = (gcnew System::Windows::Forms::Label());
			this->textBoxThemeName = (gcnew System::Windows::Forms::TextBox());
			this->labelThemeName = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteAccount = (gcnew System::Windows::Forms::Button());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelAccountType
			// 
			this->labelAccountType->AutoSize = true;
			this->labelAccountType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelAccountType->Location = System::Drawing::Point(8, 9);
			this->labelAccountType->Name = L"labelAccountType";
			this->labelAccountType->Size = System::Drawing::Size(190, 24);
			this->labelAccountType->TabIndex = 2;
			this->labelAccountType->Text = L"Тип учетной записи";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxFirstName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxFirstName->Location = System::Drawing::Point(123, 9);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->ReadOnly = true;
			this->textBoxFirstName->Size = System::Drawing::Size(100, 29);
			this->textBoxFirstName->TabIndex = 3;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelFirstName->Location = System::Drawing::Point(3, 9);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(51, 24);
			this->labelFirstName->TabIndex = 4;
			this->labelFirstName->Text = L"Имя:";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->buttonAddThemeName);
			this->panel1->Controls->Add(this->buttonAddCityName);
			this->panel1->Controls->Add(this->textBoxAddCityName);
			this->panel1->Controls->Add(this->textBoxAddThemeName);
			this->panel1->Controls->Add(this->textBoxLogin);
			this->panel1->Controls->Add(this->labelLogin);
			this->panel1->Controls->Add(this->textBoxCity);
			this->panel1->Controls->Add(this->labelCityName);
			this->panel1->Controls->Add(this->textBoxThemeName);
			this->panel1->Controls->Add(this->labelThemeName);
			this->panel1->Controls->Add(this->textBoxLastName);
			this->panel1->Controls->Add(this->labelLastName);
			this->panel1->Controls->Add(this->textBoxFirstName);
			this->panel1->Controls->Add(this->labelFirstName);
			this->panel1->Location = System::Drawing::Point(12, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(760, 469);
			this->panel1->TabIndex = 5;
			// 
			// buttonAddThemeName
			// 
			this->buttonAddThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonAddThemeName->Location = System::Drawing::Point(460, 53);
			this->buttonAddThemeName->Name = L"buttonAddThemeName";
			this->buttonAddThemeName->Size = System::Drawing::Size(293, 36);
			this->buttonAddThemeName->TabIndex = 17;
			this->buttonAddThemeName->Text = L"Добавить название тематики";
			this->buttonAddThemeName->UseVisualStyleBackColor = true;
			this->buttonAddThemeName->Click += gcnew System::EventHandler(this, &ProfileForm::buttonAddThemeName_Click);
			// 
			// buttonAddCityName
			// 
			this->buttonAddCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonAddCityName->Location = System::Drawing::Point(460, 117);
			this->buttonAddCityName->Name = L"buttonAddCityName";
			this->buttonAddCityName->Size = System::Drawing::Size(293, 36);
			this->buttonAddCityName->TabIndex = 8;
			this->buttonAddCityName->Text = L"Добавить название города";
			this->buttonAddCityName->UseVisualStyleBackColor = true;
			this->buttonAddCityName->Click += gcnew System::EventHandler(this, &ProfileForm::buttonAddCityName_Click);
			// 
			// textBoxAddCityName
			// 
			this->textBoxAddCityName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxAddCityName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxAddCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxAddCityName->Location = System::Drawing::Point(229, 124);
			this->textBoxAddCityName->Name = L"textBoxAddCityName";
			this->textBoxAddCityName->Size = System::Drawing::Size(212, 29);
			this->textBoxAddCityName->TabIndex = 16;
			// 
			// textBoxAddThemeName
			// 
			this->textBoxAddThemeName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxAddThemeName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxAddThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxAddThemeName->Location = System::Drawing::Point(229, 57);
			this->textBoxAddThemeName->Name = L"textBoxAddThemeName";
			this->textBoxAddThemeName->Size = System::Drawing::Size(212, 29);
			this->textBoxAddThemeName->TabIndex = 15;
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxLogin->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxLogin->Location = System::Drawing::Point(474, 7);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->ReadOnly = true;
			this->textBoxLogin->Size = System::Drawing::Size(100, 29);
			this->textBoxLogin->TabIndex = 12;
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelLogin->Location = System::Drawing::Point(335, 9);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(133, 24);
			this->labelLogin->TabIndex = 11;
			this->labelLogin->Text = L"Вы зашли как:";
			// 
			// textBoxCity
			// 
			this->textBoxCity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCity->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxCity->Location = System::Drawing::Point(123, 105);
			this->textBoxCity->Name = L"textBoxCity";
			this->textBoxCity->ReadOnly = true;
			this->textBoxCity->Size = System::Drawing::Size(100, 29);
			this->textBoxCity->TabIndex = 10;
			// 
			// labelCityName
			// 
			this->labelCityName->AutoSize = true;
			this->labelCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelCityName->Location = System::Drawing::Point(3, 105);
			this->labelCityName->Name = L"labelCityName";
			this->labelCityName->Size = System::Drawing::Size(71, 24);
			this->labelCityName->TabIndex = 9;
			this->labelCityName->Text = L"Город:";
			// 
			// textBoxThemeName
			// 
			this->textBoxThemeName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxThemeName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxThemeName->Location = System::Drawing::Point(123, 153);
			this->textBoxThemeName->Name = L"textBoxThemeName";
			this->textBoxThemeName->ReadOnly = true;
			this->textBoxThemeName->Size = System::Drawing::Size(100, 29);
			this->textBoxThemeName->TabIndex = 8;
			// 
			// labelThemeName
			// 
			this->labelThemeName->AutoSize = true;
			this->labelThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelThemeName->Location = System::Drawing::Point(3, 153);
			this->labelThemeName->Name = L"labelThemeName";
			this->labelThemeName->Size = System::Drawing::Size(101, 24);
			this->labelThemeName->TabIndex = 7;
			this->labelThemeName->Text = L"Тематика:";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxLastName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxLastName->Location = System::Drawing::Point(123, 57);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->ReadOnly = true;
			this->textBoxLastName->Size = System::Drawing::Size(100, 29);
			this->textBoxLastName->TabIndex = 6;
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelLastName->Location = System::Drawing::Point(3, 57);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(96, 24);
			this->labelLastName->TabIndex = 5;
			this->labelLastName->Text = L"Фамилия:";
			// 
			// buttonDeleteAccount
			// 
			this->buttonDeleteAccount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonDeleteAccount->Location = System::Drawing::Point(412, 511);
			this->buttonDeleteAccount->Name = L"buttonDeleteAccount";
			this->buttonDeleteAccount->Size = System::Drawing::Size(360, 38);
			this->buttonDeleteAccount->TabIndex = 6;
			this->buttonDeleteAccount->Text = L"Удалить аккаунт";
			this->buttonDeleteAccount->UseVisualStyleBackColor = true;
			this->buttonDeleteAccount->Click += gcnew System::EventHandler(this, &ProfileForm::buttonDeleteAccount_Click);
			// 
			// buttonSettings
			// 
			this->buttonSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonSettings->Location = System::Drawing::Point(12, 511);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(360, 38);
			this->buttonSettings->TabIndex = 7;
			this->buttonSettings->Text = L"Настройки";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &ProfileForm::buttonSettings_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &ProfileForm::timer_Tick);
			// 
			// ProfileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->buttonSettings);
			this->Controls->Add(this->buttonDeleteAccount);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelAccountType);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ProfileForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ProfileForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region INIT_SECTION
void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_get_profile;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
}

void loadData()
{
	int offset = 0;

	std::vector<char> mass;

	createMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}

#pragma endregion INIT_SECTION

#pragma region ADD_THEME_SECTION
private: void createMessageAddTheme(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_add_theme;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	std::string themeName = getStringFromSystemString(this->textBoxAddThemeName->Text);

	writeStringToMessage(mass, themeName, offset);
}

private: System::Void buttonAddThemeName_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::vector<char> mass;
	int offset = 0;
	createMessageAddTheme(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}
#pragma endregion ADD_THEME_SECTION

#pragma region ADD_CITY_SECTION
private: void createMessageAddCity(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_add_city;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	std::string cityName = getStringFromSystemString(this->textBoxAddCityName->Text);

	writeStringToMessage(mass, cityName, offset);
}

private: System::Void buttonAddCityName_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::vector<char> mass;
	int offset = 0;
	createMessageAddCity(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}
#pragma endregion ADD_CITY_SECTION
//settings
private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) 
{

}

//delete account
private: System::Void buttonDeleteAccount_Click(System::Object^  sender, System::EventArgs^  e) 
{

}

//timer
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if (!ServerMessageQueue.empty())
	{
		std::vector<char> q = ServerMessageQueue.front();
		ServerMessageQueue.erase(ServerMessageQueue.begin());

		printCharMass(q);
		DataFormat d;
		readHeader(q, d);
		int offset = getHeaderSize();

		if (d.ActionID == action_add_city_response)
		{
			MessageBox::Show(
				"Название города успешно добавлено",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
		}

		if (d.ActionID == action_add_theme_response)
		{
			MessageBox::Show(
				"Название тематики успешно добавлено",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
		}

		if (d.ActionID == action_get_profile_response)
		{
			if (this->accountType == ACCOUNT_TYPE_ADMINISTRATOR)
			{
				std::string login;

				readStringFromMessage(q, login, offset);

				this->textBoxLogin->Text = gcnew System::String(login.c_str());
			}
			else if (this->accountType == ACCOUNT_TYPE_SCIENTIST)
			{
				std::string login;
				std::string firstName;
				std::string lastName;
				std::string themeName;
				std::string cityName;

				readStringFromMessage(q, login, offset);
				readStringFromMessage(q, firstName, offset);
				readStringFromMessage(q, lastName, offset);
				readStringFromMessage(q, themeName, offset);
				readStringFromMessage(q, cityName, offset);

				this->textBoxLogin->Text = gcnew System::String(login.c_str());
				this->textBoxFirstName->Text = gcnew System::String(firstName.c_str());
				this->textBoxLastName->Text = gcnew System::String(lastName.c_str());
				this->textBoxThemeName->Text = gcnew System::String(themeName.c_str());
				this->textBoxCity->Text = gcnew System::String(cityName.c_str());
			}
		}
	}
}
};
}
