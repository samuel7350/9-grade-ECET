#pragma once
#include <iostream>
#include <fstream>
#include <vector>

namespace Testsss {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: AxAcroPDFLib::AxAcroPDF^  axAcroPDF1;
	private: System::Windows::Forms::Button^  button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->axAcroPDF1 = (gcnew AxAcroPDFLib::AxAcroPDF());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axAcroPDF1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F));
			this->button1->ForeColor = System::Drawing::Color::Indigo;
			this->button1->Location = System::Drawing::Point(40, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Encrypt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(556, 404);
			this->progressBar1->Maximum = 1000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(435, 65);
			this->progressBar1->TabIndex = 1;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Form1::progressBar1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(125, 440);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(218, 29);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Indigo;
			this->button2->Location = System::Drawing::Point(304, 361);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 52);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Decrypt";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(196, 486);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(2);
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"EXIT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// axAcroPDF1
			// 
			this->axAcroPDF1->Enabled = true;
			this->axAcroPDF1->Location = System::Drawing::Point(522, 12);
			this->axAcroPDF1->Name = L"axAcroPDF1";
			this->axAcroPDF1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"axAcroPDF1.OcxState")));
			this->axAcroPDF1->Size = System::Drawing::Size(490, 597);
			this->axAcroPDF1->TabIndex = 5;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(161, 527);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(135, 39);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Open PDF";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 621);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->axAcroPDF1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axAcroPDF1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
				 ;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 progressBar1 -> Value = 0;
				 for(float i = 0; i < 1000; i++)
				 {
					 progressBar1 -> Value = i;												//Moves the Progress Bar
					 textBox1 -> Text = "We're Starting the console...";					//Accesses the Text of the Textbox
				 }
				 String^ CoolRun = "C:\\Whatever\\MakeExe.bat"			//Change If we do One File
				 Process::Start(CoolRun);
				 String ^ FilePath = "C:\\Whatever\\Encrypt.exe";		
				 Process::Start(FilePath);					//Starts the Process ^^^^^
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				using namespace std;
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				MessageBox::Show("The Program Will Now Close.");
				Form1::Close();					//Closes the Form
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 OpenFileDialog ^ Openfile1 = gcnew OpenFileDialog;
				 Openfile1 -> ShowDialog();
				 axAcroPDF1 -> src = Openfile1 -> FileName;

		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			progressBar1 -> Value = 0;
			for(float i = 0; i < 1000; i++)
			{
				progressBar1 -> Value = i;												//Moves the Progress Bar
				textBox1 -> Text = "We're Starting the console...";					//Accesses the Text of the Textbox
			}
			String^ CoolRun = "C:\\Whatever\\MakeExe2.bat"			//Change If we do One File
			Process::Start(CoolRun);
			String ^ FilePath = "C:\\Whatever\\Decrypt.exe";		
			Process::Start(FilePath);					//Starts the Process ^^^^^
		 }
};
}

