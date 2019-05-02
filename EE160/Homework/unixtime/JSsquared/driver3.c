//Japhet Ye
//driver3.c
//JSsquared
//October 6, 2016
#include<stdio.h>
#include"epoch.h"

int main(){

    double y;
    int day, month, year, hour, minute, seconds, flag;

    //prompts user to enter date and time
    printf("Enter Date and Time:(numbers only)\n");
    flag = scanf("%d %d %d %d %d %d", &day, &month, &year, &hour, &minute, &seconds);

    while ( flag != EOF ){

	//calls function
	y = secs_since_epoch(day,month,year,hour,minute,seconds);
	
	//if user inputs an invalid input
	if ( y == -1 ){

	    printf("Not a valid input, try again\n");

	}

        printf("%lf\n", y);

	
        printf("Enter Date and Time:(numbers only)\n");
	flag = scanf("%d %d %d %d %d %d", &day, &month, &year, &hour, &minute, &seconds);

    }

    return 0;
}
