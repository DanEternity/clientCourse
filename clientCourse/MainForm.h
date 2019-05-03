#pragma once
#include <iostream>

#include "MainHeader.h"

namespace clientCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		int accountType = 0;
		System::Collections::Generic::List<int> confs;

		MainForm(int accountType)
		{
			InitializeComponent();

			this->accountType = accountType;
		}

		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  profileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  myConfToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  messagesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^  mainProfile;
	private: System::Windows::Forms::Panel^  mainConf;
	private: System::Windows::Forms::Panel^  mainMessages;
	private: System::Windows::Forms::Panel^  mainSearch;
	private: System::Windows::Forms::Panel^  mainOptions;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  mainConfDataGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ConfName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myConfToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->messagesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainProfile = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mainConf = (gcnew System::Windows::Forms::Panel());
			this->mainConfDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->ConfName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->mainMessages = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mainSearch = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->mainOptions = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->mainProfile->SuspendLayout();
			this->mainConf->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainConfDataGrid))->BeginInit();
			this->mainMessages->SuspendLayout();
			this->mainSearch->SuspendLayout();
			this->mainOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->profileToolStripMenuItem,
					this->myConfToolStripMenuItem, this->messagesToolStripMenuItem, this->searchToolStripMenuItem, this->optionsToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(968, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// profileToolStripMenuItem
			// 
			this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
			this->profileToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->profileToolStripMenuItem->Text = L"Профиль";
			this->profileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::profileToolStripMenuItem_Click);
			// 
			// myConfToolStripMenuItem
			// 
			this->myConfToolStripMenuItem->Name = L"myConfToolStripMenuItem";
			this->myConfToolStripMenuItem->Size = System::Drawing::Size(123, 20);
			this->myConfToolStripMenuItem->Text = L"Мои конференции";
			this->myConfToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::myConfToolStripMenuItem_Click);
			// 
			// messagesToolStripMenuItem
			// 
			this->messagesToolStripMenuItem->Name = L"messagesToolStripMenuItem";
			this->messagesToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->messagesToolStripMenuItem->Text = L"Сообщения";
			this->messagesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::messagesToolStripMenuItem_Click);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->searchToolStripMenuItem->Text = L"Поиск";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::searchToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->optionsToolStripMenuItem->Text = L"Настройки";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::optionsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->exitToolStripMenuItem->Text = L"Выход";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// mainProfile
			// 
			this->mainProfile->Controls->Add(this->label1);
			this->mainProfile->Location = System::Drawing::Point(12, 27);
			this->mainProfile->Name = L"mainProfile";
			this->mainProfile->Size = System::Drawing::Size(460, 256);
			this->mainProfile->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Profile ///FIXME";
			// 
			// mainConf
			// 
			this->mainConf->Controls->Add(this->mainConfDataGrid);
			this->mainConf->Location = System::Drawing::Point(496, 27);
			this->mainConf->Name = L"mainConf";
			this->mainConf->Size = System::Drawing::Size(460, 256);
			this->mainConf->TabIndex = 2;
			// 
			// mainConfDataGrid
			// 
			this->mainConfDataGrid->AllowUserToAddRows = false;
			this->mainConfDataGrid->AllowUserToDeleteRows = false;
			this->mainConfDataGrid->AllowUserToResizeColumns = false;
			this->mainConfDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mainConfDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->ConfName });
			this->mainConfDataGrid->Location = System::Drawing::Point(3, 3);
			this->mainConfDataGrid->Name = L"mainConfDataGrid";
			this->mainConfDataGrid->ReadOnly = true;
			this->mainConfDataGrid->RowHeadersVisible = false;
			this->mainConfDataGrid->RowTemplate->ReadOnly = true;
			this->mainConfDataGrid->Size = System::Drawing::Size(454, 250);
			this->mainConfDataGrid->TabIndex = 0;
			this->mainConfDataGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::mainConfDataGrid_CellDoubleClick);
			// 
			// ConfName
			// 
			this->ConfName->HeaderText = L"НазваниеКонференции";
			this->ConfName->Name = L"ConfName";
			this->ConfName->ReadOnly = true;
			this->ConfName->Visible = false;
			// 
			// mainMessages
			// 
			this->mainMessages->Controls->Add(this->label2);
			this->mainMessages->Location = System::Drawing::Point(12, 289);
			this->mainMessages->Name = L"mainMessages";
			this->mainMessages->Size = System::Drawing::Size(460, 256);
			this->mainMessages->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Messages ///FIXME";
			// 
			// mainSearch
			// 
			this->mainSearch->Controls->Add(this->label4);
			this->mainSearch->Location = System::Drawing::Point(496, 289);
			this->mainSearch->Name = L"mainSearch";
			this->mainSearch->Size = System::Drawing::Size(460, 256);
			this->mainSearch->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Search ///FIXME";
			// 
			// mainOptions
			// 
			this->mainOptions->Controls->Add(this->label3);
			this->mainOptions->Location = System::Drawing::Point(12, 551);
			this->mainOptions->Name = L"mainOptions";
			this->mainOptions->Size = System::Drawing::Size(460, 256);
			this->mainOptions->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Options ///FIXME";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(968, 741);
			this->Controls->Add(this->mainOptions);
			this->Controls->Add(this->mainSearch);
			this->Controls->Add(this->mainMessages);
			this->Controls->Add(this->mainConf);
			this->Controls->Add(this->mainProfile);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->mainProfile->ResumeLayout(false);
			this->mainProfile->PerformLayout();
			this->mainConf->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainConfDataGrid))->EndInit();
			this->mainMessages->ResumeLayout(false);
			this->mainMessages->PerformLayout();
			this->mainSearch->ResumeLayout(false);
			this->mainSearch->PerformLayout();
			this->mainOptions->ResumeLayout(false);
			this->mainOptions->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/*
REASONABLE FUNCTIONS
*/

	private: void setPanelActive(System::Windows::Forms::Panel ^p)
	{
		p->BringToFront();

		panelSetColorDef();
		panelSetColor(p, Color::Purple);
	}

/*
REASONABLE FUNCTIONS END
*/

/*
DEBUG FUNCTIONS
*/
	private: void panelSetColorDef()
	{
		mainProfile->BackColor = Color::White;
		mainConf->BackColor = Color::White;
		mainMessages->BackColor = Color::White;
		mainSearch->BackColor = Color::White;
		mainOptions->BackColor = Color::White;
	}

	private: void panelSetColor(System::Windows::Forms::Panel ^p, Color color)
	{
		p->BackColor = color;
	}

/*
DEBUG FUNCTIONS END
*/

	private: System::Void profileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setPanelActive(mainProfile);
	}

//MY_CONF_FUNCTIONS
	private: System::Void myConfToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setPanelActive(mainConf);
	}

	//Conf cell double click
	private: System::Void mainConfDataGrid_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{

	}
//MY_CONF_FUNCTIONS END

	private: System::Void messagesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setPanelActive(mainMessages);
	}

	private: System::Void searchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setPanelActive(mainSearch);
	}

	private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setPanelActive(mainOptions);
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		exit(0);
	}
};
}