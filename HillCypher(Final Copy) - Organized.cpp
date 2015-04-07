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
#define SIZE 3
using namespace std;

/*
*********************************************************************************************************************************************
*/

void randKey(float [SIZE][SIZE]);					//Creates Random Key
vector<int> Message();							//Gets the Message, Stores it in a Vector
float determinant(float [SIZE][SIZE]);					//Calculates the Determinant
vector<float> inverse(float [SIZE][SIZE], int);				//Finds the Inverse Matrix of the Key
void outputkey(ofstream&);						//Writes the Key into the Txt File
ofstream createtxt();							//Makes the Text File
ifstream openfile();							//Opens the Specified Txt File
void Decrypt();								//Main Decrypt Function
vector<float> getkey(ifstream&);					//Gets Key from the File
vector<int> MatrixMultiply(float [SIZE][SIZE], vector<int>);		//Multiplies Matricies(For both Encrypt and Decrypt)	
vector<int> sizecheck(vector<int>);					//Checks if the Message is divisible by 3
vector<int> fetch(ifstream&);						//Gets the Message from Text File
void Encrypt();								//Main Encrypt Function
void intro();								//Introduction Screen
int checkvalid(string);
//TEMPLATE FOR OUTPUTTING VECTORS
/*********************************************************************/



template <typename T>
ostream & operator << (ostream &out, const vector<T> &v)
{
	size_t last = v.size() - 1;
	for(size_t i = 0; i < v.size(); i++)
	{
		out << v[i];
		if (i != last)
		out << endl;				//Use this to change what is between the Vectors (between the double quotes) Right now its 1 space between each value
	}
	return out;
}



//Prints Different Colors upon call
//example
//cout << colorname << variable/text;
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



ostream& operator << (ostream &textcolor, const COLORS &Color)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);			//Found on Google, to be honest
    SetConsoleTextAttribute(out, Color);				//Included in Windows.h
    return(textcolor);							//returns the name, evertime, cout is called
    									//changes the test color to whatevr name was called
}

/*********************************************************************/



float key[SIZE][SIZE];					//Global - We Need these Keys Everywhere
float decryptkey[3][3];
string filename = "";					//Need this For a lot too
stringstream overflow;					//Takes in all Overflow
							//Will output to tell them all the unnecessary stuff they entered
string sht;						//Does nothing
//Main Below

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

