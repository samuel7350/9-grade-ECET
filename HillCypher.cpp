#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "stdlib.h"
#include <vector>
#include <string>
using namespace std;
char again;
int sizeofarr = 9;
int counter = 0;
string message = "";
string filename = "";
string TempEncrypt = "";
void CoFactor()
{

}
void Determinant()
{

}
void Inverse()
{

}
void MatrixMultiplication()
{

}
int key[3][3] =
{
{0,0,0},
{0,0,0},
{0,0,0}
};

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

void Decrypt()
{
    cout << "Please enter the filename of the encrypted message: ";
    cin >> filename;
    cout << "The Filename you Entered is: " << filename << endl;
    ifstream EncryptedMessage;
    EncryptedMessage.open("filename");
        while(!EncryptedMessage.eof())
        {
            getline(EncryptedMessage, TempEncrypt);
            cout << TempEncrypt;
        }
        EncryptedMessage.close();
        system("Pause");
}

void Encrypt()
{
    srand((unsigned)time(NULL));
        while(sizeofarr > 0)
        {
            key[3][3] = rand() % 27;                    //Generates a random number from 0 to 26
            cout << key[3][3] << " ";                   //Outputs the value with a space after it (For Debugging)
            counter++;                                  //Counter +1
            if ( counter % 3 == 0)                      //When the counter reaches 3
                cout << endl;                           //Go to the next line (For Debugging)
            sizeofarr = sizeofarr - 1;                  //sizeofarr - 1 (starts at 9)
        }
            cout << "Please enter the message: ";
            cin >> message;
            cout << "Your Message is: \n" << message << endl;
            cout << "Do you Wish to Encrypt this? (Y to continue)";
            cin >> again;
            if (again != 'y' || again != 'Y')
                Decrypt();
}

int main()
{
    while(true)
    {
        Encrypt();
        cout << "Would you Like to Decrypt a Message? (Y/N)";
        cin >> again;
        if (again == 'y' || again == 'Y')
            Decrypt();
        else
        {
            cout << string(20, '\n');
            cout << "Thank you for Encrypting with us.\nYour Encrypted File is is the same directory as this program :)";
            return 0;
        }
    }
}
