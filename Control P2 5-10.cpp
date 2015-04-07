// factorials 1-5.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>


int factorial(int num);

int main()
{
	puts("Control P2 5.10");
	system("pause");
	system("cls");


	puts("Factorials 1-5:");
	for(int x=1; x<=5; x++ )
	{
		printf("%d\n", factorial(x));
	}





	return 0;
}

int factorial(int num)
{
	int fact=1;
for (int c = 1; c <= num; c++)
{
	fact = fact * c;
}
return fact;
}