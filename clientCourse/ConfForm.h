#pragma once

#include "Network.h"

#include "MessageManagerForm.h"
#include "MemberManagerForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ConfForm
	/// </summary>
	public ref class ConfForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	public: MemberManagerForm ^memberManagerForm;
	public: MessageManagerForm ^messageManagerForm;
	public: int confID;
	public: bool inEdit;
	public: int adminId;
	public: bool alreadyIn;
	private: System::Windows::Forms::Button^  buttonDelete;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::TextBox^  textBoxConfName;
	private: System::Windows::Forms::TextBox^  textBoxDates;
	private: System::Windows::Forms::TextBox^  textBoxCityName;
	private: System::Windows::Forms::TextBox^  textBoxThemeName;
	private: System::Windows::Forms::Button^  buttonLeave;
			 
	public:
		ConfForm(int accountType, int confID, int alreadyIn)//What conf should we create? ///FIXME
		{
			InitializeComponent();
			
			this->accountType = accountType;
			this->confID = confID;
			this->inEdit = false;
			this->alreadyIn = (alreadyIn == ALREADY_IN ? true : false);

			loadData();

			timer->Start();

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
			{
				this->buttonMessages->Show();
				this->buttonMembers->Show();
				this->buttonSettings->Show();
				this->buttonLeave->Hide();
				this->buttonDelete->Show();

				int size = 182;
				int offset = 5;
				this->buttonMessages->Location = System::Drawing::Point(3 + (size + offset) * 0, 435);
				this->buttonMessages->Size = System::Drawing::Size(size, 29);

				this->buttonMembers->Location = System::Drawing::Point(3 + (size + offset) * 1, 435);
				this->buttonMembers->Size = System::Drawing::Size(size, 29);

				this->buttonSettings->Location = System::Drawing::Point(3 + (size + offset) * 2, 435);
				this->buttonSettings->Size = System::Drawing::Size(size, 29);

				this->buttonDelete->Location = System::Drawing::Point(3 + (size + offset) * 3, 435);
				this->buttonDelete->Size = System::Drawing::Size(size, 29);
			}
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
			{
				this->buttonMessages->Hide();
				this->buttonMembers->Show();
				this->buttonSettings->Hide();
				this->buttonLeave->Show();
				this->buttonDelete->Hide();

				int size = 371;
				int offset = 6;
				
				this->buttonMembers->Location = System::Drawing::Point(3 + (size + offset) * 0, 435);
				this->buttonMembers->Size = System::Drawing::Size(size, 29);

				this->buttonLeave->Location = System::Drawing::Point(3 + (size + offset) * 1, 435);
				this->buttonLeave->Size = System::Drawing::Size(size, 29);

				if (!this->alreadyIn)
					buttonLeave->Text = L"Вступить";
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ConfForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::Button^  buttonMembers;
	private: System::Windows::Forms::Button^  buttonMessages;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonLeave = (gcnew System::Windows::Forms::Button());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->buttonMembers = (gcnew System::Windows::Forms::Button());
			this->buttonMessages = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBoxConfName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDates = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCityName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxThemeName = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->buttonDelete);
			this->panel1->Controls->Add(this->buttonLeave);
			this->panel1->Controls->Add(this->buttonSettings);
			this->panel1->Controls->Add(this->buttonMembers);
			this->panel1->Controls->Add(this->buttonMessages);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Location = System::Drawing::Point(12, 70);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(760, 479);
			this->panel1->TabIndex = 3;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonDelete->Location = System::Drawing::Point(546, 435);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(122, 37);
			this->buttonDelete->TabIndex = 5;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &ConfForm::buttonDelete_Click);
			// 
			// buttonLeave
			// 
			this->buttonLeave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonLeave->Location = System::Drawing::Point(418, 435);
			this->buttonLeave->Name = L"buttonLeave";
			this->buttonLeave->Size = System::Drawing::Size(122, 37);
			this->buttonLeave->TabIndex = 4;
			this->buttonLeave->Text = L"Покинуть";
			this->buttonLeave->UseVisualStyleBackColor = true;
			this->buttonLeave->Click += gcnew System::EventHandler(this, &ConfForm::buttonLeave_Click);
			// 
			// buttonSettings
			// 
			this->buttonSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonSettings->Location = System::Drawing::Point(273, 435);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(139, 37);
			this->buttonSettings->TabIndex = 3;
			this->buttonSettings->Text = L"Настройки";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &ConfForm::buttonSettings_Click);
			// 
			// buttonMembers
			// 
			this->buttonMembers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonMembers->Location = System::Drawing::Point(135, 435);
			this->buttonMembers->Name = L"buttonMembers";
			this->buttonMembers->Size = System::Drawing::Size(132, 37);
			this->buttonMembers->TabIndex = 2;
			this->buttonMembers->Text = L"Участники";
			this->buttonMembers->UseVisualStyleBackColor = true;
			this->buttonMembers->Click += gcnew System::EventHandler(this, &ConfForm::buttonMembers_Click);
			// 
			// buttonMessages
			// 
			this->buttonMessages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonMessages->Location = System::Drawing::Point(3, 435);
			this->buttonMessages->Name = L"buttonMessages";
			this->buttonMessages->Size = System::Drawing::Size(126, 37);
			this->buttonMessages->TabIndex = 1;
			this->buttonMessages->Text = L"Сообщения";
			this->buttonMessages->UseVisualStyleBackColor = true;
			this->buttonMessages->Click += gcnew System::EventHandler(this, &ConfForm::buttonMessages_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(750, 426);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"Информация о конференции";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &ConfForm::timer_Tick);
			// 
			// textBoxConfName
			// 
			this->textBoxConfName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxConfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxConfName->Location = System::Drawing::Point(12, 6);
			this->textBoxConfName->MaximumSize = System::Drawing::Size(755, 29);
			this->textBoxConfName->MinimumSize = System::Drawing::Size(226, 29);
			this->textBoxConfName->Name = L"textBoxConfName";
			this->textBoxConfName->ReadOnly = true;
			this->textBoxConfName->Size = System::Drawing::Size(755, 29);
			this->textBoxConfName->TabIndex = 5;
			this->textBoxConfName->Text = L"Название конференции";
			// 
			// textBoxDates
			// 
			this->textBoxDates->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxDates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxDates->Location = System::Drawing::Point(12, 35);
			this->textBoxDates->MaximumSize = System::Drawing::Size(220, 29);
			this->textBoxDates->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxDates->Name = L"textBoxDates";
			this->textBoxDates->ReadOnly = true;
			this->textBoxDates->Size = System::Drawing::Size(220, 29);
			this->textBoxDates->TabIndex = 6;
			this->textBoxDates->Text = L"Даты проведения";
			// 
			// textBoxCityName
			// 
			this->textBoxCityName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxCityName->Location = System::Drawing::Point(238, 35);
			this->textBoxCityName->MaximumSize = System::Drawing::Size(120, 29);
			this->textBoxCityName->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxCityName->Name = L"textBoxCityName";
			this->textBoxCityName->ReadOnly = true;
			this->textBoxCityName->Size = System::Drawing::Size(120, 29);
			this->textBoxCityName->TabIndex = 7;
			this->textBoxCityName->Text = L"Город";
			// 
			// textBoxThemeName
			// 
			this->textBoxThemeName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxThemeName->Location = System::Drawing::Point(364, 35);
			this->textBoxThemeName->MaximumSize = System::Drawing::Size(403, 29);
			this->textBoxThemeName->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxThemeName->Name = L"textBoxThemeName";
			this->textBoxThemeName->ReadOnly = true;
			this->textBoxThemeName->Size = System::Drawing::Size(403, 29);
			this->textBoxThemeName->TabIndex = 8;
			this->textBoxThemeName->Text = L"Тематика";
			// 
			// ConfForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->textBoxThemeName);
			this->Controls->Add(this->textBoxCityName);
			this->Controls->Add(this->textBoxDates);
			this->Controls->Add(this->textBoxConfName);
			this->Controls->Add(this->panel1);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ConfForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConfForm";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_conf_full_info;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	//int confID = 900;//error
	int confID = this->confID;

	offset = getHeaderSize();
	writeIntToMessage(mass, confID, offset);
}

