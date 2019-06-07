#pragma once

#include "Network.h"

#include "ScientistForm.h"
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	public:
	public: ScientistForm ^ scientistForm;
	public: ConfForm ^ confForm;

	public: SearchForm(int accountType)
	{
		InitializeComponent();
		
		this->accountType = accountType;
		scientistForm = gcnew ScientistForm(accountType);
		confForm = gcnew ConfForm(accountType);
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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  labelConfTheme;
	private: System::Windows::Forms::TextBox^  textBoxConfTheme;
	private: System::Windows::Forms::Button^  buttonFind;
	private: System::Windows::Forms::CheckBox^  checkBoxScientistFind;
	private: System::Windows::Forms::TextBox^  textBoxDataEnd;
	private: System::Windows::Forms::TextBox^  textBoxDataStart;
	private: System::Windows::Forms::Label^  labelDataEnd;
	private: System::Windows::Forms::Label^  labelDataStart;
	private: System::Windows::Forms::TextBox^  textBoxScientistName;
	private: System::Windows::Forms::Label^  labelScientistName;
	private: System::Windows::Forms::TextBox^  textBoxConfName;
	private: System::Windows::Forms::Label^  labelConfName;
	private: System::Windows::Forms::TextBox^  textBoxCity;
	private: System::Windows::Forms::Label^  labelCity;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::CheckBox^  checkBoxConfFind;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->checkBoxConfFind = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxScientistFind = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxDataEnd = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDataStart = (gcnew System::Windows::Forms::TextBox());
			this->labelDataEnd = (gcnew System::Windows::Forms::Label());
			this->labelDataStart = (gcnew System::Windows::Forms::Label());
			this->textBoxScientistName = (gcnew System::Windows::Forms::TextBox());
			this->labelScientistName = (gcnew System::Windows::Forms::Label());
			this->textBoxConfName = (gcnew System::Windows::Forms::TextBox());
			this->labelConfName = (gcnew System::Windows::Forms::Label());
			this->textBoxCity = (gcnew System::Windows::Forms::TextBox());
			this->labelCity = (gcnew System::Windows::Forms::Label());
			this->labelConfTheme = (gcnew System::Windows::Forms::Label());
			this->textBoxConfTheme = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonFind);
			this->panel1->Controls->Add(this->checkBoxConfFind);
			this->panel1->Controls->Add(this->checkBoxScientistFind);
			this->panel1->Controls->Add(this->textBoxDataEnd);
			this->panel1->Controls->Add(this->textBoxDataStart);
			this->panel1->Controls->Add(this->labelDataEnd);
			this->panel1->Controls->Add(this->labelDataStart);
			this->panel1->Controls->Add(this->textBoxScientistName);
			this->panel1->Controls->Add(this->labelScientistName);
			this->panel1->Controls->Add(this->textBoxConfName);
			this->panel1->Controls->Add(this->labelConfName);
			this->panel1->Controls->Add(this->textBoxCity);
			this->panel1->Controls->Add(this->labelCity);
			this->panel1->Controls->Add(this->labelConfTheme);
			this->panel1->Controls->Add(this->textBoxConfTheme);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(245, 537);
			this->panel1->TabIndex = 0;
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->buttonFind->Location = System::Drawing::Point(3, 496);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(236, 38);
			this->buttonFind->TabIndex = 1;
			this->buttonFind->Text = L"Поиск";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &SearchForm::buttonFind_Click);
			// 
			// checkBoxConfFind
			// 
			this->checkBoxConfFind->AutoSize = true;
			this->checkBoxConfFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBoxConfFind->Location = System::Drawing::Point(8, 367);
			this->checkBoxConfFind->Name = L"checkBoxConfFind";
			this->checkBoxConfFind->Size = System::Drawing::Size(219, 28);
			this->checkBoxConfFind->TabIndex = 11;
			this->checkBoxConfFind->Text = L"Искать конференции";
			this->checkBoxConfFind->UseVisualStyleBackColor = true;
			// 
			// checkBoxScientistFind
			// 
			this->checkBoxScientistFind->AutoSize = true;
			this->checkBoxScientistFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->checkBoxScientistFind->Location = System::Drawing::Point(8, 333);
			this->checkBoxScientistFind->Name = L"checkBoxScientistFind";
			this->checkBoxScientistFind->Size = System::Drawing::Size(161, 28);
			this->checkBoxScientistFind->TabIndex = 1;
			this->checkBoxScientistFind->Text = L"Искать ученых";
			this->checkBoxScientistFind->UseVisualStyleBackColor = true;
			// 
			// textBoxDataEnd
			// 
			this->textBoxDataEnd->Location = System::Drawing::Point(8, 282);
			this->textBoxDataEnd->Name = L"textBoxDataEnd";
			this->textBoxDataEnd->Size = System::Drawing::Size(231, 20);
			this->textBoxDataEnd->TabIndex = 10;
			// 
			// textBoxDataStart
			// 
			this->textBoxDataStart->Location = System::Drawing::Point(8, 232);
			this->textBoxDataStart->Name = L"textBoxDataStart";
			this->textBoxDataStart->Size = System::Drawing::Size(231, 20);
			this->textBoxDataStart->TabIndex = 9;
			// 
			// labelDataEnd
			// 
			this->labelDataEnd->AutoSize = true;
			this->labelDataEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelDataEnd->Location = System::Drawing::Point(4, 255);
			this->labelDataEnd->Name = L"labelDataEnd";
			this->labelDataEnd->Size = System::Drawing::Size(202, 24);
			this->labelDataEnd->TabIndex = 8;
			this->labelDataEnd->Text = L"Дата начала периода";
			// 
			// labelDataStart
			// 
			this->labelDataStart->AutoSize = true;
			this->labelDataStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelDataStart->Location = System::Drawing::Point(4, 205);
			this->labelDataStart->Name = L"labelDataStart";
			this->labelDataStart->Size = System::Drawing::Size(202, 24);
			this->labelDataStart->TabIndex = 7;
			this->labelDataStart->Text = L"Дата начала периода";
			// 
			// textBoxScientistName
			// 
			this->textBoxScientistName->Location = System::Drawing::Point(8, 182);
			this->textBoxScientistName->Name = L"textBoxScientistName";
			this->textBoxScientistName->Size = System::Drawing::Size(231, 20);
			this->textBoxScientistName->TabIndex = 6;
			// 
			// labelScientistName
			// 
			this->labelScientistName->AutoSize = true;
			this->labelScientistName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelScientistName->Location = System::Drawing::Point(4, 155);
			this->labelScientistName->Name = L"labelScientistName";
			this->labelScientistName->Size = System::Drawing::Size(131, 24);
			this->labelScientistName->TabIndex = 5;
			this->labelScientistName->Text = L"ФИО ученого";
			// 
			// textBoxConfName
			// 
			this->textBoxConfName->Location = System::Drawing::Point(8, 132);
			this->textBoxConfName->Name = L"textBoxConfName";
			this->textBoxConfName->Size = System::Drawing::Size(231, 20);
			this->textBoxConfName->TabIndex = 4;
			// 
			// labelConfName
			// 
			this->labelConfName->AutoSize = true;
			this->labelConfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelConfName->Location = System::Drawing::Point(4, 105);
			this->labelConfName->Name = L"labelConfName";
			this->labelConfName->Size = System::Drawing::Size(224, 24);
			this->labelConfName->TabIndex = 3;
			this->labelConfName->Text = L"Название конференции";
			// 
			// textBoxCity
			// 
			this->textBoxCity->Location = System::Drawing::Point(8, 82);
			this->textBoxCity->Name = L"textBoxCity";
			this->textBoxCity->Size = System::Drawing::Size(231, 20);
			this->textBoxCity->TabIndex = 2;
			// 
			// labelCity
			// 
			this->labelCity->AutoSize = true;
			this->labelCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelCity->Location = System::Drawing::Point(4, 55);
			this->labelCity->Name = L"labelCity";
			this->labelCity->Size = System::Drawing::Size(66, 24);
			this->labelCity->TabIndex = 1;
			this->labelCity->Text = L"Город";
			// 
			// labelConfTheme
			// 
			this->labelConfTheme->AutoSize = true;
			this->labelConfTheme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->labelConfTheme->Location = System::Drawing::Point(4, 5);
			this->labelConfTheme->Name = L"labelConfTheme";
			this->labelConfTheme->Size = System::Drawing::Size(223, 24);
			this->labelConfTheme->TabIndex = 0;
			this->labelConfTheme->Text = L"Тематика конференции";
			// 
			// textBoxConfTheme
			// 
			this->textBoxConfTheme->Location = System::Drawing::Point(8, 32);
			this->textBoxConfTheme->Name = L"textBoxConfTheme";
			this->textBoxConfTheme->Size = System::Drawing::Size(231, 20);
			this->textBoxConfTheme->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(263, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(509, 537);
			this->panel2->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->Location = System::Drawing::Point(3, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(503, 483);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SearchForm::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// SearchForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"SearchForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SearchForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void buttonFind_Click(System::Object^  sender, System::EventArgs^  e) 
{
	String ^confName = this->textBoxConfName->Text;
	String ^city = this->textBoxCity->Text;
	String ^confTheme = this->textBoxConfTheme->Text;
	String ^DataStart = this->textBoxDataStart->Text;
	String ^DataEnd = this->textBoxDataEnd->Text;
	String ^ScientistName = this->textBoxScientistName->Text;

	//send search request
}

#pragma region Functions
private:

#pragma endregion Functions

private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	//Scientist
	if (this->checkBoxScientistFind->Checked)
	{
		this->Hide();
		scientistForm->ShowDialog();
		this->Show();
		this->Activate();
	}
	else if (this->checkBoxConfFind->Checked)
	{
		this->Hide();
		confForm->ShowDialog();
		this->Show();
		this->Activate();
	}
}
};
}
