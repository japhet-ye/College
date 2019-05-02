
/*	filename: driver4.c
 *	author: Sam Amonette
 *	Team: J^2s
 *	username: amonette
 *	date: 10-22-16
 *
 *	description: driver for HW 3*/


#include <stdio.h>
#include <math.h>
#define ERROR 2
#define NMAX 170
#define ABSOLUTE(x) ((x)<0 ? -(x):(x))

double factorial(int x);
float sinff(float x, int n);
float sint(float x, int n);
int main()
{	
	printf("n\tsin(x)\n");
	for (int n = 0;n < NMAX;n++)
		// We will use x=1.57, appx. pi/2
		printf("%d\t%f\n",n,sint(1.57,n));
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
		return 2;
	else	
		
		for (int n=0;n<N;n++)
		{
			ans+=pow(-1,n)*pow(x,2*n+1)/factorial(2*n+1);
		}
		return ans;
}