private: void loadData()
{
	int offset = 0;

	std::vector<char> mass;

	createMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}

//Сообщения
private: System::Void buttonMessages_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->timer->Stop();
	messageManagerForm = gcnew MessageManagerForm(accountType);

	this->Hide();
	messageManagerForm->ShowDialog();
	this->Show();
	this->Activate();

	delete messageManagerForm;
	this->timer->Start();
}

private: void createSettingsMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_update_conf_info;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	int count = 1;
	int id = this->confID;;
	std::string name = getStringFromSystemString(this->textBoxConfName->Text);
	std::string date = getStringFromSystemString(this->textBoxDates->Text);
	int themeId = -1;
	int cityId = -1;
	std::string description = getStringFromSystemString(this->richTextBox1->Text);
	int admin = this->adminId;
	std::string cityName = getStringFromSystemString(this->textBoxCityName->Text);
	std::string themeName = getStringFromSystemString(this->textBoxThemeName->Text);

	int newSize = offset + 5 * sizeof(int) + name.size() + date.size() + description.size() + cityName.size() + themeName.size();
	mass.resize(200 + newSize);

	writeIntToMessage(mass, count, offset);
	for (int i(0); i < count; i++)//count = 1
	{
		writeIntToMessage(mass, id, offset);
		writeStringToMessage(mass, name, offset);
		writeStringToMessage(mass, date, offset);
		writeIntToMessage(mass, themeId, offset);
		writeIntToMessage(mass, cityId, offset);
		writeStringToMessage(mass, description, offset);
		writeIntToMessage(mass, admin, offset);
		writeStringToMessage(mass, cityName, offset);
		writeStringToMessage(mass, themeName, offset);
	}
}

