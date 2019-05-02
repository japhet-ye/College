

/*	filename: driver6.c
 *	author: Sam Amonette
 *	Team: J^2s
 *	username: amonette
 *	date: 10-22-16
 *
 *	description: driver for HW 3*/


#include <stdio.h>
#include <math.h>
#define ERROR 2
//#define NMAX 11 // Any NMAX higher doesn't give more accurate results
#define XMAX 10
#define ABSOLUTE(x) ((x)<0 ? -(x):(x))

double factorial(int x);
float sinff(float x, int n);
float sint(float x, int n);
int main()
{
	// For the entire homework assignment, I found instructions unclear.
	// This is minimal because my TA said I could interpret it this way.
	// So we don't print any tables.

	// Declare Variables
	float error; // Where we store the error they enter
	float x;
	int flag;
	// Get n
	printf("Enter the error. It must be less than .001: \n");
	flag = scanf("%f",&error);
	// Get x
	printf("Enter x, the argument of sin(x), in radians: \n");
	flag = scanf("%f",&x);	
	while (flag != EOF)
	{	
		if ( error > .001)
		{
			printf("Something went wrong. Did you enter error \
greater than .001?\n");
			printf("Enter another error less than .001\
 and another x value (EOF to quit):\n");
			flag = scanf("%f %f",&error,&x);
		}
		else
		{	
			float y = sin(x);
			printf("Library sin(%f)=%f\n",x,y);
			for (int n = 0; ABSOLUTE(sint(x,n)-y) > error; n++)
			{
				printf("For sint(%f,%d) = %f\n",x,n,sint(x,n));				
				printf("Error is %f\n",ABSOLUTE(sint(x,n)-y));
				printf("Enter another error less than .001\
 and another x value (EOF to quit):\n");	
			}
			flag = scanf("%f %f",&error,&x);
			
		}
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



