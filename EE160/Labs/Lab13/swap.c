//Japhet Ye
//swap.c
#include<stdio.h>
#include"swap.h"

#define DEBUG 1

void swap( float *x, float *y){

    float temp;

    #ifdef DEBUG
    printf("Entering swap() with\n");
    printf("x is address = %x, contents %f\n", x, *x);
    printf("y is address = %x, cintents %f\n", y, *y);
    #endif

    temp = *x;

    *x = *y;

    *y= temp;

    #ifdef DEBUG
    printf("Exiting swap() with\n");
    printf("x is address = %x, contents %f\n", x, *x);
    printf("y is address = %x, contents %f\n", y, *y);
    #endif

}
