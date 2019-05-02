//japhet Ye
//driver2.c
//JSsquared
//October 6, 2016
#include<stdio.h>
#include"leap.h"
#include"julian.h"

int main(){

    int day, month, year, y, flag;

    //propmts user to enter date
    printf("Enter date\n");
    flag = scanf("%d %d %d", &day, &month, &year);

    while ( flag != EOF ) {

	//calls function
	y = julian_date(day,month,year);

	printf("%d days\n", y);

	printf("Enter Date\n");
	flag = scanf("%d %d %d", &day, &month, &year);

    }

    return 0;

}
