#ifndef DECRYPT
#define DECRYPT

#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <math.h>
#include <Windows.h>
#include <direct.h>
//#include "Misc.h"
#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Misc.h"
//#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Macros.h"
#include <sys/stat.h>
#pragma comment(lib, "winmm.lib")
#define SIZE 3
using namespace std;

#define SHOW_FILES() system("dir *.txt /b /o:-D")

string file;
float determinant(float key[SIZE][SIZE])	//Function Definition
{ //FUNCTION (DETERMINANT FINDER) START
	int det = 0;
	for (int i = 0; i < SIZE; i++)	//This is spaced out to be easily read, pretty much hard coded for only 3x3 matricies
	{
		det =
			det +
			(
			key[0][i] *
			(
			key[1][(i + 1) % SIZE] *
			key[2][(i + 2) % SIZE] -
			key[1][(i + 2) % SIZE] *
			key[2][(i + 1) % SIZE]
			)
			);
	}
	return det;			//Returns det value
} //FUNCTION (DETERMINANT FINDER) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************


ifstream openfile()
{ //FUNCTION (OPEN FILE FOR READ) START
	while(true)
	{
		cout << "Pick a directory (Ex. C:\\Users\\Me\\Cplusplus) <--- Dont add the last \\\nPress Enter to Continue with the Same Directory\n----> ";
		string directory;
		getline(cin, directory);
		struct stat dirtest;
		if (stat(directory.c_str(), &dirtest) == 0)
		{
			_chdir(directory.c_str());
			cout << "Here is a list of all the .txt files in the Directory.\n";
			if(system("dir *.txt /b"))
			{
				cout << "\nThis Directory has no Text Files Available,\nPick a different directory.\n";
				Sleep(1500);
				system("CLS");
				continue;
			}
			break;
		}
		else
		{
			if(directory.length() == 0)
			{
				cout << "Here is a list of all the .txt files in the Directory.\n";
				if(system("dir *.txt /b"))
				{
					cout << "\nThis Directory has no Text Files Available,\nPick a different directory.\n";
					Sleep(1500);
					system("CLS");
					continue;
				}
				break;
			}
			for (int x = 0; x < 5; x++)
			{
				Sleep(250);
				cout << lightblue << "\rPLEASE ENTER A VALID DIRECTORY!!";
				Sleep(250);
				cout << lightred << "\rPLEASE ENTER A VALID DIRECTORY!!";
			}
			system("CLS");
			system("COLOR 30");
			continue;
		}
	}
	cout << "\n";
	ifstream EncodedM;
	while (true)
	{
		cout << "Please Enter the FileName of your Encoded Text: ";
		getline(cin, file);
		if (file.length() == 0)
			getline(cin, file);
		EncodedM.open(file.c_str(), ifstream::in);
		if (file.length() == 0)
			continue;
		if (EncodedM.good())
			break;
		if (EncodedM.fail())
		{
			for (int x = 0; x<5; x++)
			{
				Sleep(250);
				cout << lightblue << "\rPLEASE ENTER A VALID FILENAME!!";
				Sleep(250);
				cout << lightred << "\rPLEASE ENTER A VALID FILENAME!!";
			}
			Sleep(1000);
			system("CLS");
			system("COLOR 30");
			cout << "Here is a list of all the .txt files in the Directory.\n";
			SHOW_FILES();
			cout << "\n";
			continue;
		}
	}	
	struct stat filestats;
	stat(file.c_str(), &filestats);
	cout << "Last status change:       " << ctime(&filestats.st_ctime);
    	cout << "Last file access:         " << ctime(&filestats.st_atime);
    	cout << "Last file modification:   " << ctime(&filestats.st_mtime);
	size_t filesize = filestats.st_size;
	cout << "File Size:                " << filesize << " Bytes\n"; 
	system("PAUSE");
	return EncodedM;
} //FUNCTION (OPEN FILE FOR READ) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<float> getkey(ifstream& EncodedM)
{ //FUNCTION (GET KEY) START
	char c = EncodedM.get();
	vector<float> a;
	a.push_back(int(c) - 48);
	while (EncodedM.good())
	{
		c = EncodedM.get();
		a.push_back(int(c) - 48);
		if (a.size() == 10)
			break;
	}
	a.erase(a.end() - 1, a.end());
	return a;
} //FUNCTION (GET KEY) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************


//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<int> fetch(ifstream& EncodedM)
{ //FUNCTION (FETCH ENCODED WORDS) START
	int a;
	vector<int> b;
	while (EncodedM >> a)
	{
		b.push_back(a);
	}
	return b;
} //FUNCTION (FETCH ENCODED WORDS) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************


