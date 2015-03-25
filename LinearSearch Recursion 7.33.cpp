#include <iostream>
#include <vector>

using namespace std;

int linearsearch(vector<int>, int, int);
int main()
{
	int searchsearchkey;
	int length;
	vector<int> a;
	cout << "Enter the Number of Comming Numbers: ";
	cin >> length;
	int temp = length;
	while(temp > 0)
	{
		int y;
		cin >> y;
		a.push_back(y);
		--temp;
	}
	cout << "Enter the Number you Wish to Find: ";
	cin >> searchsearchkey;
	cout << linearsearch(a, length, searchsearchkey) << endl;
}

int linearsearch(vector<int> a, int length, int searchkey)
{
    length=length-1;
    if(length <0)
		return 1;
    else if(a[length] == searchkey)
		return length + 1;
    else
		return linearsearch(a,length, searchkey);
}
