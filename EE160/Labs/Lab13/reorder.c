#include<stdio.h>
#include"swap.h"

void reorder( float *a, float *b, float *c){

    if (*a > *c){

	swap_big( a, c);

    }

    if (*b > *c){

	swap_big( b, c);

    }

    if (*a > *b){

	swap_big( a, b);

    }

    

}
