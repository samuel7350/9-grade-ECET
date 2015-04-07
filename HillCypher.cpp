#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "stdlib.h"
#include <vector>
#include <string>
#include <ctime>
using namespace std;
/*
**********************************************************************************************************************
*/

template <typename T>
ostream & operator << (ostream &out, const vector<T> &v)
{
size_t last = v.size() - 1;
for(size_t i = 0; i < v.size(); i++)
{
out << v[i];
if (i != last)
out << " ";				//Use this to change what is between the Vectors (between the double quotes) Right now its 1 space between each value
}
return out;
}

char choose;
char decrypt;
char y = 'i';
int key[3][3] =
{
{0,0,0},
{0,0,0},
{0,0,0}
};
int ctr = 8;
int b[3][3];
char again;
int sizeofarr = 9;
int det;
int counter = 0;
string message = "";
string filename = "";
string TempEncrypt = "";
string randfilename = "";
vector<int> myVector;
static const char randstring[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

int str = sizeof(randstring) - 1;
/*
**********************************************************************************************************************
*/
char genrand()  // Random string generator function.
{
    return randstring[rand() % str];
}
void Transpose()
{
	for(int i=0;i<3;i++) 
	{ 
		for(int j=0;j<3;j++) 
		{ 
			b[i][j] = key[j][i]; 
		} 
	}
}
void CoFactor()
{

}
void Determinant()
{
	/*
    int total2 = 1;
    int total3 = 1;
    total2 = key[0][0] * key[1][1] * key[2][2];
    total3 = key[0][2] * key[1][1] * key[2][0];
    cout << total2 << endl;
    cout << total3 << endl;
    cout << total2 - total3 << endl;
	*/
	det = 0;
	for(int i=0;i<3;i++)
	 {
	  det = det + (key[0][i] * (key [1][(i + 1) % 3] * key[2][(i + 2) % 3] - key[1][(i + 2) % 3] * key[2][(i + 1) % 3]));
	  cout << det << endl;
	 }
}
void Inverse()
{
	/*
        temp[0] = key[1][1] * key[2][2] - key[1][2] * key[2][1];
        temp[1] = key[1][2] * key[2][0] - key[1][0] * key[2][2];
        temp[2] = key[1][0] * key[2][1] - key[1][1] * key[2][0];
        temp[3] = key[0][2] * key[2][1] - key[0][1] * key[2][2];
        temp[4] = key[0][0] * key[2][2] - key[0][2] * key[2][0];
        temp[5] = key[0][1] * key[2][0] - key[0][0] * key[2][1];
        temp[6] = key[0][1] * key[1][2] - key[0][2] * key[1][1];
        temp[7] = key[0][2] * key[1][0] - key[0][0] * key[1][2];
        temp[8] = key[0][0] * key[1][1] - key[0][1] * key[1][0];
		for(int i = 0; i < 9; i++)
				cout << temp[i] << endl;
		int k = 0;
		int g = 0;
				for (int i = 0; i < 3; i++)
					{
						inverse[k+0][g+0] = temp[i+0] / 3;
						cout << inverse[k][g];
						system("pause");
						inverse[k+1][g+1] = temp[i+3] / 3;
						inverse[k+2][g+2] = temp[i+6] / 3;
						k = k + 3;
						g = g + 3;
					}
				for(int i = 0; i < 3; i++)
				{
					for(int j; j < 3; j++)
					{
						cout << inverse[i][j] << "  ";
					}
					cout << endl;
				}
				cout << endl;
				system("Pause");
				*/
	//Not werking so far....:(
}
void Message()
{
	vector<int> myVector;
	string message;
	cout << "Please Enter the Message to Be Decrypted. \n";
	getline(cin, message);								//Asks for the message they want to encrypt
	cout << randfilename << endl;
				if(!message.empty())
				{
					cout << "Your Message is: \n" << message << endl << endl;
					cout << "This is your Encrypted FileName! Please Keep it for Decryption!\n";
					cout << randfilename << endl << endl;
				}
				else
				{
					getline(cin, message);
					cout << "Your Message is: \n" << message << endl << endl;
					cout << "This is your Encrypted FileName! Please Keep it for Decryption!\n";
					cout << randfilename << endl << endl;
				}
	for (int count = 0; count < message.length(); count++)   //takes each character of the message
	{
		char y = message.at(count);
		myVector.push_back(static_cast<int>(y));
	}
			cout << "The vector is: " << endl;
			
		/*	for (int i = 0; i < myVector.size(); i++){	//outputs the vector and the stuff inside
				cout << myVector[i] << " " << endl;
			}
		*/
			cout << myVector << endl;			//This works too cause of the template
	while (myVector.size() % 3 != 0){	
		myVector.push_back(32);   
	}
}

void MatrixMultiplication() //i need the code for the conversion of the message
                            //in order to run the multiplication as many times needed
{
    int i, j, k, count = 0, total = 0;       // i = rows, j = columns
	int W[3][1];
	for (i = 0; i < 3; i++)
	{

		for (k = 0; k < 3; k++)
		{
			total += key[i][k] * W[k][1];  //mulitplies Key by matrix W
		}
		cout << setw(4) << total << " "; //total displays the product in 3x1 matrix,
		++count;						 //although its not really a matrix yet.
		cout << endl;
		total = 0;
	}
}


void Decrypt()
{
	char delet;
	cout << "\nThis is a list of all txt files in the directory\n";
	system("dir *.txt /a-d /b");
	cout << "Would you like to delete all files in the current folder?";
	cin >> delet;
	if(toupper(delet) == 'Y')
	{
		string c = "del /Q ";
		string p = "*.txt";
		system(c.append(p).c_str());
	}
	//^^^ Havent tried it out, should work
	//made c and p string because you need strings for append
    cout << "\nPlease enter the filename of the encrypted message: ";
    cin >> filename;
    cout << "The Filename you Entered is: " << filename << endl;
    ifstream EncryptedMessage;
    EncryptedMessage.open(filename.c_str());
        while(!EncryptedMessage.eof())                  //Makes sure all lines are scanned
        {
            getline(EncryptedMessage, TempEncrypt);     //Fetches the Lines of the Message file
            cout << TempEncrypt;                        //Prints the Message
        }
        /*    cout << "\n" << "is This Your Message? (Y/N)";	//Checks validation if message
            cin >> again;
            if (again == 'y' || again == 'Y')
                break;
            else					//If its not the message, they can do something else
                {
                cin >> filename;
                EncryptedMessage.open("filename");	//Not finalized yet
                continue;
                }
        */
        string temp2 = TempEncrypt.substr(0, 16);
		cout << temp2 << endl;					//For Debugging (Should Show the Key (9 Numbers))
		TempEncrypt.erase(TempEncrypt.begin(), TempEncrypt.begin()+16);	//Erases the key after it is transfered to temp2
		cout << TempEncrypt << endl;			//Whats left in the file (For Debugging)
        EncryptedMessage.close();				//Closes the file
        system("Pause");
}
void Encrypt()
{
		srand(time(0));
		string randfilename;
		while(ctr > 0)
		{
		randfilename+= genrand();					//Generates Random 8 Element String(For Filename)
		--ctr;
		}
		randfilename+= ".txt";	                //Adds .txt to end of string
		cout << randfilename << endl;
		ofstream Stuff;							//WHATEVER NEEDS TO GO IN THE TXT REPLACE COUT WITH STUFF
		Stuff.open(randfilename.c_str(), ios::app);
		while(true)
		{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				int s;
				s = rand() % 9 + 1;
				key[i][j] = s;
			}
		}
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout << key[i][j]  << "  ";
				Stuff << key[i][j] << "  ";
			}
			cout << endl;
			Stuff << endl;
		}
		Determinant();
		system("pause");
		cout << det << endl;
		system("pause");
		if(det != 0)
			break;
		else
			continue;
		}
	//Inverse();							//Not Working.....YET
	Message();
	system("pause");
}
int main()
{
    Encrypt();
	Decrypt();
}










//This is for the GUI
/*
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
			this->button1->Location = System::Drawing::Point(80, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
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
			this->textBox1->Location = System::Drawing::Point(136, 379);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(218, 29);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(339, 328);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Decrypt";
			this->button2->UseVisualStyleBackColor = true;
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
				 for(float i = 0; i < 1000; i++)
				 {
				 progressBar1 -> Value = i;												//Moves the Progress Bar
				 textBox1 -> Text = "We're Starting the console...";					//Accesses the Text of the Textbox
				 }
				 String ^ FilePath = "C:\\Users\\Abhi\\Documents\\Visual Studio 2010\\Projects\\Cryptography\\Cryptography\\Files.exe";		
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
};
}

*/
