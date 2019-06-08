#pragma once
///FIXME create textBox

#include "Network.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MessageForm
	/// </summary>
	public ref class MessageForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: int messageID;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Label^  labelTo;
	public: bool isCreating;
	private: System::Windows::Forms::Button^  buttonSend;
	public: int confID;
	public: int messageType;
	public: int messageParam;
		MessageForm(int accountType, int messageType, int messageID, bool creating, int confID)
		{
			InitializeComponent();

			this->accountType = accountType;
			this->messageType = messageType;
			this->messageID = messageID;
			this->isCreating = creating;
			this->confID = confID;

			loadData();

			timer->Start();

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
				this->label2->Text = L"Администратор";
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
				this->label2->Text = L"Ученый";

			buttonSend->Enabled = this->isCreating;
			buttonSend->Visible = this->isCreating;
			if (this->isCreating)
			{
				this->buttonAccept->Visible = false;
				this->buttonAccept->Enabled = false;

				this->buttonDenied->Visible = false;
				this->buttonDenied->Enabled = false;
			}
			else
			{
				if (messageType == MESSAGE_INFORMATION)
				{
					this->buttonAccept->Hide();
					this->buttonDenied->Hide();

					this->label1->Text = L"Информационное сообщение";
				}
				else if (messageType == MESSAGE_INVITE)
				{
					if (accountType == ACCOUNT_TYPE_SCIENTIST)
					{
						//everything is okay
					}
					else if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
					{
						this->buttonAccept->Hide();
						this->buttonDenied->Text = L"Вернуть";
					}

					this->label1->Text = L"Приглашение";
				}
				else if (messageType == MESSAGE_REQUEST)
				{
					if (accountType == ACCOUNT_TYPE_SCIENTIST)
					{
						this->buttonAccept->Hide();
						this->buttonDenied->Text = L"Вернуть";
					}
					else if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
					{
						//everything is okay
					}

					this->label1->Text = L"Запрос";
				}
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MessageForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  labelTheme;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  buttonAccept;
	private: System::Windows::Forms::Button^  buttonDenied;
	private: System::Windows::Forms::Label^  labelFrom;
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
			this->labelTheme = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonAccept = (gcnew System::Windows::Forms::Button());
			this->buttonDenied = (gcnew System::Windows::Forms::Button());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelTo = (gcnew System::Windows::Forms::Label());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelTheme
			// 
			this->labelTheme->AutoSize = true;
			this->labelTheme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelTheme->Location = System::Drawing::Point(12, 44);
			this->labelTheme->Name = L"labelTheme";
			this->labelTheme->Size = System::Drawing::Size(61, 24);
			this->labelTheme->TabIndex = 1;
			this->labelTheme->Text = L"Тема:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 71);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(760, 433);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// buttonAccept
			// 
			this->buttonAccept->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonAccept->Location = System::Drawing::Point(12, 510);
			this->buttonAccept->Name = L"buttonAccept";
			this->buttonAccept->Size = System::Drawing::Size(366, 39);
			this->buttonAccept->TabIndex = 3;
			this->buttonAccept->Text = L"Принять";
			this->buttonAccept->UseVisualStyleBackColor = true;
			this->buttonAccept->Click += gcnew System::EventHandler(this, &MessageForm::buttonAccept_Click);
			// 
			// buttonDenied
			// 
			this->buttonDenied->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonDenied->Location = System::Drawing::Point(406, 510);
			this->buttonDenied->Name = L"buttonDenied";
			this->buttonDenied->Size = System::Drawing::Size(366, 39);
			this->buttonDenied->TabIndex = 4;
			this->buttonDenied->Text = L"Отказать";
			this->buttonDenied->UseVisualStyleBackColor = true;
			this->buttonDenied->Click += gcnew System::EventHandler(this, &MessageForm::buttonDenied_Click);
			// 
			// labelFrom
			// 
			this->labelFrom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelFrom->Location = System::Drawing::Point(12, 9);
			this->labelFrom->MaximumSize = System::Drawing::Size(150, 24);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(150, 24);
			this->labelFrom->TabIndex = 0;
			this->labelFrom->Text = L"От:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(694, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"type";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(694, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"role";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MessageForm::timer_Tick);
			// 
			// labelTo
			// 
			this->labelTo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelTo->Location = System::Drawing::Point(168, 9);
			this->labelTo->MaximumSize = System::Drawing::Size(150, 24);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(150, 24);
			this->labelTo->TabIndex = 7;
			this->labelTo->Text = L"Кому:";
			// 
			// buttonSend
			// 
			this->buttonSend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonSend->Location = System::Drawing::Point(208, 510);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(366, 39);
			this->buttonSend->TabIndex = 8;
			this->buttonSend->Text = L"Отправить";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MessageForm::buttonSend_Click);
			// 
			// MessageForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->labelTo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonDenied);
			this->Controls->Add(this->buttonAccept);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->labelTheme);
			this->Controls->Add(this->labelFrom);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"MessageForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MessageForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void createMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_get_message;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();
	
	int messageID = this->messageID;
	writeIntToMessage(mass, messageID, offset);
}

