
/*	Filename: is_leap.c
	Author: Sam Amonette
	Team: SJ^2
	username: amonette
	Date: 10-2-16
	
	Description: Takes one argument, year; if one, true, if 0, false, that is a leap year*/

#include <stdio.h>
#include "leap.h"
#define DEBUG
int is_leap(int year)
{
	if (year % 4 == 0)
	{	
		if (year % 100 != 0 || year % 400 == 0)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}	
}

