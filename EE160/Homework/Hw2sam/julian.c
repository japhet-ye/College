/*	Filename: julian.c
	Author: Sam Amonette
	Team: SJ^2
	username: amonette
	Date: 10-2-16
	
	Description: Takes three arguments: day, month, year. Returns ordinal day number for that day.*/

#include "julian.h"
//#define DEBUG

int julian (int day, int month, int year)
{	
	// Variable declarations
	int i = 1; // Counter
	int sum = 0; // Sum is where I will store the sum of the number of days in a given year
	int ordinal; // Where I store the ordinal day number	
	while ( i < month)
	{
		sum = sum + day_of_month(i,year);
		#ifdef DEBUG
		printf("sum = %d\tday_of_month = %d\t day = %d\n",sum,day_of_month(i,year),day);
		#endif
		i++;
	}
	ordinal = sum + day;
	#ifdef DEBUG
	printf("DEBUG: day of month is %d for month of %d in year % d\n",day_of_month(i,year),i,year);
	printf("day_of_month is %d\n",day_of_month(month,year));
	#endif
	
	return ordinal;	
}
int day_of_month(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{	
			return 31;
		}
		else if (month == 2)
		{
			if (is_leap(year) == 1)
			{
				return 29;
			}
			else
			{
				return 28;
			} 	
		}
		else if (month == 4  || month == 6  || month == 9 || month == 11)
		{
			return 30;
		}
}


