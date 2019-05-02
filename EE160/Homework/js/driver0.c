

/*	filename: driver.c
 *	author: Sam Amonette
 *	Team: J^2s
 *	username: amonette
 *	date: 10-22-16
 *
 *	description: driver for my first factorial function for HW 3*/


#include <stdio.h>
#include <math.h>

#define ABSOLUTE(x) ((x)<0 ? -(x):(x))

double factorial(int x);
int main()
{	int i = 0; // Counter

        printf("n\tn!\n");

	while(i <= 170) // Bigger than 170 will return inf
	{	// Call factorial with increasingly bigger numbers
		//printf("factorial(%d)=%lf\n",i,factorial(i));
		//printf("%d! = %.2f\n", i, factorial(i));
                printf("%d\t%lf\n", i, factorial(i));
 
		i++;
	}
}

double factorial(int x)
{
	if (ABSOLUTE(x) == 0)
		return 1;
	else	// Reucusive definition of factorial function
		return x*factorial(x - 1);
}


