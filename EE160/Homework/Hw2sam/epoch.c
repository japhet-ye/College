

/*	Filename: epoch.c
	Author: Sam Amonette
	Team: SJ^2
	username: amonette
	Date: 10-2-16
	
	Description: 
Write a function that will return number of seconds since Unix Epoch time, 00:00:00 Thursday January 1, 1970*/

#include "epoch.h"
double secs_since_epoch(int day, int month, int year, int hour, int minute, int second)
{	
	int yrs; // Years since 1970 (could be negative)
	int days; // Days in a partial year (i.e. current year)
	int counter =  1970; // Epoch year (incriment, counts years)
	int sum = 0; // sum of day to be converted to hours to minutes then seconds
	int hours = 0; // sum of hour, converted from days 
	int mins = 0; //
	int seconds = 0;
	if (year >= counter) // Case 1 year greater than 1970
	{
		while (counter < year) // Count up from 1970 to the current year, to get number of days in all these years (sum)
		{
			if (is_leap(counter) == 1)
			{
				sum += 366;
				
			} 
			else 
			{
				sum += 365;
			}
			counter++;
			//printf("sum is %d\n",sum);
		}
		sum += julian(day,month,year); // Add the number of days in the current year
		//printf("sum is %d\n",sum);
		hours = sum * 24 + hour; // Convert days to hours
		//printf();
		mins = hours * 60 + minute; // Convert hours to minutes
		seconds = mins * 60 + second; // Convert minutesm to seconds
		return seconds;
	}
	else if (year < counter) // Case 2 year less than 1970
	{	
		//while (counter > year) // Count down from 1970 to current year, to get number of days in all these years
		//{
		//	if (is_leap(counter) == 1)
		//	{
		//		sum += 366;
		//	} 
		//	else 
		//	{
		//		sum += 365
		//	}
		//	counter -= 1;
		//}
		//sum += julian(day,month,year); // Add the number of days in the current year
		//sum = sum * (-1)
		return -1;
	}

	
}
