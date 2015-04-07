// Chapter9factorial.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include <iostream>
int factorial(int num);


int main()
{
	char part=0;
	printf("Control P1: 4.35 Parts ABC\n");
	printf("Which part do you want [A, B, C]: ");

	
	part=getchar();
	
	system("cls");

	if(tolower(part)=='a')
	{
		int num=0, fact = 1;

		printf("Enter a number to find its factorial: ");
		scanf_s("%d", &num);
		fact=factorial(num);
		printf("The factorial of that is: %d\n", fact);
	}
	else if(tolower(part)=='b')
	{
		float e=0;
		int accuracy=0;
		printf("Enter the accuracy of e(number of terms in summation): ");
		scanf_s("%d", &accuracy);
		for(int x=0; x<accuracy; x++)
		{
			e+=1.0/factorial(x);
		}

		printf("e= %f\n", e);
	}
	else if(tolower(part)=='c')
	{
		double power=0, e=0;
		int accuracy=0;
		printf("Enter the power to raise e to (e^x): ",power);
		scanf_s("%lf", &power);
		printf("Enter the accuracy of e^%f(number of terms in summation): ",power);
		scanf_s("%ld", &accuracy);
		for(int x=0; x<accuracy; x++)
		{
			e+=pow(power,x)/factorial(x);
		}

		printf("e= %lf\n", e);
	}
	else
	{
		printf("NOT VALID");
	}

	return 0;
}

int factorial(int num)
{int fact=1;
for (int c = 1; c <= num; c++)
{
	fact = fact * c;
}
return fact;
}