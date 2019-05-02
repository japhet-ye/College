//garvity.c
//Japhet Ye
//japhetye@hawai.edu
//Japhet and Jin's group
//calculating velocity and distance of a faling abject version 2

#include<stdio.h>

#define g 9.8

int main()
{
	double t;
	double v;
	double d;

	//time
	printf("Enter time in seconds\n");
	scanf("%lf", &t);
	
	printf("t=%.3f s\n",t);

	//Calculate Velocity and distance
	 v = g * t;
	 d = g * (t * t)/ 2;

	printf("v=%.3f meters/second\nd=%.3f meters\n",
		v, d);

}


