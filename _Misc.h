#ifndef MISC
#define MISC
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
#pragma comment(lib, "winmm.lib")
#define SIZE 3
using namespace std;






template <typename T>
ostream & operator << (ostream &out, const vector<T> &v)
{
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); i++)
	{
		out << v[i];
		if (i != last)
			out << endl;				//Use this to change what is between the Vectors (between the double quotes) Right now its 1 space between each value
	}
	return out;
}


float key[SIZE][SIZE];					//Global - We Need these Keys Everywhere
float decryptkey[3][3];
string filename = "";					//Need this For a lot too
stringstream overflow;					//Takes in all Overflow
//Will output to tell them all the unnecessary stuff they entered
string sht;						//Does nothing
//Main Below


enum COLORS								//Just Color Names
{
	black,
	blue,
	green,
	cyan,
	red,
	magenta,
	brown,
	normal,
	darkgrey,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightmagenta,
	yellow,
	white
};
/*********************************************************************/
//Prints Different Colors upon call
//example
//cout << colorname << variable/text;
/*********************************************************************/



ostream& operator << (ostream &textcolor, const COLORS &Color)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);			//Found on Google, to be honest
	SetConsoleTextAttribute(out, Color);				//Included in Windows.h
	return(textcolor);							//returns the name, evertime, cout is called
	//changes the test color to whatevr name was called
}

/*********************************************************************/

void intro()
{ //FUNCTION (INTRO) START
	//Each system("COLOR __") changes Foreground and Background colors
	system("mode 650");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);			//Maximizes the console to fit the screen
	PlaySound(TEXT("GetLowRemix.wav"), NULL, SND_ASYNC);		//Plays Music
	system("Color 1B");
	Sleep(500);
	system("CLS");
	cout << "\n\t\t\t\tThe Matrix Machine";
	system("Color 2D");
	Sleep(500);
	system("CLS");
	cout << "\n\n\t\t\t\tThe Matrix Machine";
	system("Color 3E");
	Sleep(500);
	system("CLS");
	cout << "\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 4F");
	Sleep(500);
	system("CLS");
	cout << "\n\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 5A");
	Sleep(500);
	system("CLS");
	cout << "\n\n\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 1C");
	Sleep(500);


	string name="Abhishek  Patel";




	system("CLS");
	system("COLOR 81");
	cout << "\n\n\n\n\n\n\t\t\t\tThe Matrix Machine\n";
	Sleep(500);
	system("COLOR A7");
	cout << lightmagenta << "\t\t\t\t  ";
	for(int x=0; x<name.size(); x++)
	{
	cout << name.at(x);
	Sleep(200);
	}
		cout << "\n";
	Sleep(500);
	system("COLOR FA");
	cout << white << "\t\t\t\t   ";
	name="Samuel Carlos";
	for(int x=0; x<name.size(); x++)
	{
	cout << name.at(x);
	Sleep(200);
	}
		cout << "\n";
	Sleep(500);
	system("COLOR B3");
	cout << lightred << "\t\t\t\t    ";
	name="Julie Pirro";
	for(int x=0; x<name.size(); x++)
	{
	cout << name.at(x);
	Sleep(200);
	}
		cout << "\n";
	Sleep(500);
	system("COLOR 30");
} //FUNCTION (INTRO) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************



int checkvalid(string filename)		//Makes sure the filename is valid (does not have special characters)
{
	for (int i = 0; i < filename.length(); i++)
	{
		if  (
			filename.at(i) == '\\'|| 
			filename.at(i) == '/' || 
			filename.at(i) == '*' || 
			filename.at(i) == '?' || 
			filename.at(i) == '"' || 
			filename.at(i) == '<' || 
			filename.at(i) == '>' || 
			filename.at(i) == '|' ||
			filename.size() > 128
			)
		{
			return 0;
		}
	}
	return 1;
}


vector<int> MatrixMultiply(float key[3][3], vector<int> before)
{ //FUNCTION (MULTIPLY MATRICES) START
	float total = 0;
	vector<int> after;

	while (before.size() != 0)
	{
		int q = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				total += (key[i][k] * before[q]);  //mulitplies Key by matrix W
				q++;
			}
			int rounded = floor(total + 0.5);
			//total oushed back into after
			//although its not really a matrix yet.
			after.push_back(rounded);

			total = 0;
			q = 0;
		}
		total = 0;
		before.erase(before.begin(), before.begin() + 3);
	}
	return after;
} //FUNCTION (MULTIPLY MATRICES) END



void displaytxtfiles()
{
	
	system("dir *.txt /b /o:-D");// sorts by date
	//credit to http://ss64.com/nt/dir.html for explanation of parameters
	return;

}




#endif
