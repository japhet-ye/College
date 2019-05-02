


/*	Filename: epochdriver.c
	Author: Sam Amonette
	Team: SJ^2
	username: amonette
	Date: 10-2-16
	
	Description: JUST THE DRIVER
Write a function that will return number of seconds since Unix Epoch time, 00:00:00 Thursday January 1, 1970*/

#include <stdio.h>
#include "epoch.h"

int main()
{
	printf("%lf\n",secs_since_epoch(15,5,1984,8,50,30));
}
