//Japhet Ye
//epochtime.c
//JSsquared
//October 6, 2016
#include<stdio.h>
#include"epoch.h"

int main(){

    double y;
    int day, month, year, hour, minute, seconds, flag;

    //prompts user to enter current date and time
    printf("Enter Current Date and Time(numbers only)\n");
    flag = scanf("%d %d %d %d %d %d", &day, &month, &year, &hour, &minute, &seconds);

    while ( flag != EOF ){

	y = secs_since_epoch(day,month,year,hour,minute,seconds);
	
	if ( y == -1 ){

	    printf("Not a valid input, try again\n");

	}

        printf("%lf\n", y);

        printf("Enter Date and Time:(numbers only)\n");
	flag = scanf("%d %d %d %d %d %d", &day, &month, &year, &hour, &minute, &seconds);

    }

    return 0;
}
