#pragma once

#include "MainHeader.h"

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
	private: System::Windows::Forms::Button^  buttonDelete;
	private: System::Windows::Forms::Button^  buttonLeave;
			 
	public:
		ConfForm(int accountType)//What conf should we create? ///FIXME
		{
			InitializeComponent();
			
			accountType = accountType;
			messageManagerForm = gcnew MessageManagerForm(accountType);
			memberManagerForm = gcnew MemberManagerForm(accountType);

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
	private: System::Windows::Forms::Label^  labelConfName;
	protected:
	private: System::Windows::Forms::Label^  labelDates;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::Button^  buttonMembers;
	private: System::Windows::Forms::Button^  buttonMessages;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

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
			this->labelConfName = (gcnew System::Windows::Forms::Label());
			this->labelDates = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonLeave = (gcnew System::Windows::Forms::Button());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->buttonMembers = (gcnew System::Windows::Forms::Button());
			this->buttonMessages = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelConfName
			// 
			this->labelConfName->AutoSize = true;
			this->labelConfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->labelConfName->Location = System::Drawing::Point(12, 9);
			this->labelConfName->Name = L"labelConfName";
			this->labelConfName->Size = System::Drawing::Size(156, 29);
			this->labelConfName->TabIndex = 0;
			this->labelConfName->Text = L"<ConfName>";
			// 
			// labelDates
			// 
			this->labelDates->AutoSize = true;
			this->labelDates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->labelDates->Location = System::Drawing::Point(12, 38);
			this->labelDates->Name = L"labelDates";
			this->labelDates->Size = System::Drawing::Size(103, 29);
			this->labelDates->TabIndex = 1;
			this->labelDates->Text = L"<Dates>";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label1->Location = System::Drawing::Point(174, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"<City>";
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
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(750, 426);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// ConfForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelDates);
			this->Controls->Add(this->labelConfName);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ConfForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConfForm";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//Сообщения
private: System::Void buttonMessages_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Hide();
	messageManagerForm->ShowDialog();
	this->Show();
	this->Activate();
}

//Участники
private: System::Void buttonMembers_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Hide();
	memberManagerForm->ShowDialog();
	this->Show();
	this->Activate();
}

//Настройки
private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) 
{

}

//Покинуть
private: System::Void buttonLeave_Click(System::Object^  sender, System::EventArgs^  e) 
{
}

//Удалить
private: System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e) 
{
}
};
}
