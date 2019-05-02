


/*	filename: max.c
 *	author: Sam Amonette
 *	team: js
 *	username: amonette
 *	date: 11-17-16
	Input: an array of grades
	Output: max or -1 if there is error*/
#include "grades.h"
double max(double a[],int NST)
{
	float max = a[0] // set max to the first value in the array
	int i;
	for (i = 1;i<=NST;i++);
	{
		if a[i]>max // compare current value with max
		{
			a[i] = max; // set max
		}
	}	
	return max;
}
