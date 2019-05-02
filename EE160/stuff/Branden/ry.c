#include<stdio.h>

void FizzBuzz(int n);

int main(){

	int x = 20;
	FizzBuzz(x);

	return 0;
}



void FizzBuzz(int n){
	int a = 1;

	while(a<=n){
		if(a%3 == 0 && a%5 == 0) printf("FizzBuzz\n");
		else if(a%3 == 0) printf("Fizz\n");
		else if(a%5 == 0) printf("Buzz\n");
		else printf("%d\n",a);
		a += 1;
	}
}
