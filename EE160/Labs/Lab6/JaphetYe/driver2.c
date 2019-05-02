
//Japhet ye
//J squared S
//September 20, 2016
//driver1.c
#include<stdio.h>

#include"maxmin.h"

int main ()
{

    float x, y, z, a ,flag;

    printf("Enter A Number:\n");
    scanf("%f", &x);

    if ( flag == EOF )
    {
	printf("TERMINATED\n");
	return 0;
    }

    while ( flag != EOF )
    {
	
	printf("Enter a Number:\n");
	flag = scanf("%f", &y);
	
        z = max(x,y);
        a = min(x,y);

	printf("Enter a Number:\n");
	flag = scanf("%f", &x);

    }
    printf("The Bigger of the two numbers is:%f\n", z);
    printf("The Lesser of the two numbers if:%f\n", a);

    return 0;
    
}
