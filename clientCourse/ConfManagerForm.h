#pragma once

#include "MainHeader.h"

#include "ConfForm.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ConfManagerForm
	/// </summary>
	public ref class ConfManagerForm : public System::Windows::Forms::Form
	{
	public: int accountType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	public:
	public: ConfForm ^ confForm;

	public: ConfManagerForm(int accountType)
		{
			InitializeComponent();
			
			confForm = gcnew ConfForm(accountType);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ConfManagerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(760, 537);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ConfManagerForm::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// ConfManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->dataGridView1);
			this->Location = System::Drawing::Point(200, 50);
			this->Name = L"ConfManagerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConfManagerForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

//Cell double Click
private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	this->Hide();
	confForm->ShowDialog();
	this->Show();
	this->Activate();
}
};
}
