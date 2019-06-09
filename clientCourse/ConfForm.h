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
	/// ������ ��� ConfForm
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
	public: int returnState;
	private: System::Windows::Forms::Button^  buttonDelete;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::TextBox^  textBoxConfName;
	private: System::Windows::Forms::TextBox^  textBoxDates;
	private: System::Windows::Forms::TextBox^  textBoxCityName;
	private: System::Windows::Forms::TextBox^  textBoxThemeName;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonLeave;
			 
	public:
		ConfForm(int accountType, int confID, int alreadyIn)//What conf should we create? ///FIXME
		{
			InitializeComponent();
			
			this->accountType = accountType;
			this->confID = confID;
			this->inEdit = false;
			this->alreadyIn = (alreadyIn == ALREADY_IN ? true : false);
			this->returnState = RETURN_STATE_NONE;
			loadData();
			
			timer->Start();

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
			{
				this->buttonMessages->Show();
				this->buttonMembers->Show();
				this->buttonSettings->Show();
				this->buttonLeave->Hide();
				this->buttonDelete->Show();

				int size = 185;
				int offset = 6;
				this->buttonMessages->Location = System::Drawing::Point(10 + (size + offset) * 0, 512);
				this->buttonMessages->Size = System::Drawing::Size(size, 29);

				this->buttonMembers->Location = System::Drawing::Point(10 + (size + offset) * 1, 512);
				this->buttonMembers->Size = System::Drawing::Size(size, 29);

				this->buttonSettings->Location = System::Drawing::Point(10 + (size + offset) * 2, 512);
				this->buttonSettings->Size = System::Drawing::Size(size, 29);

				this->buttonDelete->Location = System::Drawing::Point(10 + (size + offset) * 3, 512);
				this->buttonDelete->Size = System::Drawing::Size(size, 29);
			}
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
			{
				this->buttonMessages->Hide();
				this->buttonMembers->Show();
				this->buttonSettings->Hide();
				this->buttonLeave->Show();
				this->buttonDelete->Hide();

				int size = 376;
				int offset = 6;
				
				this->buttonMembers->Location = System::Drawing::Point(10 + (size + offset) * 0, 512);
				this->buttonMembers->Size = System::Drawing::Size(size, 29);

				this->buttonLeave->Location = System::Drawing::Point(10 + (size + offset) * 1, 512);
				this->buttonLeave->Size = System::Drawing::Size(size, 29);

				if (!this->alreadyIn)
					buttonLeave->Text = L"��������";
			}
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ConfForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::Button^  buttonMembers;
	private: System::Windows::Forms::Button^  buttonMessages;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonDelete->Location = System::Drawing::Point(648, 512);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(122, 37);
			this->buttonDelete->TabIndex = 5;
			this->buttonDelete->Text = L"�������";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &ConfForm::buttonDelete_Click);
			// 
			// buttonLeave
			// 
			this->buttonLeave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonLeave->Location = System::Drawing::Point(445, 512);
			this->buttonLeave->Name = L"buttonLeave";
			this->buttonLeave->Size = System::Drawing::Size(122, 37);
			this->buttonLeave->TabIndex = 4;
			this->buttonLeave->Text = L"��������";
			this->buttonLeave->UseVisualStyleBackColor = true;
			this->buttonLeave->Click += gcnew System::EventHandler(this, &ConfForm::buttonLeave_Click);
			// 
			// buttonSettings
			// 
			this->buttonSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonSettings->Location = System::Drawing::Point(300, 512);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(139, 37);
			this->buttonSettings->TabIndex = 3;
			this->buttonSettings->Text = L"���������";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &ConfForm::buttonSettings_Click);
			// 
			// buttonMembers
			// 
			this->buttonMembers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonMembers->Location = System::Drawing::Point(162, 512);
			this->buttonMembers->Name = L"buttonMembers";
			this->buttonMembers->Size = System::Drawing::Size(132, 37);
			this->buttonMembers->TabIndex = 2;
			this->buttonMembers->Text = L"���������";
			this->buttonMembers->UseVisualStyleBackColor = true;
			this->buttonMembers->Click += gcnew System::EventHandler(this, &ConfForm::buttonMembers_Click);
			// 
			// buttonMessages
			// 
			this->buttonMessages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonMessages->Location = System::Drawing::Point(10, 512);
			this->buttonMessages->Name = L"buttonMessages";
			this->buttonMessages->Size = System::Drawing::Size(126, 37);
			this->buttonMessages->TabIndex = 1;
			this->buttonMessages->Text = L"���������";
			this->buttonMessages->UseVisualStyleBackColor = true;
			this->buttonMessages->Click += gcnew System::EventHandler(this, &ConfForm::buttonMessages_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->richTextBox1->Location = System::Drawing::Point(10, 203);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(760, 303);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"���������� � �����������";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &ConfForm::timer_Tick);
			// 
			// textBoxConfName
			// 
			this->textBoxConfName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxConfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxConfName->Location = System::Drawing::Point(233, 6);
			this->textBoxConfName->MaximumSize = System::Drawing::Size(524, 29);
			this->textBoxConfName->MinimumSize = System::Drawing::Size(226, 29);
			this->textBoxConfName->Name = L"textBoxConfName";
			this->textBoxConfName->ReadOnly = true;
			this->textBoxConfName->Size = System::Drawing::Size(524, 22);
			this->textBoxConfName->TabIndex = 5;
			this->textBoxConfName->Text = L"�������� �����������";
			// 
			// textBoxDates
			// 
			this->textBoxDates->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxDates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxDates->Location = System::Drawing::Point(233, 41);
			this->textBoxDates->MaximumSize = System::Drawing::Size(524, 29);
			this->textBoxDates->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxDates->Name = L"textBoxDates";
			this->textBoxDates->ReadOnly = true;
			this->textBoxDates->Size = System::Drawing::Size(524, 22);
			this->textBoxDates->TabIndex = 6;
			this->textBoxDates->Text = L"���� ����������";
			// 
			// textBoxCityName
			// 
			this->textBoxCityName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxCityName->Location = System::Drawing::Point(233, 76);
			this->textBoxCityName->MaximumSize = System::Drawing::Size(524, 29);
			this->textBoxCityName->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxCityName->Name = L"textBoxCityName";
			this->textBoxCityName->ReadOnly = true;
			this->textBoxCityName->Size = System::Drawing::Size(524, 22);
			this->textBoxCityName->TabIndex = 7;
			this->textBoxCityName->Text = L"�����";
			// 
			// textBoxThemeName
			// 
			this->textBoxThemeName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxThemeName->Location = System::Drawing::Point(233, 111);
			this->textBoxThemeName->MaximumSize = System::Drawing::Size(524, 29);
			this->textBoxThemeName->MinimumSize = System::Drawing::Size(0, 29);
			this->textBoxThemeName->Name = L"textBoxThemeName";
			this->textBoxThemeName->ReadOnly = true;
			this->textBoxThemeName->Size = System::Drawing::Size(524, 22);
			this->textBoxThemeName->TabIndex = 8;
			this->textBoxThemeName->Text = L"��������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(3, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"�������� �����������:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(3, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(177, 24);
			this->label2->TabIndex = 10;
			this->label2->Text = L"���� ����������:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(3, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 24);
			this->label3->TabIndex = 11;
			this->label3->Text = L"�����:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(3, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 24);
			this->label4->TabIndex = 12;
			this->label4->Text = L"��������:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(8, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(232, 24);
			this->label5->TabIndex = 13;
			this->label5->Text = L"�������� �����������:";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBoxConfName);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBoxDates);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBoxCityName);
			this->panel1->Controls->Add(this->textBoxThemeName);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(12, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(760, 155);
			this->panel1->TabIndex = 14;
			// 
			// ConfForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->buttonMessages);
			this->Controls->Add(this->buttonMembers);
			this->Controls->Add(this->buttonSettings);
			this->Controls->Add(this->buttonLeave);
			this->Controls->Add(this->buttonDelete);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ConfForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConfForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//Message manager
private: System::Void buttonMessages_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->timer->Stop();
	messageManagerForm = gcnew MessageManagerForm(accountType, this->confID);

	this->Hide();
	messageManagerForm->ShowDialog();
	this->Show();
	this->Activate();

	delete messageManagerForm;
	this->timer->Start();
}

