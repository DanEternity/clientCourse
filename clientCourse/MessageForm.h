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
	/// Сводка для MessageForm
	/// </summary>
	public ref class MessageForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public:
	public: int messageType;
	public:
		MessageForm(int accountType, int messageType)
		{
			InitializeComponent();
			
			this->accountType = accountType;
			this->messageType = messageType;

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
				this->label2->Text = L"Администратор";
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
				this->label2->Text = L"Ученый";

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
			this->labelTheme = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonAccept = (gcnew System::Windows::Forms::Button());
			this->buttonDenied = (gcnew System::Windows::Forms::Button());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelTheme
			// 
			this->labelTheme->AutoSize = true;
			this->labelTheme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelTheme->Location = System::Drawing::Point(12, 44);
			this->labelTheme->Name = L"labelTheme";
			this->labelTheme->Size = System::Drawing::Size(93, 24);
			this->labelTheme->TabIndex = 1;
			this->labelTheme->Text = L"<Theme>";
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
			this->labelFrom->AutoSize = true;
			this->labelFrom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelFrom->Location = System::Drawing::Point(12, 9);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(77, 24);
			this->labelFrom->TabIndex = 0;
			this->labelFrom->Text = L"<From>";
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
			// MessageForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
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
private: System::Void buttonAccept_Click(System::Object^  sender, System::EventArgs^  e) 
{

}

private: System::Void buttonDenied_Click(System::Object^  sender, System::EventArgs^  e) 
{
}
};
}
