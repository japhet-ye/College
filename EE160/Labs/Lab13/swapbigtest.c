//Japhet Ye
//swapbigtest.c
#include<stdio.h>
#include"swap.h"

int main(){

    float a;
    float b;

    while (scanf("%f %f", &a, &b) != EOF){

        printf("a = %f at %x\n", a , &a);
        printf("b = %f at %x\n\n", b, &b);

	swap_big(&a, &b);

        printf("a = %f at %x\n", a, &a);
        printf("b = %f at %x\n\n", b, &b);

    }
    
    return 0;


}
