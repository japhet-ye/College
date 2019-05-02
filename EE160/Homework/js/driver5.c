

/*	filename: driver5.c
 *	author: Sam Amonette
 *	Team: J^2s
 *	username: amonette
 *	date: 10-22-16
 *
 *	description: driver for HW 3*/


#include <stdio.h>
#include <math.h>
#define ERROR 2
#define NMAX 11 // Any NMAX higher doesn't give more accurate results
#define XMAX 10
#define ABSOLUTE(x) ((x)<0 ? -(x):(x))

double factorial(int x);
float sinff(float x, int n);
float sint(float x, int n);
int main()
{	// Declare some variables
	float start, stop, inc; //Start and stop of range and the incriment
	printf("Enter a start and end range for angle and incriment in \
radians:");
	scanf("%f%f%f",&start,&stop,&inc);
	printf("x\tn\tsin(x)\n");
	for (start;start <= stop; start+=inc)
	{
		printf("%.2f",start);
		for (int n = 0;n < NMAX;n++) 
			// We will use x=1.57, appx. pi/2
			printf("\t%d\t%f\n",n,sint(start,n));
	}
}

double factorial(int x)
{
	if (ABSOLUTE(x) == 0 || ABSOLUTE(x) == 1)
		return 1;
	else
		return (x*factorial(x - 1));
}

float sint(float x, int N)
{	
	double ans=0; // Where we store the answer
	if (N > 170)
		return ERROR;
	else	

		for (int n=0;n<N;n++)
		{
			ans+=pow(-1,n)*pow(x,2*n+1)/factorial(2*n+1);
		}
	return ans;
}
