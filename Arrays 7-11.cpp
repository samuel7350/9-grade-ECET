// Bubble Sort.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>

int main()
{


	int num[10] = {0};

	puts("Arrays 7.11");
	system("pause");
	system("cls");

	puts("Enter the numbers:");
	for (int x=0; x<10; x++)
	{
		scanf("%d", &num[x]);
	}

	for (int x=0; x<9; x++)
	{
		for (int y=0; y<9; y++)
		{
			if (num[y]>num[y+1])
			{
				int temp=num[y+1];
				num[y+1]=num[y];
				num[y]=temp;
			}
		}
	}
	
	puts("Numbers in order:");

	for (int x=0; x<10; x++)
	{
		printf("%d\n", num[x]);
	}





	return 0;
}

