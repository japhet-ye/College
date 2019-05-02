//Japhet Ye
//temperature.c
//September 22, 2016
//J Squared
//This program converts Ferenheit to Celcius
#include<stdio.h>

double tempcon( double far);

int main()
{
	double cel, far, flag;
	printf("Enter Degrees In Ferenheit\n");
	flag = scanf("%lf", &far);
	
	if ( flag == EOF )
	{
		printf("Terminated\n");
		return 0;
	}
	
	cel = tempcon(far);
	printf("%lf degrees Celcius if %lf degrees Farenheit\n", cel, far);
	return 0;
}

double tempcon( double far)
{
	double cel;
	cel = ( far - 32 ) *  5 / 9 ;
	return cel;
}
	
