#include <iostream>
#include <vector>
using namespace std;

int minimum(vector<int>, int, int);
int rec(vector<int>, int, int, int);
int main()
{
	int y;
	int start;
	int end;
	vector<int> a;
	cout << "Enter 10 Numbers. \n";
	for(int i = 0; i < 10; i++)
	{
		cout << i + 1 << ": ";
		cin >> y;
		a.push_back(y);
	}
	cout << "Enter the Start Point: ";
	cin >> start;
	cout << "Enter the End Point: ";
	cin >> end;
	//int temp = minimum(a, start, end);
	a.erase(a.begin(), a.begin() + start - 1);
	a.erase(a.end() - (a.size() - end), a.end());
	int n = a.size();
	cout << "This is the Minimum Number in this Group: " << rec(a, n, start, end);
}

int rec(vector<int> a,int n, int start, int end)
{
    int min;
    if(n == 1)
		return a[0];
	if(start == end)
		return a[start - 1];
	else
    {
        min=rec(a, n-1, start, end);
		n = n - 1;
        if(min < a[n])
			return min;
        else
			return a[n];
	}
}
