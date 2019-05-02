


/*	filename: assignletter.c
 *	author: Sam Amonette
 *	team: js
 *	username: amonette
 *	date: 11-17-16
	Input: an array of grades
	Output: min or -1 if there is error

Input: a grade as points
Functionality: converts point grade into letter grade Output: a char representing the letter grade, or -1 if error*/
#include "grades.h"
char assignletter(float grade)
{
	if (grade<0)
		return -1; // Indicates an error
	switch(grade)
	{
		if (grade<0)
			return -1;
		if (grade<60)
			return 'F';
		if (grade<70)
			return 'D';
		if (grade<80)
			return 'C';
		if (grade<90)
			return 'B';	
		else:
			return 'A';	
	}

}