private: void loadData()
{
	int offset = 0;

	std::vector<char> mass;

	createMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}

private: void createMessageSendMessage(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_send_message;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	int id = 0;
	int fromId = 0;
	int toId = 0;
	std::string label = getStringFromSystemString(this->labelTheme->Text).substr(3);
	int messageType = this->messageType;
	std::string fromName = "";
	std::string toName = getStringFromSystemString(this->labelTo->Text).substr(5);
	std::string text = getStringFromSystemString(this->richTextBox1->Text);
	int param = this->confID;
	
	toName = "test2";

	writeIntToMessage(mass, id, offset);
	writeIntToMessage(mass, fromId, offset);
	writeIntToMessage(mass, toId, offset);
	writeStringToMessage(mass, label, offset);
	writeIntToMessage(mass, messageType, offset);
	writeStringToMessage(mass, fromName, offset);
	writeStringToMessage(mass, toName, offset);
	writeStringToMessage(mass, text, offset);
	writeIntToMessage(mass, param, offset);
}

private: void createMessageJoinConference(std::vector<char> &mass, int &offset)
{
	__int64 Account = accountID;
	Actions ActionID = action_join_conf;
	int PacketID = 0;
	int PacketCountExpected = 0;

	mass.resize(200);

	writeHeader(mass, DataFormat(Account, ActionID, PacketID, PacketCountExpected));

	offset = getHeaderSize();

	writeIntToMessage(mass, this->messageParam, offset);
}

private: System::Void buttonAccept_Click(System::Object^  sender, System::EventArgs^  e) 
{
	std::vector<char> mass;
	int offset;

	createMessageJoinConference(mass, offset);
	
	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}

private: System::Void buttonDenied_Click(System::Object^  sender, System::EventArgs^  e) 
{

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

		if (d.ActionID == action_error)
		{
			MessageBox::Show(
				"Ошибка при добавлении на коонференции",
				"Успех",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information,
				MessageBoxDefaultButton::Button1,
				MessageBoxOptions::DefaultDesktopOnly
			);

			this->Activate();
		}

		if (d.ActionID == action_join_conf)
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

		if (d.ActionID == action_get_message_response)
		{
			int count;//count = 1
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
				std::string text;
				int param;

				readIntFromMessage(q, id, offset);
				readIntFromMessage(q, fromId, offset);
				readIntFromMessage(q, toId, offset);
				readStringFromMessage(q, label, offset);
				readIntFromMessage(q, messageType, offset);
				readStringFromMessage(q, fromName, offset);
				readStringFromMessage(q, toName, offset);
				readStringFromMessage(q, text, offset);
				readIntFromMessage(q, param, offset);

				this->messageParam = param;

				System::String ^fromS = L"От: " + gcnew System::String(fromName.c_str());
				System::String ^labelS = L"Тема: " + gcnew System::String(label.c_str());
				System::String ^toS = L"Кому: " + gcnew System::String(toName.c_str());
				this->labelFrom->Text = fromS;
				this->labelTheme->Text = labelS;
				this->labelTo->Text = toS;

				this->richTextBox1->Text = gcnew System::String(text.c_str());
			}
		}
	}
}

private: System::Void buttonSend_Click(System::Object^  sender, System::EventArgs^  e) 
{
	std::vector<char> mass;
	int offset = 0;

	createMessageSendMessage(mass, offset);

	printCharMass(mass);

	SendToServer(&mass[0], offset, _socket);
}
};
}
