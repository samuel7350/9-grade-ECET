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
ostream & operator << (ostream & out, const vector <T> & v)
{
size_t last = v.size() - 1;
for(size_t i = 0; i < v.size(); ++i)
{
out << v[i];
if (i != last)
out << " , ";
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

int counter = 0;

string message = "";

string filename = "";

string TempEncrypt = "";

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
	for(i=0;i<3;i++) 
	{ 
		for(j=0;j<3;j++) 
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
    int total2 = 1;
    int total3 = 1;
    total2 = key[0][0] * key[1][1] * key[2][2];
    total3 = key[0][2] * key[1][1] * key[2][0];
    cout << total2 << endl;
    cout << total3 << endl;
    cout << total2 - total3 << endl;
}
void Inverse()
{

}
void Message()
{
	vector<int> myVector;		
	string message;
	getline(cin, message);		
	for (int count = 0; count < message.length(); count++)   //takes each character of the message
	{
		char y = message.at(count);
		myVector.push_back(static_cast<int>(y));
	}
			cout << "The vector is: " << endl;
			for (int i = 0; i < myVector.size(); i++){	//outputs the vector and the stuff inside
				cout << myVector[i] << " " << endl;
			}
	
	while (myVector.size() % 3 != 0){	
		myVector.push_back(32);   
	}
}
/*
void MatrixMultiplication() //i need the code for the conversion of the message
                            //in order to run the multiplication as many times needed
{
    int i, j, k, count = 0, total = 0;       // i = rows, j = columns

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < 3; k++)
				total += K[i][k] * W[k][j];  //mulitplies Key by matrix W
			cout << setw(4) << total << " "; //total displays the product in 3x1 matrix,
			++count;						 //although its not really a matrix yet.
			cout << endl;
			total = 0;


		}
	}
}
*/

void Decrypt()
{
    cout << "Please enter the filename of the encrypted message: ";
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
	randfilename+= ".txt";						//Adds .txt to end of string
	remove("Encrypted.txt");				//Deletes the old file used last time
    ofstream Stuff;							//WHATEVER NEEDS TO GO IN THE TXT REPLACE COUT WITH STUFF
	Stuff.open(randfilename.c_str(), ios::app);
    srand((unsigned)time(NULL));			//Like Stuff << Key[3][3];
        while(sizeofarr > 0)
        {
            key[3][3] = rand() % 10;                    //Generates a random number from 0 to 9
            cout << setw(2) << key[3][3] << " ";        //Outputs the value with a space after it (For Debugging)
			Stuff << setw(2) << key[3][3] << " ";
            counter++;                                  //Counter +1
            if ( counter % 3 == 0)                      //When the counter reaches 3
			{
                cout << endl;                           //Go to the next line (For Debugging)
				Stuff << endl;
			}
            sizeofarr = sizeofarr - 1;                  //sizeofarr - 1 (starts at 9)
        }
        Determinant();
            cout << "Please enter the message: ";
            getline(cin, message);								//Asks for the message they want to encrypt
			if(!message.empty())
			{
				cout << "Your Message is: \n" << message << endl;
				cout << "This is your Encrypted FileName! Please Keep it for Decryption!\n";
				cout << randfilename << endl;
			}
			else
			{
				getline(cin, message);
				cout << "Your Message is: \n" << message << endl << endl;
				cout << "This is your Encrypted FileName! Please Keep it for Decryption!\n";
				cout << randfilename << endl << endl;;
			}
}

int main()
{
    while(true)
    {
		cout << "What would you like to do?\nD= Decrypt\nE = Encrypt\n";
		cin >> choose;
		if (choose == 'e' || choose == 'E')
		{
			if(y == 'i')
				Encrypt();
			cout << "Would You like to Decrypt?(Y/N)\n";
			cin >> decrypt;
			if (decrypt == 'y' || decrypt == 'Y')
			{
				Decrypt();
				y = 'v';
			}
			else
				return 0;
		}
		else if (choose == 'd' || choose == 'D')
		{
			Decrypt();
		}
    }
}
