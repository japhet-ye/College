



/*	filename: total.c
 *	author: Sam Amonette
 *	team: js
 *	username: amonette
 *	date: 11-17-16
	Input: an array of grades
	Output: total*/
#include "grades.h"
float total(a[],NST)
{
	float sum = 0; // Declare and initialize where we store total
	for (int i = 0;i<NST;i++)
	{
		sum+=a[i];
	}
	return sum;
}
