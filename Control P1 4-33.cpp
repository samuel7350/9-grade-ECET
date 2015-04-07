
#include "stdio.h"
#include "math.h"
#include <iostream>




int main()
{
	int sidea=0, sideb=0, sidec=0;
	printf("Control P1 4.33\n");


	system("pause");
	system("cls");


	printf("Enter side A: ");
	scanf_s("%d", &sidea);

	printf("Enter side B: ");
	scanf_s("%d", &sideb);

	printf("Enter side C: ");
	scanf_s("%d", &sidec);



	if(sidec==sqrt((float)(sidea*sidea+sideb*sideb)) ||sideb==sqrt((float)(sidea*sidea+sidec*sidec)) || sidea==sqrt((float)(sidec*sidec+sideb*sideb)))
	{
		printf("That's a right triangle\n");
	}
	else
	{
		printf("That's not a right trangle\n");
	}


	system("pause");


}