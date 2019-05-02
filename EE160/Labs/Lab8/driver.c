
/*	File: driver.c
	by:   Tep Dobry
	date:
*/

/*  This file contains a test driver which reads a number in roman 
	numerals and prints it in decimal.  I uses the function
	get_roman() in roman.c
*/
//Japhet Ye
#include <stdio.h>
#include "roman.h"

int skipspaces(void);

int main()
{  int number;

	/*  prompt for first roman number entry  */
	printf("Enter an number in roman numerals(EOF to quit): ");

	//number = skipspaces();
	number = get_roman();

	/*  while there are more numbers  */
	while( number != EOF)
	{
	
		if (number == 0)
			printf("Invalid Input\n");
		else
		printf("The number is %d\n",number);
		/* prompt for next number  */
		printf("Enter an number in roman numerals(EOF to quit): ");

		//number = skipspaces();
		number = get_roman();
	}
	/*  clean up screen  */
	printf("\n");
}



int skipspaces(void){

	int c;
	
	c = getchar();

	while ( c == ' ' || c == '\t' || c == '\n' )
		c = getchar();

	return c;

} 


