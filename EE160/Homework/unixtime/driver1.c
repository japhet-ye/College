//driver.c
//Japhet Ye
//JSsquared 
//October 2, 2016
#include<stdio.h>
#include"leap.h"

int main()
{

	int x, y, flag;

	//prompts user to input date
	printf("Enter Year\n");
	flag = scanf("%d", &x);
	
	//while loop
	while ( flag != EOF ) {

	    //calls function
	    y = is_leap(x);

	    //true/false return values
	    if (y ==1){

		printf("The Year %d is a Leap Year\n", x);

	    }

	    else {

		printf("The Year %d is Not  Leap Year\n", x);

	    }

	    printf("Enter Year\n");
	    flag = scanf("%d", &x);

	}

}
