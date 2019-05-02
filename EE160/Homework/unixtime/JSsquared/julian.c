//#include"leap.h"
#include"julian.h"
#include<stdio.h>

int julian_date(int day, int month, int year){

    //initilizes total and counts up
    int sum = 0, x = 0, count = 0;

    count = month + count;
    sum = sum + day;  //leftover days is starting value

    count = count - 1;//goes down to the next full month

    x = is_leap(year);//checks to see if year is a leap year
    
    //counting down months and adding repected values to them
    while ( count > 1 || count == 1 ) {

        //ckecks to see if febuary
	if ( count == 2 ){

	    //if the year is a leap year
	    if ( x == 1 ){
	
	        sum = 29 + sum;
	
	    }
	    //could use an else, but idk really, just felt like it
	    if ( x == 0 ){

		sum = 28 + sum;

	    }

	}

        //checks month with 31 days
	if ( count == 1 || count == 3 || count == 5 || count == 7 || count == 8 || count == 10 || count == 12 ){

	    sum = sum + 31;

	}
        //checks month with 30 days
	if ( count == 11 || count == 9 || count == 6 || count == 4 ){

	    sum = sum + 30;

	}
	//goes down a month
	count = count - 1;

    }
    //return the amount of days
    return sum;

}
