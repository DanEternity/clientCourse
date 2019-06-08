#pragma once
#include <iostream>

#include "Network.h"

#include "SearchForm.h"
#include "MessageManagerForm.h"
#include "ConfManagerForm.h"
#include "ProfileForm.h"

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
		SearchForm ^searchForm;
		MessageManagerForm ^messageManagerForm;
		ConfManagerForm ^confManagerForm;
		ProfileForm ^profileForm;
		unsigned __int64 q = 0;

	private: System::Windows::Forms::Button^  buttonProfile;
	private: System::Windows::Forms::Button^  buttonConf;
	private: System::Windows::Forms::Button^  buttonMessages;
	private: System::Windows::Forms::Button^  buttonSearch;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::Timer^  timer1;
	public: System::Collections::Generic::List<int> confs;

	public: MainForm(int accountType)
		{
			InitializeComponent();

			this->accountType = accountType;

			//searchForm = gcnew SearchForm(accountType);
			//profileForm = gcnew ProfileForm(accountType);

			if (accountType == ACCOUNT_TYPE_ADMINISTRATOR)
			{
				this->messagesToolStripMenuItem->Available = false;
				this->buttonMessages->Hide();

				int sizeX = 255;
				int sizeY = 262;
				int offsetX = 5;
				int offsetY = 5;

				this->buttonProfile->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonProfile->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 0, 27 + (sizeY + offsetY) * 0);

				this->buttonConf->Size = System::Drawing::Size(sizeX + offsetX + sizeX, sizeY);
				this->buttonConf->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 1, 27 + (sizeY + offsetY) * 0);

				this->buttonSearch->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonSearch->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 0, 27 + (sizeY + offsetY) * 1);

				this->buttonSettings->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonSettings->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 1, 27 + (sizeY + offsetY) * 1);

				this->buttonExit->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonExit->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 2, 27 + (sizeY + offsetY) * 1);
			}
			else if (accountType == ACCOUNT_TYPE_SCIENTIST)
			{
				int sizeX = 255;
				int sizeY = 262;
				int offsetX = 5;
				int offsetY = 5;

				this->buttonProfile->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonProfile->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 0, 27 + (sizeY + offsetY) * 0);

				this->buttonConf->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonConf->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 1, 27 + (sizeY + offsetY) * 0);

				this->buttonMessages->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonMessages->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 2, 27 + (sizeY + offsetY) * 0);

				this->buttonSearch->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonSearch->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 0, 27 + (sizeY + offsetY) * 1);

				this->buttonSettings->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonSettings->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 1, 27 + (sizeY + offsetY) * 1);

				this->buttonExit->Size = System::Drawing::Size(sizeX, sizeY);
				this->buttonExit->Location = System::Drawing::Point(3 + (sizeX + offsetX) * 2, 27 + (sizeY + offsetY) * 1);
			}

			this->timer1->Start();
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
	private: System::Windows::Forms::ToolStripMenuItem^  profileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  myConfToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  messagesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myConfToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->messagesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonProfile = (gcnew System::Windows::Forms::Button());
			this->buttonConf = (gcnew System::Windows::Forms::Button());
			this->buttonMessages = (gcnew System::Windows::Forms::Button());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
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
			// buttonProfile
			// 
			this->buttonProfile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonProfile->Location = System::Drawing::Point(12, 27);
			this->buttonProfile->Name = L"buttonProfile";
			this->buttonProfile->Size = System::Drawing::Size(209, 244);
			this->buttonProfile->TabIndex = 3;
			this->buttonProfile->Text = L"Профиль";
			this->buttonProfile->UseVisualStyleBackColor = true;
			this->buttonProfile->Click += gcnew System::EventHandler(this, &MainForm::buttonProfile_Click);
			// 
			// buttonConf
			// 
			this->buttonConf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonConf->Location = System::Drawing::Point(227, 27);
			this->buttonConf->Name = L"buttonConf";
			this->buttonConf->Size = System::Drawing::Size(281, 196);
			this->buttonConf->TabIndex = 4;
			this->buttonConf->Text = L"Конференции";
			this->buttonConf->UseVisualStyleBackColor = true;
			this->buttonConf->Click += gcnew System::EventHandler(this, &MainForm::buttonConf_Click);
			// 
			// buttonMessages
			// 
			this->buttonMessages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonMessages->Location = System::Drawing::Point(12, 277);
			this->buttonMessages->Name = L"buttonMessages";
			this->buttonMessages->Size = System::Drawing::Size(209, 272);
			this->buttonMessages->TabIndex = 5;
			this->buttonMessages->Text = L"Сообщения";
			this->buttonMessages->UseVisualStyleBackColor = true;
			this->buttonMessages->Click += gcnew System::EventHandler(this, &MainForm::buttonMessages_Click);
			// 
			// buttonSearch
			// 
			this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonSearch->Location = System::Drawing::Point(227, 229);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(281, 196);
			this->buttonSearch->TabIndex = 6;
			this->buttonSearch->Text = L"Поиск";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &MainForm::buttonSearch_Click);
			// 
			// buttonSettings
			// 
			this->buttonSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonSettings->Location = System::Drawing::Point(514, 27);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(258, 282);
			this->buttonSettings->TabIndex = 7;
			this->buttonSettings->Text = L"Настройки";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &MainForm::buttonSettings_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->buttonExit->Location = System::Drawing::Point(514, 315);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(258, 234);
			this->buttonExit->TabIndex = 8;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MainForm::buttonExit_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonSettings);
			this->Controls->Add(this->buttonSearch);
			this->Controls->Add(this->buttonMessages);
			this->Controls->Add(this->buttonConf);
			this->Controls->Add(this->buttonProfile);
			this->Controls->Add(this->menuStrip1);
			this->Location = System::Drawing::Point(200, 50);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Reasonable Functions
	private: void setButtonActive(System::Windows::Forms::Button ^p)
	{
		buttonSetColorDef();
		buttonSetColor(p, Color::Purple);
	}

