//Japhet Ye
//driver3.c, pos_power function calling
//J squared S
//September 29, 2016
#include<stdio.h>
#include"pos_power.h"

int main ()
{
    float x, y, z , flag;   
    printf("Enter Base and Exponent\n");
    flag = scanf("%f %f", &x, &y);

    while ( flag != EOF ){
    
    z = pos_power(x,y);

    printf("%.2f raised to the %.2f power is %.2f\n", x, y, z);
    
    printf("Enter Base and Exponent\n");
    flag = scanf("%f %f", &x, &y);

    }
    
    return 0;
    
}
