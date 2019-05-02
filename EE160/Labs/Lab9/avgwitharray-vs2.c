//avgwitharray-vs1.c
//Japhet Ye
//October 20, 2016
#include<stdio.h>
#include"average.h"
#define N 100
int main(){
	
	int a[N];
	float sum, flag;
	int i = 0; 
	int temp;


	for ( i = 0; (i < N) && (flag != EOF) ; i++){

		flag = scanf("%d", &temp);
		if (flag != EOF){ 
			a[i] = temp;
		//sum = average(a[N],i);
		}
		
		//i = i - 1;
		//printf("%d\n", a[i]);

	}	
	i = i - 1;
	sum = avg( a , i );

	printf("average =%.2f\n", sum);

	return 0;

}
