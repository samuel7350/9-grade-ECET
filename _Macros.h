#ifndef __MACRO__
#define __MACRO__

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
#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Misc.h"
//#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Encrypt.h"
#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Encrypt v2.h"
#include "C:\Users\Sam\Documents\GitHub\9-grade-ECET\_Decrypt.h"
#pragma comment(lib, "winmm.lib")
#define SIZE 3
using namespace std;


#define SHOW_FILES() system("dir *.txt /b /o:-D")



#define MAIN() 	int main()\
	{\
	do{\
	\
	intro();			\
	char choose;		\
	while (true)\
	{\
		cout << "Press CTRL + C at any time to exit the program.\n";\
		cout << "Would you like to Encrypt or Decrypt? \nE - Encrypt\nD - Decrypt\n\n";\
		cin >> choose;\
		getline(cin, sht);\
		\
		if (choose == 'e' || choose == 'E')\
		{\
			system("CLS");\
			Encrypt();		\
			int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Decrypt?", L"Decrypt?", MB_YESNO);\
			switch (result1)\
			{\
				case IDYES:\
				{\
					system("CLS");\
					Decrypt();		\
					break;\
				}\
			}\
			break;\
		}\
		if (choose == 'd' || choose == 'D')\
		{\
			system("CLS");\
			Decrypt();		\
			int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Encrypt?", L"Encrypt?", MB_YESNO);\
			switch (result1)\
			{\
				case IDYES:\
				{\
					system("CLS");\
					Encrypt();		\
					break;\
				}\
			}\
			break;\
		}\
		else\
		{\
			system("CLS");\
			cout << "PLEASE SELECT A VALID OPTION!!\n";\
			continue;\
		}\
	}\
	cout << "\t\t\tThank You For Using this program!\n";\
}while(0);\
}\


/*
//COMMENTS---------------------------------------------------------------------------------------------------------------------------
//int main
//{
//intro();				//Function Call of Intro
	//char choose;				//Variable that asks for choice
	//while (true)
	//{
	//	cout << "Press CTRL + C at any time to exit the program.\n";
	//	cout << "Would you like to Encrypt or Decrypt? \nE - Encrypt\nD - Decrypt\n\n";
	//	cin >> choose;
	//	getline(cin, sht);		//Anything that was entered after the letter does not overflow into the next cin
	//	//Instead goes into overflow
	//	if (choose == 'e' || choose == 'E')	//If they chose to Encrypt
	//	{
	//		system("CLS");
	//		Encrypt();			//Calls Encrypt
	//		int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Decrypt?", L"Decrypt?", MB_YESNO);
	//		switch (result1)
	//		{
	//			case IDYES:
	//			{
	//				system("CLS");
	//				Decrypt();			//Call Decrypt
	//				break;
	//			}
	//		}
	//		break;
	//	}
	//	if (choose == 'd' || choose == 'D')	//If they chose to Decrypt
	//	{
	//		system("CLS");
	//		Decrypt();			//Calls Decrypt
	//		int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Encrypt?", L"Encrypt?", MB_YESNO);
	//		switch (result1)
	//		{
	//			case IDYES:
	//			{
	//				system("CLS");
	//				Encrypt();			//Call Decrypt
	//				break;
	//			}
	//		}
	//		break;
	//	}
	//	else
	//	{
	//		system("CLS");
	//		cout << "PLEASE SELECT A VALID OPTION!!\n";
	//		continue;
	//	}
	//}
	//cout << "\t\t\tThank You For Using this program!\n";
	//}

*/








#define FUNCTIONS()
void randKey(float[SIZE][SIZE]);\
vector<int> Message();\
float determinant(float[SIZE][SIZE]);\
vector<float> inverse(float[SIZE][SIZE], int);\
void outputkey(ofstream&);\
ofstream createtxt();\
ifstream openfile();\
void Decrypt();\
vector<float> getkey(ifstream&);\
vector<int> MatrixMultiply(float[SIZE][SIZE], vector<int>);\
vector<int> sizecheck(vector<int>);\
vector<int> fetch(ifstream&);\
void Encrypt();\
void intro();\
int checkvalid(string);\
\
\
\
int main()\
	{\
	do{\
	\
	intro();			\
	char choose;		\
	while (true)\
	{\
		cout << "Press CTRL + C at any time to exit the program.\n";\
		cout << "Would you like to Encrypt or Decrypt? \nE - Encrypt\nD - Decrypt\n\n";\
		cin >> choose;\
		getline(cin, sht);\
		\
		if (choose == 'e' || choose == 'E')\
		{\
			system("CLS");\
			Encrypt();		\
			int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Decrypt?", L"Decrypt?", MB_YESNO);\
			switch (result1)\
			{\
				case IDYES:\
				{\
					system("CLS");\
					Decrypt();		\
					break;\
				}\
			}\
			break;\
		}\
		if (choose == 'd' || choose == 'D')\
		{\
			system("CLS");\
			Decrypt();		\
			int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to Encrypt?", L"Encrypt?", MB_YESNO);\
			switch (result1)\
			{\
				case IDYES:\
				{\
					system("CLS");\
					Encrypt();		\
					break;\
				}\
			}\
			break;\
		}\
		else\
		{\
			system("CLS");\
			cout << "PLEASE SELECT A VALID OPTION!!\n";\
			continue;\
		}\
	}\
	cout << "\t\t\tThank You For Using this program!\n";\
}while(0);\
}\

/*
void randKey(float[SIZE][SIZE]);									//Creates Random Key
vector<int> Message();												//Gets the Message, Stores it in a Vector
float determinant(float[SIZE][SIZE]);								//Calculates the Determinant
vector<float> inverse(float[SIZE][SIZE], int);						//Finds the Inverse Matrix of the Key
void outputkey(ofstream&);											//Writes the Key into the Txt File
ofstream createtxt();												//Makes the Text File
ifstream openfile();												//Opens the Specified Txt File
void Decrypt();														//Main Decrypt Function
vector<float> getkey(ifstream&);									//Gets Key from the File
vector<int> MatrixMultiply(float[SIZE][SIZE], vector<int>);			//Multiplies Matricies(For both Encrypt and Decrypt)	
vector<int> sizecheck(vector<int>);									//Checks if the Message is divisible by 3
vector<int> fetch(ifstream&);										//Gets the Message from Text File
void Encrypt();														//Main Encrypt Function
void intro();														//Introduction Screen
int checkvalid(string);
*/







#define FUNCTIONS_AND_MAIN()\
void randKey(float[SIZE][SIZE]);\
vector<int> Message();\
float determinant(float[SIZE][SIZE]);\
vector<float> inverse(float[SIZE][SIZE], int);\
void outputkey(ofstream&);\
ofstream createtxt();\
ifstream openfile();\
void Decrypt();\
vector<float> getkey(ifstream&);\
vector<int> MatrixMultiply(float[SIZE][SIZE], vector<int>);\
vector<int> sizecheck(vector<int>);\
vector<int> fetch(ifstream&);\
void Encrypt();\
void intro();\
int checkvalid(string);






#endif
