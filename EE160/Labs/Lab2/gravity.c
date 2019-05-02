//garvity.c
//Japhet Ye
//japhetye@hawai.edu
//Japhet and Jin's group
//calculating velocity and distance of a faling abject

#include<stdio.h>

#define g 9.8

int main()
{
	double t;
	double v;
	double d;

	//time
	printf("Enter time in seconds");
	scanf("%lf", &t);
	
	printf("t=%lf s\n",t);

	//Calculate Velocity and distance
	 v = g * t;
	 d = g * t * t / 2;

	printf("v=%lf meters/second\t d=%lf meters\n",
		v, d);

}


