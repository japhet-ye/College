
/*	filename: driver1.c
 *	author: Sam Amonette
 *	Team: J^2s
 *	username: amonette
 *	date: 10-22-16
 *
 *	description: driver for my first factorial function for HW 3*/


#include <stdio.h>
#include <math.h>
#define ERROR 2
#define ABSOLUTE(x) ((x)<0 ? -(x):(x))

double factorial(int x);
float sinff(float x, int n);
int main()
{	
	int N; // Where we store number of terms/polynomials
	float x; // Where we store the argument of sin(x)
	float y; // Where we store (y = sin(x))
	int flag;
	// Here it is important to know that a value bigger than appx. 200
	// will crash the factorial function by making it return "inf".
	// printf("factorial(170) = %.2lf\n",factorial(170));
	printf("Enter N, the number of Taylor polynomials you wish to\n\
include in your approximation. The number can be 0\n\
or any integer between one and ten: ");
		
	flag = scanf("%d",&N); // Get N
	printf("\nEnter x, the argument sin(x), in radians: \n"); // Get x
	flag = scanf("%f",&x);
	while (flag != EOF) // Continue until EOF
	{
		y = sinff(x,N); // Call sinff
		if (y == ERROR && x != ERROR)
		{
			printf("\nSomething went wrong. Did you enter a\
			N outside the specified bound?\n");
		}
		else
			printf("sin(x) is approximately %f\n",y);
		printf("Enter another N and another x: \n");
		flag = scanf("%d %f",&N,&x);
		//printf("factorial(%d)=%lf\n",x,factorial(x));		
	}
}

double factorial(int x)
{
	if (ABSOLUTE(x) == 0)
		return 1;
	else
		return x*factorial(x - 1);
}
float sinff(float x, int n)
{
 	switch(n)
 	{
 		case 0:
 			return x;
 		case 1:
 			return (x-pow(x,3)/factorial(3));
 		case 2:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5));
		case 3:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7));
 		case 4:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9));
 		case 5:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11));
		case 6:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11)+\
 			pow(x,13)/factorial(13));
 		case 7:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11)+\
 			pow(x,13)/factorial(13)-pow(x,15)/factorial(15));
 		case 8:
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11)+\
 			pow(x,13)/factorial(13)-pow(x,15)/factorial(15)+\
			pow(x,17)/factorial(17));
		case 9:
 				
 			return (x-pow(x,3)/factorial(3)+\
 			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11)+\
 			pow(x,13)/factorial(13)-pow(x,15)/factorial(15)+\
 			pow(x,17)/factorial(17)-pow(x,19)/factorial(19));
 		case 10:
 			return (x-pow(x,3)/factorial(3)+\
			pow(x,5)/factorial(5)-pow(x,7)/factorial(7)+\
 			pow(x,9)/factorial(9)-pow(x,11)/factorial(11)+\
 			pow(x,13)/factorial(13)-pow(x,15)/factorial(15)+\
 			pow(x,17)/factorial(17)-pow(x,19)/factorial(19)+\
 			pow(x,21)/factorial(21));
 		default:
 			return ERROR; // sin is bounded by 1 and -1 on the top
 				// and bottom, resepectively, so I thought
 				// this would be a safe value. I don't 
 				// like printing in sub programs; I prefere
 				// to print error messages in the main 
 				// program.
 	}
 }
