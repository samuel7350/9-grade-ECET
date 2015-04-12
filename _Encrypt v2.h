#ifndef ENCRYPT
#define ENCRYPT

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
#pragma comment(lib, "winmm.lib")
#define SIZE 3
using namespace std;


#define SHOW_FILES() system("dir *.txt /b /o:-D")


vector<int> sizecheck(vector<int> test)
{ //FUNCTION (SIZE CHECK) START
	if (test.size() % 3 != 0)
		test.push_back(0);
	if (test.size() % 3 != 0)
		test.push_back(0);
	return test;
} //FUNCTION (SIZE CHECK) END


vector<int> Message()		//Function Definition
{ //FUNCTION (GET MESSAGE) START
	vector<int> a;			//New vector, not the same as the one in Ecrypt(), as it is in a different Scope
	std::string message = "";	//Makes Local String called message
	cout << "Please Enter the Message to Be Encrypted. \n";
	while (true)			//Infinite Loop, leave it with break
	{
		getline(cin, message);				//Asks for the message they want to encrypt
		if (!message.empty())
		{
			system("CLS");			//Clears Screen
			break;
		}
		else					//If theres no message, repeats from the top of the loop
		{
			continue;
		}
	}
	char choose;						//Local Char Choose
	int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to See a List of the Text Files in the Current Directory?", L"Text Files?", MB_YESNO);
	switch (result1)
	{
	case IDYES:
	{
		SHOW_FILES();
		int result2 = MessageBox(HWND_DESKTOP, L"Would you like to delete all these files?", L"DELETE", MB_YESNO);
		switch (result2)
		{
		case IDYES:
		{
			int result = MessageBox(HWND_DESKTOP, L"Are You SURE??", L"Confirmation", MB_YESNO | MB_ICONWARNING);
			switch (result)
			{
			case IDYES:
				string c = "del /Q ";
				string p = "*.txt";
				system(c.append(p).c_str());
				break;
			}
		}
		}
		break;
	}
	case IDNO:
	{
		int result = MessageBox(HWND_DESKTOP, L"Would You like to Clear the Current Folder of ALL Text Files?", L"DELETE", MB_YESNO);
		switch (result)
		{
			int result = MessageBox(HWND_DESKTOP, L"Are You SURE??", L"Confirmation", MB_YESNO | MB_ICONWARNING);
			switch (result)
			{
			case IDYES:
				string c = "del /Q ";
				string p = "*.txt";
				system(c.append(p).c_str());
				break;
			}
		}
	}
	}
	system("pause");
	while (true)		//Infinite Loop, Leave with breaks
	{
		system("COLOR 30");
		system("CLS");		//Clears Screen
		cout << "Please Enter the Desired Filename(Please Exclude the .txt at the end)\n[MAX LENGTH = 128]:\n----> ";
		getline(cin, filename);		//Getline allows for spaces, instead of traditional cin >>
		if (filename.length() == 0)
			getline(cin, filename);
		if (!checkvalid(filename))		//calls checkvalid on the filename
		{
			for (int x = 0; x<5; x++)
			{
				Sleep(250);
				cout << lightblue << "\rTHAT IS NOT VALID";
				Sleep(250);
				cout << lightred << "\rTHAT IS NOT VALID";
			}
			Sleep(1000);
			system("CLS");
			continue;
		}
		string directory;
		
		filename += ".txt";		//Adds .txt to end of string, since user was specified NOT to add .txt at end
		
		int result = MessageBox(HWND_DESKTOP, L"Would you like to pick a certain directory?", L"Confirmation", MB_YESNO | MB_ICONWARNING);
			switch (result)
			{
				case IDYES:
				{
					cout << "Enter the Specified Directory (Ex. C:\\Users\\Me)<---Please dont add the last \\\n----> ";
					getline(cin, directory);
					filename = directory + "\\" + filename;
					break;
				}

				case IDNO:
				{
					break;
				}
			}
		//If they did, it will look like filename.txt.txt
		if (!filename.empty())		//If the filename is not empty
		{
			system("CLS");		//Clears Screen
			cout << "Your File is: \n" << filename << endl;	//Shows User their inputted Filename
			cout << "And your Message is: \n" << message << endl;	//Along with the Message
			system("PAUSE");					//Pauses the Screen
			break;							//Leaves the Loop
		}
		else		//If the Message is empty
		{
			continue;	//Stay in the Loop
		}
	}

	for (int count = 0; count < message.length(); count++)
	{
		char y = message.at(count);		//takes each character of the message		
		a.push_back(static_cast<int>(y));	//Pushes it into a vector of Ints(using static cast)
	}
	a = sizecheck(a);				//Calls SizeCheck , and checks size of vector<int> a
	return a;					//Function Returns a
}  //FUNCTION (GET MESSAGE) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

void randKey(float key[SIZE][SIZE])	//Function Definition
{ //FUNCTION (GENERATE RANDOM KEY) START
	srand(time(0));			//"Changing" Seed, as Time is never constant

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			key[i][j] = rand() % 9 + 1;	//Key is assigned a random value, for every "square"

} //FUNCTION (GENERATE RANDOM KEY) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

void outputkey(ofstream& Stuff)		//Function Definition
{ //FUNCTION (WRITE KEY TO FILE) START	
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			Stuff << key[i][j];					//Outputs the Matrix into the Text File
} //FUNCTION (WRITE KEY TO FILE) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

ofstream createtxt()
{ //FUNCTION (MAKE TXT FILE) START
	//****************************************************
	ofstream Stuff;				//****			Makes The Text File
	Stuff.open(filename.c_str()); //****
	//****************************************************
	return Stuff;	//Returns Location of Stuff
} //FUNCTION (MAKE TXT FILE) END

void Encrypt()		//Function Definition
{ //FUNCTION (MAIN ENCRYPT) START
	randKey(key);							//Calls the RandKey Function
	vector<int> a = Message();					//Calls Message, returning value is stored in a

	remove(filename.c_str());					//Deletes the File if It Already Exists
	ofstream Stuff = createtxt();					//Calls createtxt, stored into the ofstream object
	outputkey(Stuff);						//Calls Outputkey, with the parameter of the Address of Stuff
	a = MatrixMultiply(key, a);					//A is overwritten, and is multiplied by the key before doing so
	Stuff << endl
		<< a 							//Vector is written into the textfile, no need to iterate due to the template
		<< endl;
	Stuff.close();							//Closes the File
} //FUNCTION (MAIN ENCRYPT) END











char betterMessage()		//Function Definition
{ //FUNCTION (GET MESSAGE) START

	



		
	char x=0;
	char *str = (char*) malloc(sizeof(char));// malloc length of str
	
	
	for(int size=0; true; size++)
	{
		x=getchar();

	

		str= (char*)realloc(str, sizeof(char)*size);

		
		if(str==NULL)
		{
			printf("MEMORY NOT ALLOCATED!!");
			free(str);
			exit(EXIT_FAILURE);
		}

		if(x=='\n')
		{
			*(str+size)='\0';
			break;
		}
		*(str+size)=x;

	}
	
	
	
	
	printf("%s\n",str);
	

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

#endif