//Memeber manager
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

#pragma region INIT_SECTION
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
#pragma endregion INIT_SECTION

#pragma region SETTINGS_SECTION
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

//���������
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

		this->buttonSettings->Text = L"���������";
	}
	else
	{
		this->textBoxConfName->ReadOnly = true;
		this->textBoxDates->ReadOnly = true;
		this->textBoxCityName->ReadOnly = true;
		this->textBoxThemeName->ReadOnly = true;

		this->richTextBox1->ReadOnly = true;

		this->buttonSettings->Text = L"��c������";

		std::vector<char> mass;
		int offset = 0;
		createSettingsMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);
		inEdit = false;
	}
}

#pragma endregion SETTINGS_SECTION

#pragma region LEAVE_JOIN_SECTION
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

//��������
private: System::Void buttonLeave_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (this->alreadyIn)
	{
		if (MessageBox::Show(
			"�� �������?",
			"������",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2,
			MessageBoxOptions::DefaultDesktopOnly
		) == System::Windows::Forms::DialogResult::No)
			return;

		this->Activate();

		std::vector<char> mass;
		int offset = 0;

		createLeaveMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);

		this->returnState = RETURN_STATE_UPDATE_CONFS;
		this->Close();
	}
	else
	{
		if (MessageBox::Show(
			"�� �������?",
			"������",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2,
			MessageBoxOptions::DefaultDesktopOnly
		) == System::Windows::Forms::DialogResult::No)
			return;

		this->Activate();

		std::vector<char> mass;
		int offset = 0;

		createJoinMessage(mass, offset);

		printCharMass(mass);

		SendToServer(&mass[0], offset, _socket);
	}
}
#pragma endregion LEAVE_JOIN_SECTION

#pragma region DELETE_SECTION
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

//�������
private: System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e) 
{
	std::vector<char> mass;
	int offset = 0;

	createDeleteMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}
#pragma endregion DELETE_SECTION

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
				"��������� ����������� �� ����������",
				"������",
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
				"�������� ������� ��������",
				"�����",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();

			this->returnState = RETURN_STATE_UPDATE_CONFS;

			return;
		}

		if (d.ActionID == action_leave_conf_response)
		{
			MessageBox::Show(
				"����������� ������� ��������",
				"�����",
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
				"����������� ������� �������",
				"�����",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->returnState = RETURN_STATE_UPDATE_CONFS;

			this->Close();
		}

		if (d.ActionID == action_join_conf_response)
		{
			MessageBox::Show(
				"�� ���� ��������� �� �����������",
				"�����",
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