int main()
{ //Main
	intro();				//Function Call of Intro
	char choose;				//Variable that asks for choice
	cout << "Would you like to Encrypt or Decrypt? \nE - Encrypt\nD - Decrypt\n\t\t\t\t\t";
	cin >> choose;
	overflow << getline(cin, sht);		//Anything that was entered after the letter does not overflow into the next cin
						//Instead goes into overflow
	if(choose == 'e' || choose == 'E')	//If they chose to Encrypt
	{
		Encrypt();			//Calls Encrypt
		cout << "Would You Like to Decrypt?\n";
		cin >> choose;			//Same Variable, Overwritten by this Cin
		overflow << getline(cin, sht);  //Extra is overflowed into StringStream
		if(choose == 'y' || choose == 'Y')	//If they Wanted to Decrypt
			Decrypt();			//Call Decrypt
	}
	if(choose == 'd' || choose == 'D')	//If they chose to Decrypt
	{
		Decrypt();			//Calls Decrypt
		cout << "Would You Like to Encrypt?\n";
		cin >> choose;			//Same Variable, Overwritten by this Cin
		overflow << getline(cin, sht);  //Extra is overflowed into StringStream
		if(choose == 'y' || choose == 'Y')	//If they wanted to Encrypt
			Encrypt();			//Call Encrypt
	}
	cout << overflow;
} //Main

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

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

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<int> Message()		//Function Definition
{ //FUNCTION (GET MESSAGE) START
	vector<int> a;			//New vector, not the same as the one in Ecrypt(), as it is in a different Scope
	std::string message = "";	//Makes Local String called message
	while(true)			//Infinite Loop, leave it with break
	{
		cout << "Please Enter the Message to Be Encrypted. \n";
		getline(cin, message);				//Asks for the message they want to encrypt
		if(!message.empty())				
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
	int result1 = MessageBox(HWND_DESKTOP, L"Would you Like to See a List of the Text Files in the Current Directory?", L"", MB_YESNO);
	switch(result1)
	{
		case IDYES:
		{
			system("dir *.txt /a-d /b");
			int result2 = MessageBox(HWND_DESKTOP, L"Would you like to delete all these files?", L"DELETE", MB_YESNO);
			switch(result2)
			{
				case IDYES:
				{
					int result = MessageBox(HWND_DESKTOP,L"Are You SURE??",L"Confirmation",MB_YESNO | MB_ICONWARNING);
					switch(result)
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
			int result = MessageBox(HWND_DESKTOP,L"Would You like to Clear the Current Folder of ALL Text Files",L"DELETE",MB_YESNO);
			switch(result)
			{
				int result = MessageBox(HWND_DESKTOP,L"Are You SURE??",L"Confirmation",MB_YESNO | MB_ICONWARNING);
				switch(result)
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
	while(true)		//Infinite Loop, Leave with breaks
	{
		system("CLS");		//Clears Screen
		cout << "Please Enter the Desired Filename(Please Exclude the .txt at the end)\n[MAX LENGTH = 128]:\n----> ";
		getline(cin, filename);		//Getline allows for spaces, instead of traditional cin >>
		
		if(!checkvalid(filename))
		{
			for(int x=0; x<5; x++)
			{
				Sleep(250);
				cout << lightblue << "\rTHAT IS NOT VALID";
				Sleep(250);
				cout << red << "\rTHAT IS NOT VALID";
			}
			Sleep(1000);
			
			continue;
		}

		filename += ".txt";		//Adds .txt to end of string, since user was specified NOT to add .txt at end
						//If they did, it will look like filename.txt.txt
		if(!filename.empty())		//If the filename is not empty
				{
					system("CLS");		//Clears Screen
					cout << "Your Filename is: \n" << filename << endl;	//Shows User their inputted Filename
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

	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			key[i][j] = rand() % 9 + 1;	//Key is assigned a random value, for every "square"

} //FUNCTION (GENERATE RANDOM KEY) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

float determinant(float key[SIZE][SIZE])	//Function Definition
{ //FUNCTION (DETERMINANT FINDER) START
	int det = 0;
	for(int i = 0; i < SIZE; i++)	//This is spaced out to be easily read, pretty much hard coded for only 3x3 matricies
		{
			det = 
				det + 
					(
					key[0][i] * 
					(
						key [1][(i + 1) % SIZE] * 
						key [2][(i + 2) % SIZE] - 
						key [1][(i + 2) % SIZE] * 
						key [2][(i + 1) % SIZE]
					)
					);
		}
	return det;			//Returns det value
} //FUNCTION (DETERMINANT FINDER) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<float> inverse(float k[SIZE][SIZE], float det)	//Function Definition
{ //FUNCTION (INVERSE) START
	vector<float> s;
	stringstream test;				//Can set precision of variable
	long double key[3][3];
	long double t[3][3] = {0};
	for(int i = 0; i < 3; i++)			//Transposes the current key
		for(int j = 0; j < 3; j++)
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
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)				//Multiplies by 1/det (Since dividing by Det would be integer division)
		{
			test.clear();
			test << setprecision(100) << t[i][j] * (1/det);
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

void outputkey(ofstream& Stuff)		//Function Definition
{ //FUNCTION (WRITE KEY TO FILE) START	
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			Stuff << key[i][j];					//Outputs the Matrix into the Text File
} //FUNCTION (WRITE KEY TO FILE) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

ofstream createtxt()
{ //FUNCTION (MAKE TXT FILE) START
	//****************************************************
		ofstream Stuff;				//****			Makes The Text File
		Stuff.open(filename.c_str(), ios::app); //****
	//****************************************************
	return Stuff;	//Returns Location of Stuff
} //FUNCTION (MAKE TXT FILE) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

void Decrypt()
{ //FUNCTION (MAIN DECRYPT) START
	system("CLS");						//Clears Screen
	ifstream EncodedM = openfile();				//Calls openfile, stored into EncodedM
	vector<float> filekey;					
	filekey = getkey(EncodedM);				//The Key is stored into vector filekey
	int a = 0;						//a is a temp counter
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
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
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)			//tempinv is transfered to array
		{
			inversekey[i][j] = tempinv[q];
			q++;
		}
	}
	vector<int> answer;
	answer = MatrixMultiply(inversekey, fromfile);		//array is multiplied with the encoded words
	for(int i = 0; i < answer.size(); i++)			
		cout << static_cast<char>(answer[i]);		//answer is a vector of ints
								//Cast while we output makes them their corresponding ASCII characters
	cout << endl;
	cout << "Would You Like to Store This into a .txt File?\n";
	string choose;
	cin >> choose;
	if(choose.at(0) == 'y' || choose.at(0) == 'Y')		//If they want to store the answer in a file
	{
		string sht;
		string file;
		cout << "Please Enter the Filename You would like to store it in(Without the \".txt\" at the end: ";
		overflow << getline(cin, sht);
		getline(cin, file);
		ofstream final;
		file += ".txt";
		final.open(file.c_str());
		for(int i = 0; i < answer.size(); i++)
			final << static_cast<char>(answer[i]);			//Again, Cast into characdters, then placed into a File
		cout << "DONE!\n";
		cout << "File Stored in: " << file << endl;
	}

} //FUNCTION (MAIN DECRYPT) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

ifstream openfile()
{ //FUNCTION (OPEN FILE FOR READ) START
	string file;
		cout << "Here is a list of all the .txt files in the Directory.\n";
		system("dir *.txt /a-d /b");
	ifstream EncodedM;
	while(true)
	{
		cout << "Please Enter the FileName of your Encoded Text: ";
		getline(cin, file);
		if(file.length() == 0)
			getline(cin, file);
		EncodedM.open (file.c_str(),ifstream::in);
		if(EncodedM.good())
			break;
		if(EncodedM.fail())
		{
			cout << "CORRECTLY!!\n";
			continue;
		}
	}

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
			if(a.size() == 10)
				break;
		}
		a.erase(a.end()-1, a.end());
		return a;
} //FUNCTION (GET KEY) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<int> MatrixMultiply(float key[3][3], vector<int> before)
{ //FUNCTION (MULTIPLY MATRICES) START
	float total = 0;
	vector<int> after;

	while(before.size() != 0)
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

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<int> sizecheck(vector<int> test)
{ //FUNCTION (SIZE CHECK) START
		if(test.size() % 3 != 0)
			test.push_back(0);
		if(test.size() % 3 != 0)
			test.push_back(0);
	return test;
} //FUNCTION (SIZE CHECK) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

vector<int> fetch(ifstream& EncodedM)
{ //FUNCTION (FETCH ENCODED WORDS) START
	int a;
	vector<int> b;
	while(EncodedM >> a)
	{
		b.push_back(a);
	}
	return b;
} //FUNCTION (FETCH ENCODED WORDS) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

void intro()
{ //FUNCTION (INTRO) START
//Each system("COLOR __") changes Foreground and Background colors
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);			//Maximizes the console to fit the screen
	PlaySound(TEXT("GetLowRemix.wav"), NULL, SND_ASYNC);		//Plays Music
	system("Color 1B");
	Sleep(1000);
	system("CLS");
	cout << "\n\t\t\t\tThe Matrix Machine";
	system("Color 2D");
	Sleep(1000);
	system("CLS");
	cout << "\n\n\t\t\t\tThe Matrix Machine";
	system("Color 3E");
	Sleep(1000);
	system("CLS");
	cout << "\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 4F");
	Sleep(1000);
	system("CLS");
	cout << "\n\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 5A");
	Sleep(1000);
	system("CLS");
	cout << "\n\n\n\n\n\t\t\t\tThe Matrix Machine";
	system("Color 6C");
	Sleep(1000);
	system("CLS");
	cout << "\n\n\n\n\n\n\t\t\t\tThe Matrix Machine\n";
	Sleep(1000);
	system("COLOR A7");
	cout << lightmagenta << "\t\t\t\t  Abhishek  Patel\n";
	Sleep(1000);
	system("COLOR FC");
	cout << white << "\t\t\t\t   Samuel Carlos\n";
	Sleep(1000);
	system("COLOR B3");
	cout << lightred <<  "\t\t\t\t    Julie Pirro\n";
	Sleep(1000);
	system("COLOR 08");
} //FUNCTION (INTRO) END

//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************



int checkvalid(string filename)
{
		for(int i = 0 ; i < filename.length(); i++)
		{
			if(filename.at(i) == '\\' || filename.at(i) == '/' || filename.at(i) == '*' || filename.at(i) == '?' || filename.at(i) == '"' || filename.at(i) == '<' || filename.at(i) == '>' || filename.at(i) == '|')
			{
				return 0;
			}
	}
		return 1;
}

