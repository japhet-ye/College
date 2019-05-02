//sphere.c
//Japhet Ye
//japhetye@hawai.edu
//Japhet and Jin's group
//1 September, 2016
//calculating the volume and surface area of sphere

#include<stdio.h>

#define PI 3.14

int main()
{
	double r;
	double s;
	double v;

	//read radius
	printf("Enter radius in centimeters");
	scanf("%lf", &r);
	
	printf("r=%lf cm\n",r);

	//Calculate Surface Area and Volume
	s = 4.0* r* r* PI;
	v = 4.0/3.0 * r * r * PI;

	printf("s=%lf square cm\t v=%lf cubic cm\n",
		s, v);

}


