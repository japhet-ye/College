
/*	filename: stddev.c
 *	author: Sam Amonette
 *	team: js
 *	username: amonette
 *	date: 11-17-16
 *	Description: Input: an array of grades
 *	Functionality: calculates average of the elements of the input array 
 *	Output: the average or -1 if there is error
 *	*/

#include "grades.h"

double average(double a[], int NST)
{	
	int i;
	double sum = 0.0; // where we sum the numbers to be averaged
	for (i=0;i<NST;i++)
	{	
		sum+=a[i];	
	}
	if (i == 0)
		return -1; // incase of error
	return sum/i;
}
