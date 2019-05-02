//Japhet Ye
//swaptest.c

#include<stdio.h>
#include"swap.h"

#define DEBUG

int main(){

    float a = 2.5;
    float b = 5.9;
    float c = 12.3;

    swap(&a, &b);

    swap(&b, &c);

    swap(&a, &b);



}