//Участники
private: System::Void buttonMembers_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->timer->Stop();
	memberManagerForm = gcnew MemberManagerForm(accountType, confID);

	this->Hide();
	memberManagerForm->ShowDialog();
	this->Show();
	this->Activate();

	delete memberManagerForm;
	this->timer->Start();
}

//Настройки
private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!inEdit)
	{
		inEdit = true;
		this->textBoxConfName->ReadOnly = false;
		this->textBoxDates->ReadOnly = false;
		this->textBoxCityName->ReadOnly = false;
		this->textBoxThemeName->ReadOnly = false;

		this->richTextBox1->ReadOnly = false;

		this->buttonSettings->Text = L"Сохранить";
	}
	else
	{
		this->textBoxConfName->ReadOnly = true;
		this->textBoxDates->ReadOnly = true;
		this->textBoxCityName->ReadOnly = true;
		this->textBoxThemeName->ReadOnly = true;

		this->richTextBox1->ReadOnly = true;

		this->buttonSettings->Text = L"Наcтройки";

		std::vector<char> mass;
		int offset = 0;
		createSettingsMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);
		inEdit = false;
	}
}

private: void createLeaveMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_leave_conf;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
	
	int confID = this->confID;

	writeIntToMessage(mass, confID, offset);
}

private: void createJoinMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_join_conf;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	int confID = this->confID;

	writeIntToMessage(mass, confID, offset);
}

//Покинуть
private: System::Void buttonLeave_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (this->alreadyIn)
	{
		if (MessageBox::Show(
			"Вы уверены?",
			"Вопрос",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2,
			MessageBoxOptions::DefaultDesktopOnly
		) == System::Windows::Forms::DialogResult::No)
			return;

		std::vector<char> mass;
		int offset = 0;

		createLeaveMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);
	}
	else
	{
		if (MessageBox::Show(
			"Вы уверены?",
			"Вопрос",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2,
			MessageBoxOptions::DefaultDesktopOnly
		) == System::Windows::Forms::DialogResult::No)
			return;

		std::vector<char> mass;
		int offset = 0;

		createJoinMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);
	}
}

private: void createDeleteMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_delete_conf;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	int confID = this->confID;

	writeIntToMessage(mass, confID, offset);
}

//Удалить
private: System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//std::vector<char> mass;
	//int offset = 0;

	//createDeleteMessage(mass, offset);
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

		if (d.ActionID == action_error)///FIXME
		{
			MessageBox::Show(
				"Указанная конференция не существует",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Close();

			return;
		}

		if (d.ActionID == action_update_conf_info_response)
		{
			MessageBox::Show(
				"Значения успешно изменены",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
			return;
		}

		if (d.ActionID == action_leave_conf_response)
		{
			MessageBox::Show(
				"Конференция успешно покинута",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
			return;
		}

		if (d.ActionID == action_conf_full_info_response)
		{
			int count;//=1
			readIntFromMessage(q, count, offset);
			for (int i(0); i < count; i++)
			{
				int id;
				std::string name;
				std::string date;
				int themeId;
				int cityId;
				std::string description;
				int admin;
				std::string cityName;
				std::string themeName;

				readIntFromMessage(q, id, offset);
				readStringFromMessage(q, name, offset);
				readStringFromMessage(q, date, offset);
				readIntFromMessage(q, themeId, offset);
				readIntFromMessage(q, cityId, offset);
				readStringFromMessage(q, description, offset);
				readIntFromMessage(q, admin, offset);
				readStringFromMessage(q, cityName, offset);
				readStringFromMessage(q, themeName, offset);

				this->textBoxConfName->Text = gcnew System::String(name.c_str());
				this->textBoxDates->Text = gcnew System::String(date.c_str());
				this->textBoxCityName->Text = gcnew System::String(cityName.c_str());
				this->textBoxThemeName->Text = gcnew System::String(themeName.c_str());

				this->richTextBox1->Text = gcnew System::String(description.c_str());

				this->adminId = admin;
			}
		}

		if (d.ActionID == action_delete_conf_response)
		{
			MessageBox::Show(
				"Конференция успешно покинута",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Close();
		}

		if (d.ActionID == action_join_conf_response)
		{
			MessageBox::Show(
				"Вы были добавлены на конференцию",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
		}
	}
}
};
}
