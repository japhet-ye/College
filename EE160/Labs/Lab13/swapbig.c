#include<stdio.h>
#include"swap.h"

void swap_big(float *a, float *b){

    float temp;

    if ( *a > *b ){

	temp = *a;

	*a = *b;

	*b = temp;

    }
    


}
