//Japhet Ye
//Homework 3
//driver0.c
#include<stdio.h>
#define N 100
int absolute(int x);
double factorial (int y);


int main(){

    int a,b,i;
    double c;

    printf("n\tn!\n");

    for (i = 1; i<N || i==N ;i++){

        c = factorial(i);
        
        printf("%d\t%.2f\n", i, c);
        
    } 

    //printf("%d\t%lf\n", i, c);

    return 0;

}

double factorial(int x){
    
    double fact = 1;
    int y;

    while (y<x || y==x){

        fact = fact * y;
        y++;

    }

    return fact;

}