vector<float> inverse(float k[SIZE][SIZE], float det)	//Function Definition
{ //FUNCTION (INVERSE) START
	vector<float> s;
	stringstream test;				//Can set precision of variable
	long double key[3][3];
	long double t[3][3] = { 0 };
	for (int i = 0; i < 3; i++)			//Transposes the current key
		for (int j = 0; j < 3; j++)
			key[i][j] = k[j][i];

	//These the Adjoints
	test << setprecision(100) << (key[1][1] * key[2][2]) - (key[2][1] * key[1][2]);
	test >> t[0][0];
	test.clear();
	test << setprecision(100) << -((key[1][0] * key[2][2]) - (key[2][0] * key[1][2]));
	test >> t[0][1];
	test.clear();
	test << setprecision(100) << (key[1][0] * key[2][1]) - (key[1][1] * key[2][0]);
	test >> t[0][2];
	test.clear();
	test << setprecision(100) << -((key[0][1] * key[2][2]) - (key[2][1] * key[0][2]));
	test >> t[1][0];
	test.clear();
	test << setprecision(100) << (key[0][0] * key[2][2]) - (key[2][0] * key[0][2]);
	test >> t[1][1];
	test.clear();
	test << setprecision(100) << -((key[0][0] * key[2][1]) - (key[2][0] * key[0][1]));
	test >> t[1][2];
	test.clear();
	test << setprecision(100) << (key[0][1] * key[1][2]) - (key[1][1] * key[0][2]);
	test >> t[2][0];
	test.clear();
	test << setprecision(100) << -((key[0][0] * key[1][2]) - (key[1][0] * key[0][2]));
	test >> t[2][1];
	test.clear();
	test << setprecision(100) << (key[0][0] * key[1][1]) - (key[1][0] * key[0][1]);
	test >> t[2][2];
	test.clear();
	//Here we multiply it by the reciprical of the determinant
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)				//Multiplies by 1/det (Since dividing by Det would be integer division)
		{
			test.clear();
			test << setprecision(100) << t[i][j] * (1 / det);
			test >> t[i][j];
			cout << t[i][j] << " ";
			s.push_back(t[i][j]);				//Pushes back the inverse into S
		}
		cout << endl;
	}
	return s;							//Returns s
} //FUNCTION (INVERSE) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

void Decrypt()
{ //FUNCTION (MAIN DECRYPT) START
	system("CLS");						//Clears Screen
	ifstream EncodedM = openfile();				//Calls openfile, stored into EncodedM
	vector<float> filekey;
	filekey = getkey(EncodedM);				//The Key is stored into vector filekey
	int a = 0;						//a is a temp counter
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			decryptkey[i][j] = filekey.at(j + a);	//Contents of the Vector are transfered to an Array
			//Since Function MatrixMultiply multiplies two arrays
		}
		a += 3;
	}
	float det = determinant(decryptkey);			//Calculates the Determinant, from the function determinant
	filekey.empty();					//Clears the remaining contents of fileke(if any)
	vector<int> fromfile;
	fromfile = fetch(EncodedM);				//Encoded Words are placed into vector fromfile
	cout << fromfile;					//Outputs fromfile, FOR DEBUGGING *TAKE OUT*
	vector<float> tempinv;
	tempinv = inverse(decryptkey, det);			//Temp inverse is found using the inverse function
	float inversekey[3][3];
	a = 0;							//a is again used as a counter
	system("CLS");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)			//tempinv is transfered to array
		{
			inversekey[i][j] = tempinv[a];
			a++;
		}
	}
	vector<int> answer;
	cout << "This is your message: \n";
	answer = MatrixMultiply(inversekey, fromfile);		//array is multiplied with the encoded words
	for (int i = 0; i < answer.size(); i++)
	{
		cout << static_cast<char>(answer[i]);		//answer is a vector of ints
		Sleep(200);
	}
	//Cast while we output makes them their corresponding ASCII characters
	cout << endl;
	/*
	int result1 = MessageBox(HWND_DESKTOP, L"DELETE ALL TRACES!!", L"", MB_YESNO);
	switch (result1)
	{
		case IDYES:
		{
			remove(file.c_str());
		}
	}
	*/
	int result1 = MessageBox(HWND_DESKTOP, L"Would You Like to Store This into a .txt File?", L"Text Files?", MB_YESNO);
	switch (result1)
	{
		case IDYES:
		{
			string sht;
			string file;
			cout << "Please Enter the Filename You would like to store it in(Without the \".txt\" at the end: ";
			getline(cin, sht);
			getline(cin, file);
			ofstream final;
			file += ".txt";
			final.open(file.c_str());
			for (int i = 0; i < answer.size(); i++)
				final << static_cast<char>(answer[i]);			//Again, Cast into characdters, then placed into a File
			cout << "DONE!\n";
			cout << "File Stored in: " << file << endl;
		}
	}
} //FUNCTION (MAIN DECRYPT) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

#endif
