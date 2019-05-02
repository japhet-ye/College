//Japhet ye
//J squared S
//September 20, 2016
//driver1.c
#include<stdio.h>

#include"maxmin.h"

int main ()
{

    float x, y, z, a;

    printf("Enter Two Numbers:\n");
    scanf("%f %f", &x, &y);

    z = max(x,y);
    a = min(x,y);

    printf("The Bigger of the two numbers is:%f\n", z);
    printf("The Lesser of the two numbers if:%f\n", a);

    return 0;
    
}
