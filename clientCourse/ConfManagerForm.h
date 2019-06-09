#pragma once

#include "Network.h"

#include "ConfForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Office::Interop;

	/// <summary>
	/// Сводка для ConfManagerForm
	/// </summary>
	public ref class ConfManagerForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Button^  buttonAddConf;
	private: System::Windows::Forms::Button^  buttonExportExcel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ConfName;
	public: ConfForm ^ confForm = nullptr;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	public:
	public: Microsoft::Office::Interop::Excel::Application ^exelFile;
	public: ConfManagerForm(int accountType)
		{
			InitializeComponent();
			
			this->accountType = accountType;

			loadData();
			
			if (accountType == ACCOUNT_TYPE_SCIENTIST)
				this->buttonAddConf->Visible = false;

			timer->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ConfManagerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ConfName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonAddConf = (gcnew System::Windows::Forms::Button());
			this->buttonExportExcel = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
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
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->ID, this->ConfName });
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->dataGridView1->RowTemplate->Height = 32;
			this->dataGridView1->Size = System::Drawing::Size(760, 494);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ConfManagerForm::dataGridView1_CellDoubleClick);
			// 
			// ID
			// 
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Silver;
			this->ID->DefaultCellStyle = dataGridViewCellStyle2;
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Visible = false;
			// 
			// ConfName
			// 
			this->ConfName->FillWeight = 680;
			this->ConfName->HeaderText = L"Название конференции";
			this->ConfName->Name = L"ConfName";
			this->ConfName->ReadOnly = true;
			this->ConfName->Width = 757;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &ConfManagerForm::timer_Tick);
			// 
			// buttonAddConf
			// 
			this->buttonAddConf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonAddConf->Location = System::Drawing::Point(12, 512);
			this->buttonAddConf->Name = L"buttonAddConf";
			this->buttonAddConf->Size = System::Drawing::Size(254, 37);
			this->buttonAddConf->TabIndex = 1;
			this->buttonAddConf->Text = L"Создать конференцию";
			this->buttonAddConf->UseVisualStyleBackColor = true;
			this->buttonAddConf->Click += gcnew System::EventHandler(this, &ConfManagerForm::buttonAddConf_Click);
			// 
			// buttonExportExcel
			// 
			this->buttonExportExcel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonExportExcel->Location = System::Drawing::Point(518, 512);
			this->buttonExportExcel->Name = L"buttonExportExcel";
			this->buttonExportExcel->Size = System::Drawing::Size(254, 37);
			this->buttonExportExcel->TabIndex = 2;
			this->buttonExportExcel->Text = L"Экспорт в excel";
			this->buttonExportExcel->UseVisualStyleBackColor = true;
			this->buttonExportExcel->Click += gcnew System::EventHandler(this, &ConfManagerForm::buttonExportExcel_Click);
			// 
			// ConfManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->buttonExportExcel);
			this->Controls->Add(this->buttonAddConf);
			this->Controls->Add(this->dataGridView1);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ConfManagerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConfManagerForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

//Conf form
private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
	if (e->RowIndex < 0)
		return;
	
	timer->Stop();
	confForm = gcnew ConfForm(accountType, Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString()), ALREADY_IN);

	this->Hide();
	confForm->ShowDialog();
	this->Show();
	this->Activate();

	if (confForm->returnState == RETURN_STATE_UPDATE_CONFS)
	{
		this->dataGridView1->Rows->Clear();
		loadData();
	}

	delete confForm;
	timer->Start();
}

#pragma region INIT_SECTION
private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_conf_user;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
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

#pragma region ADD_CONF_SECTION
void createMessageAddConf(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_add_conference;///FIXME
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
}

//addConf
private: System::Void buttonAddConf_Click(System::Object^  sender, System::EventArgs^  e)
{
	///FIXME
	int offset = 0;

	std::vector<char> mass;

	createMessageAddConf(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}
#pragma endregion ADD_CONF_SECTION

#pragma region EXPORT_TO_EXCEL
private: void createMessageFullConfInfo(std::vector<char> &mass, int &offset, int confID)
{
	__int64 Account = accountID;
	Actions ActionID = action_conf_full_info;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	writeIntToMessage(mass, confID, offset);
}

private: std::vector<std::string> getConfInfo(int confID)
{
	std::vector<std::string> buffer;

	int offset = 0;
	std::vector<char> mass;

	createMessageFullConfInfo(mass, offset, confID);

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

		buffer.push_back(name);
		buffer.push_back(date);
		buffer.push_back(cityName);
		buffer.push_back(themeName);
		buffer.push_back(description);
	}

	return buffer;
}

private: System::Void buttonExportExcel_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		return;

	this->timer->Stop();

	std::vector<std::vector<std::string> > confInfoMatr;

	for (int i(0); i < this->dataGridView1->Rows->Count; i++)
		confInfoMatr.push_back(getConfInfo(stoi(getStringFromSystemString(this->dataGridView1->Rows[i]->Cells[0]->Value->ToString()))));

	this->timer->Start();
	
	Excel::Application ^excelApp =  createExcelFile();
	writeToExcel(excelApp, confInfoMatr);
	saveAndExitExcel(excelApp, saveFileDialog1->FileName);

	MessageBox::Show(
		"Файл был успешно создан",
		"Успех",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information,
		MessageBoxDefaultButton::Button1,
		MessageBoxOptions::DefaultDesktopOnly
	);
}
#pragma endregion EXPORT_TO_EXCEL

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
		
		if (d.ActionID == action_add_conference_response)
		{
			MessageBox::Show(
				"Конференция была создана",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();

			this->dataGridView1->Rows->Clear();
			loadData();
		}

		if (d.ActionID == action_conf_user_responce)
		{
			int count;
			readIntFromMessage(q, count, offset);
			for (int i(0); i < count; i++)
			{
				int id;
				int size;

				readIntFromMessage(q, id, offset);
				readIntFromMessage(q, size, offset);

				std::string st;
				st.resize(size);
				readDataFromMessage(q, st, size, offset);

				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = id.ToString();
				this->dataGridView1->Rows[i]->Cells[1]->Value = gcnew System::String(st.c_str());
			}
		}
	}
}
};
}
