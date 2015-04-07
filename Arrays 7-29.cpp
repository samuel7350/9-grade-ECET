// primenumbergenerator.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdio.h"




int main()
{
	
	int limit=999, num=2, test=1, testsave=0;
	char numb[1000001]={1};

	for(int y=0;y<1000001;y++)
	{
		numb[y]=1;
	}


	puts("Arrays 7.29");
	system("pause");
	system("cls");






	//printf("Enter a number to find prime numbers up to:");
	//scanf("%d", &limit );

	while(num<limit)
	{
		while(num%test!=0)
		{
			test++;
			testsave=test;
			if (num==test)
			{
				test=true;
				break;
			}
		}

		if(num==2)
		{
			test=2;
		}
		if(test!=1 )
		{
			numb[num]=0;
		}	
		else
		{
			for(int a=1;a<limit; a++, a=testsave*a)
			{
				numb[a]=0;
			}
		}
		num++;
		test=2;


	}
	numb[1]=0;
	numb[2]=1;



	for(int x=1; x<limit;x++)
	{
		if(numb[x]==1)
		{
			printf("%d\n",x);
		}
	}










	return 0;
}

