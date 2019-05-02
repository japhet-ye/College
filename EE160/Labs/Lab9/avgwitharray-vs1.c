//avgwitharray-vs1.c
//Japhet Ye
//October 20, 2016
#include<stdio.h>

int main(){
	
	int a[] = { 1, 2, 3, 4, 5};
	float sum;
	int i = 0;

	for ( i = 0; i < 5; i++){

		printf("%d\n", a[i]);

	}
	
	sum = (a[0] + a[1] + a[2] + a[3] + a[4]) / 5;
	

	printf("average =%.2f\n", sum);

	return 0;

}
