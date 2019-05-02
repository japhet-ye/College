#include<stdio.h>
#include<stdlib.h>

unsigned int mutl(unsigned int a, unsigned int b){
	
	unsigned int product = 0;
	unsigned int n = b;
	for(unsigned int x=a;x!=0;x=x>>1){
		if(x%2 == 1){
			product += b;
		}
		b = b<<1;

	}

	return product;

}

void main(){

	unsigned int a,b;
	
	printf("Welcome to multiply!\n");
	printf("Enter first positive integer: ");
	scanf("%d",&a);
	printf("\nEnter second positive integer: ");
	scanf("%d",&b);
	printf("Product = %d\n",mutl(a,b));
	printf("Mahalo\n");
}
