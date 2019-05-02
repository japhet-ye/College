//Japhet Ye
//J Squared
//Septe,ber 8, 2016
//This program calculates the amount of hours, minutes, and seconds for a given
//set amount of seconds

#include<stdio.h>

int main()
{
	int s, h, m;
	//ask for number of seconds
	printf("Enter the number of seconds\n");
	scanf("%d", &s);

	//comupte number of hours
	h = s / 3600;

	//compute number of minutes
	m = s / 60;
	
	//remainder minutes
	m = m % 60;
	//remainder seoncds
	s = s % 60;
	
	//print results
	printf("%d hours , %d minutes , %d seconds\n", h, m, s);


}
 
