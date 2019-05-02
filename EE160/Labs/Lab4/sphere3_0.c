//sphere.c
//Japhet Ye
//japhetye@hawai.edu
//Japhet and Jin's group
//13 September, 2016
//calculating the volume and surface area of sphere revised

#include<stdio.h>

#define PI 3.14

int main()
{
	double r;
	double s;
	double v;

	//read radius
	printf("Enter radius in centimeters\n");
	scanf("%lf", &r);
	
	//if statement
	if( r > 0 ) {

	printf("r=%lf cm\n",r);

	//Calculate Surface Area and Volume
	s = 4.0* r* r* PI;
	v = 4.0/3.0 * r * r * r * PI;

	printf("s=%lf square cm\t v=%lf cubic cm\n",
		s, v);
	}

	else {

	printf("Not a Valid Input\n");
	}

	return 0;

}


