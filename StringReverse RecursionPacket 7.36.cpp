#include <iostream>
#include <string>
using namespace std;

void reversestring(string);

int main()
{
	string a;
	getline(cin, a);
	reversestring(a);
}

void reversestring(string a)
{
	if(a.length() == 0)
		cout << endl;
	else
	{
		cout << a.at(a.length() - 1);
		a.erase(a.end() - 1, a.end());
		reversestring(a);
	}
}
