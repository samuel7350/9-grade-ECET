
#include "stdio.h"
#include "math.h"
#include <iostream>
#include <conio.h>
#include <windows.h>


int main()
{
	int sidea=0, sideb=0, sidec=0;
	printf("Control P1 4.29\n");
	printf("Hit any key to quit\n");

	system("pause");
	system("cls");


	for(unsigned long long x=1; true; x*=2)
	{
		printf("%llu\n",x );
		Sleep(250);
		if(kbhit())
		{
			break;
		}
		
	}


	system("pause");


}