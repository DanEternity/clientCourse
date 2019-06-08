#pragma once

#include <iostream>

#include "Network.h"
#include "MessageForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MessageManagerForm
	/// </summary>
	public ref class MessageManagerForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  messageType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  fromId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  toId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Отправитель;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Получатель;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Тема;

	public: MessageForm ^ messageForm;
		
	public: MessageManagerForm(int accountType)
		{
			InitializeComponent();
			
			this->accountType = accountType;

			loadData();

			timer->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MessageManagerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->messageType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fromId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->toId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Отправитель = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Получатель = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Тема = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->checkBox6);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Controls->Add(this->checkBox9);
			this->panel1->Controls->Add(this->checkBox7);
			this->panel1->Controls->Add(this->checkBox5);
			this->panel1->Controls->Add(this->checkBox3);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(303, 537);
			this->panel1->TabIndex = 0;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Checked = true;
			this->checkBox6->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox6->Location = System::Drawing::Point(3, 71);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(268, 28);
			this->checkBox6->TabIndex = 13;
			this->checkBox6->Text = L"Отправленные сообщения";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox2->Location = System::Drawing::Point(3, 411);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(255, 28);
			this->checkBox2->TabIndex = 11;
			this->checkBox2->Text = L"Прочитанные сообщения";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Checked = true;
			this->checkBox9->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox9->Location = System::Drawing::Point(3, 343);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(277, 28);
			this->checkBox9->TabIndex = 9;
			this->checkBox9->Text = L"Непрочитанные сообщения";
			this->checkBox9->UseVisualStyleBackColor = true;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Checked = true;
			this->checkBox7->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox7->Location = System::Drawing::Point(3, 275);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(297, 28);
			this->checkBox7->TabIndex = 7;
			this->checkBox7->Text = L"Непрочитанные приглашения";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox5->Location = System::Drawing::Point(3, 207);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(265, 28);
			this->checkBox5->TabIndex = 5;
			this->checkBox5->Text = L"Непринятые приглашения";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox3->Location = System::Drawing::Point(3, 139);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(243, 28);
			this->checkBox3->TabIndex = 3;
			this->checkBox3->Text = L"Принятые приглашения";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(245, 28);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Отправленные запросы";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MessageManagerForm::checkBox_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(321, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(451, 537);
			this->panel2->TabIndex = 1;
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id, this->messageType,
					this->fromId, this->toId, this->Отправитель, this->Получатель, this->Тема
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(445, 531);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MessageManagerForm::dataGridView1_CellDoubleClick);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MessageManagerForm::timer_Tick);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// messageType
			// 
			this->messageType->HeaderText = L"messageType";
			this->messageType->Name = L"messageType";
			this->messageType->ReadOnly = true;
			this->messageType->Visible = false;
			// 
			// fromId
			// 
			this->fromId->HeaderText = L"fromId";
			this->fromId->Name = L"fromId";
			this->fromId->ReadOnly = true;
			this->fromId->Visible = false;
			// 
			// toId
			// 
			this->toId->HeaderText = L"toId";
			this->toId->Name = L"toId";
			this->toId->ReadOnly = true;
			this->toId->Visible = false;
			// 
			// Отправитель
			// 
			this->Отправитель->HeaderText = L"from";
			this->Отправитель->Name = L"Отправитель";
			this->Отправитель->ReadOnly = true;
			// 
			// Получатель
			// 
			this->Получатель->HeaderText = L"to";
			this->Получатель->Name = L"Получатель";
			this->Получатель->ReadOnly = true;
			// 
			// Тема
			// 
			this->Тема->HeaderText = L"label";
			this->Тема->Name = L"Тема";
			this->Тема->ReadOnly = true;
			// 
			// MessageManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"MessageManagerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MessageManagerForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_message_list;
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

private: System::Void checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{

}

private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	this->timer->Stop();

	int messageType = Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString());
	int messageID = Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
	this->messageForm = gcnew MessageForm(accountType, messageType, messageID, false, -1);

	this->Hide();
	messageForm->ShowDialog();
	this->Show();
	this->Activate();

	delete this->messageForm;
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

		if (d.ActionID == action_message_list_response)
		{
			int count;
			readIntFromMessage(q, count, offset);

			for (int i(0); i < count; i++)
			{
				int id;
				int fromId;
				int toId;
				std::string label;
				int messageType;
				std::string fromName;
				std::string toName;

				readIntFromMessage(q, id, offset);
				readIntFromMessage(q, fromId, offset);
				readIntFromMessage(q, toId, offset);
				readStringFromMessage(q, label, offset);
				readIntFromMessage(q, messageType, offset);
				readStringFromMessage(q, fromName, offset);
				readStringFromMessage(q, toName, offset);

				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = id.ToString();
				this->dataGridView1->Rows[i]->Cells[1]->Value = messageType.ToString();
				this->dataGridView1->Rows[i]->Cells[2]->Value = fromId.ToString();
				this->dataGridView1->Rows[i]->Cells[3]->Value = toId.ToString();
				this->dataGridView1->Rows[i]->Cells[4]->Value = gcnew System::String(fromName.c_str());
				this->dataGridView1->Rows[i]->Cells[5]->Value = gcnew System::String(toName.c_str());
				this->dataGridView1->Rows[i]->Cells[6]->Value = gcnew System::String(label.c_str());
			}
		}
	}
}
};
}
