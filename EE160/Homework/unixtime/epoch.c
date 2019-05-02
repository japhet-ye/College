//Japhet Ye
//epoch.c
//JSsquared
#include"epoch.h"
#include"leap.h"
#include"julian.h"

double secs_since_epoch(int day,int month,int year,int hour,int minute,int seconds){

    //initilizes variables
    int x = day, y = month, z = year; //x = day y = month z = year
    double a = 0, b = 0, c = 0, d = 0, e = 0; //a = sum days b = check if leap year c = sum hours
	//d = sum minutes e = sum seconds
    double q;

    //returns julian date(the amount of days in the year
    a = julian_date(x,y,z);

    //goes down to the next full year
    z = z - 1;

    //counts down years until 1970
    while ( z > 1970 || z == 1970 ){

        //checks to see of year is a leap year
        b = is_leap(z);

        //adds repected values to the sum of the days
	if ( b == 1 ){

	    a = a + 366;

	}

	if ( b == 0 ){

	    a = a + 365;

	}
        //goes down to the next full year
	z = z - 1;
    }

    /*if ( a == 1 ){

	//return the amount of seconds in the time if 1 1 1970

    }*/

    //counting days Since 1 1 1970, removes 1 1 190 from day count
    a = a - 1;

    //converts days to hours
    c = (a * 24) + hour;

    //converts hours to minutes
    d = (c * 60) + minute;

    //converts minute sto seconds
    e = (d * 60) + seconds;
 
    //return the amount of seconds
    return e;

    


}
