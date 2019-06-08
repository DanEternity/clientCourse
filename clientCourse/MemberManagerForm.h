#pragma once

#include "Network.h"

#include "ScientistForm.h"
#include "MessageForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MemberManagerForm
	/// </summary>
	public ref class MemberManagerForm : public System::Windows::Forms::Form
	{
	public: ScientistForm ^ scientistForm;
	public: MessageForm ^ messageForm;
	private: System::Windows::Forms::Timer^  timer;
	public: int confID;
	private: System::Windows::Forms::Button^  buttonExportExcel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastName;
	private: System::Windows::Forms::Button^  buttonAddMember;
	public: int accountType;
		MemberManagerForm(int accountType, int confID)
		{
			InitializeComponent();
			
			this->accountType = accountType;
			this->confID = confID;

			loadData();

			if (accountType == ACCOUNT_TYPE_SCIENTIST)
				this->buttonAddMember->Visible = false;
			else this->buttonAddMember->Visible = true;

			this->timer->Start();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MemberManagerForm()
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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonExportExcel = (gcnew System::Windows::Forms::Button());
			this->buttonAddMember = (gcnew System::Windows::Forms::Button());
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
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id, this->firstName,
					this->lastName
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Size = System::Drawing::Size(760, 492);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MemberManagerForm::dataGridView1_CellDoubleClick);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// firstName
			// 
			this->firstName->HeaderText = L"»м€";
			this->firstName->Name = L"firstName";
			this->firstName->ReadOnly = true;
			this->firstName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->firstName->Width = 375;
			// 
			// lastName
			// 
			this->lastName->HeaderText = L"‘амили€";
			this->lastName->Name = L"lastName";
			this->lastName->ReadOnly = true;
			this->lastName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->lastName->Width = 375;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MemberManagerForm::timer_Tick);
			// 
			// buttonExportExcel
			// 
			this->buttonExportExcel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonExportExcel->Location = System::Drawing::Point(493, 510);
			this->buttonExportExcel->Name = L"buttonExportExcel";
			this->buttonExportExcel->Size = System::Drawing::Size(279, 39);
			this->buttonExportExcel->TabIndex = 1;
			this->buttonExportExcel->Text = L"Ёкспортировать в Excel";
			this->buttonExportExcel->UseVisualStyleBackColor = true;
			// 
			// buttonAddMember
			// 
			this->buttonAddMember->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonAddMember->Location = System::Drawing::Point(12, 510);
			this->buttonAddMember->Name = L"buttonAddMember";
			this->buttonAddMember->Size = System::Drawing::Size(279, 39);
			this->buttonAddMember->TabIndex = 2;
			this->buttonAddMember->Text = L"ƒобавить участника";
			this->buttonAddMember->UseVisualStyleBackColor = true;
			this->buttonAddMember->Click += gcnew System::EventHandler(this, &MemberManagerForm::buttonAddMember_Click);
			// 
			// MemberManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->buttonAddMember);
			this->Controls->Add(this->buttonExportExcel);
			this->Controls->Add(this->dataGridView1);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"MemberManagerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MemberManagerForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_get_conf_members;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	int confID = this->confID;
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

private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	this->timer->Stop();
	scientistForm = gcnew ScientistForm(accountType);

	this->Hide();
	scientistForm->ShowDialog();
	this->Show();
	this->Activate();

	delete scientistForm;
	this->timer->Start();
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

		if (d.ActionID == action_get_conf_members_response)
		{
			int count;
			readIntFromMessage(q, count, offset);
			for (int i(0); i < count; i++)
			{
				int id;
				std::string firstName;
				std::string lastName;

				readIntFromMessage(q, id, offset);
				readStringFromMessage(q, firstName, offset);
				readStringFromMessage(q, lastName, offset);

				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = id.ToString();
				this->dataGridView1->Rows[i]->Cells[1]->Value = gcnew System::String(firstName.c_str());
				this->dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String(lastName.c_str());
			}
		}
	}
}

//add memeber
private: System::Void buttonAddMember_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->timer->Stop();

	this->messageForm = gcnew MessageForm(accountType, MESSAGE_INVITE, -1, true, this->confID);
	this->Hide();
	messageForm->ShowDialog();

	this->Show();
	this->Activate();

	this->timer->Start();
}
};
}
