//Japhet Ye
//temptable.c
//J Squared
//September 22, 2016
#include<stdio.h>

float tempcon( float x);
int temptable( float start, float stop);

int main()
{
	float start, stop, count;
	
	printf("Enter Start and Ending Temperatures\n");
	scanf("%f %f", &start, &stop);
	
	while ( start != stop ){
	temptable( start, stop);

	//printf("%f\n", &count);

	printf("Enter Start and Ending Temperatures\n");
	scanf("%f %f", &start, &stop);

	}

	return 0;

	
}

int temptable ( float start, float stop)
{
	float x, y;
	float count = 0;
	
	x = start;
	y = tempcon(x);	
	printf("Farenheit\tCelcius\n");
	printf("%.2f\t\t%.2f\n", x, y);
	while ( x != stop)
	{
		//printf("%f\t%f\n", x, y);
		
		x = x + 5;
		y = tempcon(x);
		//x = x + 5;
		printf("%.2f\t\t%.2f\n", x ,y);
		count = count + 1;
		
		if ( x == stop || x > stop )
		{
			printf("%.2f Lines Printed\n", count);
			return 1;
		}
	}
	
}

float tempcon ( float x)
{
	float y = ( x - 32 ) * 5 / 9;
	return y;
}
