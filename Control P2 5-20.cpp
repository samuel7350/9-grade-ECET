// Brute force pytagorean triples.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include <iostream>
#include "math.h"






int checktriple(int sidea, int sideb, int sidec);

int main(void)
{
	
	puts("Control P2 5.20");
	system("pause");
	system("cls");

	
	for(int x=1; x<500; x++)
	{
		for(int y=1; y<500; y++)
		{
			for(int z=1; z<500; z++)
			{
				if(checktriple(x,y,z))
				{
					printf("%d, %d, %d\n",x,y,z);
				}
				
			}



		}

	}



	system("pause");



	return 0;
}

int checktriple(int sidea, int sideb, int sidec)
{
	if(sidec==sqrt((float)(sidea*sidea+sideb*sideb)) ||sideb==sqrt((float)(sidea*sidea+sidec*sidec)) || sidea==sqrt((float)(sidec*sidec+sideb*sideb)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}