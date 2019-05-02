//Japhet Ye
//reordertest.c
#include<stdio.h>
#include"swap.h"

int main(){

    float a;
    float b;
    float c;

    while (scanf("%f %f %f", &a, &b, &c)!= EOF){

	printf("a = %f at %x\n", a, &a);
        printf("b = %f at %x\n", b, &b);
        printf("c = %f at %x\n\n", c, &c);

	reorder(&a,&b,&c);

	printf("after function\n");
        printf("a = %f at %x\n", a , &a);
        printf("b = %f at %x\n", b, &b);
	printf("c = %f at %x\n\n", c, &c);


    }




}
