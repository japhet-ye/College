//Japhet Ye
//September 22, 2016
//J Squared
//This program calculates the maximum of the numbers
#include<stdio.h>

int main()
{

	//
	float x, y, z, flag;

	printf("Enter a number\n");
	flag = scanf("%f", &x);

	if ( flag == EOF )
	{
		printf("Maximum Number is %f\n", x);
		return 0;
	}

	printf("Enter a number\n");
	flag = scanf("%f", &y);

	if ( flag == EOF )
	{
		printf("Maximum Number is %f\n", x);
		return 0;
	}

	while ( flag != EOF )
	{
		if ( y > x )
		{
			x = y;
		}
		printf("Enter a number\n");
		flag = scanf("%f", &y);
		
		if ( flag == EOF )
		{
			printf("The Maximum Number is %f\n", x);
			return 0;
		}
		//if ( y > x )
		//{
			//x = y;
		//}
		
		//if ( flag == EOF )
		//{
			//printf("The Maximum Number is %f\n", x);
			//return 0;
		//}
			
	}
	printf("The Maximum Number is %f\n", x);
	return 0;
	
}

		
