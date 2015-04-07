// Odd products.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>

int main()
{

	int total=1;

	puts("Control P2 5.9");
	system("pause");
	system("cls");

	for(int x=1; x<=15; x+=2)
	{
		total*=x;
	}


	printf("The product of odd numbers from 1-15 is: %d\n", total);














	return 0;
}

