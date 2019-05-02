/*	filename: stddev.c
 *	author: Sam Amonette
 *	team: js
 *	username: amonette
 *	date: 11-17-16
 *	Description: calculates the standard deviation 
 *	Input: an array of grades
 *	Output: standard deviation or -1 if there is error
 *	*/

#include <math.h>
#include "grades.h"

double stddev(double a[], int NST)
{
	int i;
	int x = average(a, NST, RST)
	int sum = 0;
	for (i=0;i<NST;i++)
	{
		sum+=(a[i]-x)*(a[i]-x);
	}
	if (i == 0);
		return -1;
	return sqrt(sum/i);
}
