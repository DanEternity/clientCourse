#pragma once

#include "Network.h"

#include "ProfileForm.h"
#include "ConfForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SearchForm
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public: int accountType;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBoxSearchPattern;

	private: System::Windows::Forms::Button^  buttonFind;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  alreadyIn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  confName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  theme;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date;
	private: System::Windows::Forms::Label^  labelCityName;
	private: System::Windows::Forms::TextBox^  textBoxCityName;
	private: System::Windows::Forms::Label^  labelThemeName;
	private: System::Windows::Forms::TextBox^  textBoxThemeName;





	public: ConfForm ^ confForm;

	public: SearchForm(int accountType)
	{
		InitializeComponent();
		
		this->accountType = accountType;

		this->timer->Start();
	}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBoxSearchPattern = (gcnew System::Windows::Forms::TextBox());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelCityName = (gcnew System::Windows::Forms::Label());
			this->textBoxCityName = (gcnew System::Windows::Forms::TextBox());
			this->labelThemeName = (gcnew System::Windows::Forms::Label());
			this->textBoxThemeName = (gcnew System::Windows::Forms::TextBox());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->alreadyIn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->confName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->theme = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ControlLight;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id, this->alreadyIn,
					this->confName, this->theme, this->Date
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 106);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(760, 443);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SearchForm::dataGridView1_CellDoubleClick);
			// 
			// textBoxSearchPattern
			// 
			this->textBoxSearchPattern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxSearchPattern->Location = System::Drawing::Point(12, 12);
			this->textBoxSearchPattern->Name = L"textBoxSearchPattern";
			this->textBoxSearchPattern->Size = System::Drawing::Size(760, 29);
			this->textBoxSearchPattern->TabIndex = 1;
			this->textBoxSearchPattern->Text = L"Введите строку для поиска";
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonFind->Location = System::Drawing::Point(670, 71);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(103, 29);
			this->buttonFind->TabIndex = 2;
			this->buttonFind->Text = L"Поиск";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &SearchForm::buttonFind_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &SearchForm::timer_Tick);
			// 
			// labelCityName
			// 
			this->labelCityName->AutoSize = true;
			this->labelCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelCityName->Location = System::Drawing::Point(12, 44);
			this->labelCityName->Name = L"labelCityName";
			this->labelCityName->Size = System::Drawing::Size(171, 24);
			this->labelCityName->TabIndex = 3;
			this->labelCityName->Text = L"Название города:";
			// 
			// textBoxCityName
			// 
			this->textBoxCityName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxCityName->Location = System::Drawing::Point(12, 71);
			this->textBoxCityName->Name = L"textBoxCityName";
			this->textBoxCityName->Size = System::Drawing::Size(323, 29);
			this->textBoxCityName->TabIndex = 4;
			// 
			// labelThemeName
			// 
			this->labelThemeName->AutoSize = true;
			this->labelThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelThemeName->Location = System::Drawing::Point(341, 44);
			this->labelThemeName->Name = L"labelThemeName";
			this->labelThemeName->Size = System::Drawing::Size(192, 24);
			this->labelThemeName->TabIndex = 5;
			this->labelThemeName->Text = L"Название тематики:";
			// 
			// textBoxThemeName
			// 
			this->textBoxThemeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBoxThemeName->Location = System::Drawing::Point(341, 71);
			this->textBoxThemeName->Name = L"textBoxThemeName";
			this->textBoxThemeName->Size = System::Drawing::Size(323, 29);
			this->textBoxThemeName->TabIndex = 6;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// alreadyIn
			// 
			this->alreadyIn->HeaderText = L"alredyIn";
			this->alreadyIn->Name = L"alreadyIn";
			this->alreadyIn->ReadOnly = true;
			this->alreadyIn->Visible = false;
			// 
			// confName
			// 
			this->confName->HeaderText = L"Название конференции";
			this->confName->Name = L"confName";
			this->confName->ReadOnly = true;
			this->confName->Width = 382;
			// 
			// theme
			// 
			this->theme->HeaderText = L"Тематика";
			this->theme->Name = L"theme";
			this->theme->ReadOnly = true;
			this->theme->Width = 225;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Даты";
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			this->Date->Width = 150;
			// 
			// SearchForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->textBoxThemeName);
			this->Controls->Add(this->labelThemeName);
			this->Controls->Add(this->textBoxCityName);
			this->Controls->Add(this->labelCityName);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->textBoxSearchPattern);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"SearchForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SearchForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region FIND_SECTION
private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_search_conf;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
	
	std::string pattern = getStringFromSystemString(this->textBoxSearchPattern->Text);
	std::string cityName = getStringFromSystemString(this->textBoxCityName->Text);
	std::string themeName = getStringFromSystemString(this->textBoxThemeName->Text);
	int isPattern = 1;
	int isCity = (cityName.size() > 0 ? 1 : 0);
	int isTheme = (themeName.size() > 0 ? 1: 0);

	writeStringToMessage(mass, pattern, offset);
	writeStringToMessage(mass, cityName, offset);
	writeStringToMessage(mass, themeName, offset);
	writeIntToMessage(mass, isPattern, offset);
	writeIntToMessage(mass, isCity, offset);
	writeIntToMessage(mass, isTheme, offset);
}

private: void loadData()
{
	int offset = 0;

	std::vector<char> mass;

	createMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}

private: System::Void buttonFind_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->dataGridView1->Rows->Clear();
	loadData();
}
#pragma endregion FIND_SECTION
private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	timer->Stop();
	confForm = gcnew ConfForm(accountType, Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString())
		, Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString()));

	this->Hide();
	confForm->ShowDialog();
	this->Show();
	this->Activate();

	delete confForm;
	timer->Start();
}

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

		if (d.ActionID == action_search_conf_response)
		{
			int count;
			readIntFromMessage(q, count, offset);
			for (int i(0); i < count; i++)
			{
				/*
				int id;
				std::string confName;

				readIntFromMessage(q, id, offset);
				readStringFromMessage(q, confName, offset);

				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = id.ToString();
				this->dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String(confName.c_str());
				*/
				int id;
				std::string name;
				std::string date;
				int themeId;
				int cityId;
				std::string description;
				int admin;
				std::string cityName;
				std::string themeName;
				int our;

				readIntFromMessage(q, id, offset);
				readStringFromMessage(q, name, offset);
				readStringFromMessage(q, date, offset);
				readIntFromMessage(q, themeId, offset);
				readIntFromMessage(q, cityId, offset);
				readStringFromMessage(q, description, offset);
				readIntFromMessage(q, admin, offset);
				readStringFromMessage(q, cityName, offset);
				readStringFromMessage(q, themeName, offset);
				readIntFromMessage(q, our, offset);

				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = id.ToString();
				this->dataGridView1->Rows[i]->Cells[1]->Value = our.ToString();
				this->dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String(name.c_str());
				this->dataGridView1->Rows[i]->Cells[3]->Value = gcnew System::String(themeName.c_str());
				this->dataGridView1->Rows[i]->Cells[4]->Value = gcnew System::String(date.c_str());
			}
		}
	}
}
};
}