#pragma endregion

#pragma region Debug Functions

	private: void buttonSetColorDef()
	{
		this->buttonConf->BackColor = Color::White;
		this->buttonExit->BackColor = Color::White; 
		this->buttonMessages->BackColor = Color::White;
		this->buttonProfile->BackColor = Color::White;
		this->buttonSettings->BackColor = Color::White;
		this->buttonSearch->BackColor = Color::White;
	}

	private: void buttonSetColor(System::Windows::Forms::Button ^p, Color color)
	{
		p->BackColor = color;
	}

#pragma endregion

	private: System::Void profileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setButtonActive(this->buttonProfile);

		this->Hide();
		profileForm->ShowDialog();
		this->Show();
		this->Activate();
	}

	private: System::Void myConfToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setButtonActive(this->buttonConf);

		confManagerForm = gcnew ConfManagerForm(accountType);
		this->Hide();
		confManagerForm->ShowDialog();
		this->Show();
		this->Activate();
	}

	private: System::Void messagesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setButtonActive(this->buttonMessages);

		this->Hide();
		messageManagerForm->ShowDialog();
		this->Show();
		this->Activate();
	}

	private: System::Void searchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setButtonActive(this->buttonSearch);

		this->Hide();
		searchForm->ShowDialog();
		this->Show();
		this->Activate();
	}

	private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setButtonActive(this->buttonSettings);
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		exit(0);
	}

#pragma region Buttons
//Профиль
private: System::Void buttonProfile_Click(System::Object^  sender, System::EventArgs^  e) 
{
	setButtonActive(this->buttonProfile);

	this->Hide();
	profileForm->ShowDialog();
	this->Show();
	this->Activate();
}

//Конференции
private: System::Void buttonConf_Click(System::Object^  sender, System::EventArgs^  e) 
{
	setButtonActive(this->buttonConf);

	this->confManagerForm = gcnew ConfManagerForm(accountType);
	this->Hide();
	confManagerForm->ShowDialog();
	this->Show();
	this->Activate();

	delete confManagerForm;
}

//Настройки
private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) 
{
	setButtonActive(this->buttonSettings);
}

//Сообщения
private: System::Void buttonMessages_Click(System::Object^  sender, System::EventArgs^  e) 
{
	setButtonActive(this->buttonMessages);

	this->messageManagerForm = gcnew MessageManagerForm(accountType);

	this->Hide();
	messageManagerForm->ShowDialog();
	this->Show();
	this->Activate();

	delete messageManagerForm;
}

//Поиск
private: System::Void buttonSearch_Click(System::Object^  sender, System::EventArgs^  e) 
{
	setButtonActive(this->buttonSearch);

	this->searchForm = gcnew SearchForm(accountType);

	this->Hide();
	searchForm->ShowDialog();
	this->Show();
	this->Activate();

	delete searchForm;
}

//Выход
private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	exit(0);
}
#pragma endregion Buttons

//timer
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	//std::cout << "MainFormTimerUpdate " << this->q << std::endl;
	//q++;
	UpdateSocket(_socket);
}
};
}