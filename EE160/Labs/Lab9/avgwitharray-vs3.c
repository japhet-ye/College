//avgwitharray-vs1.c
//Japhet Ye
//October 20, 2016
#include<stdio.h>
#include<stdlib.h>
#include"average.h"
#define N 100
int main(){
	
	int a[N];
	float sum, flag;
	int i = 0; 
	int temp;
	FILE *ifp;

	ifp = fopen("input.txt", "r");

	if (ifp == NULL){
		fprintf(stderr, "Can't Open input.txt\n");
		exit(1);
	}


	/*for ( i = 0; (i < N) && (flag != EOF) ; i++){

		flag = scanf("%d", &temp);
		if (flag != EOF){ 
			a[i] = temp;
		//sum = average(a[N],i);
		}
		
		//i = i - 1;
		//printf("%d\n", a[i]);

	}	
	i = i - 1;*/
	for (i=0; (i < N) && (flag != EOF); i++){
		
		flag = fscanf(ifp,"%d",&temp);
		if (flag != EOF)
			a[i] = temp;
	}

	i = i - 1;

	sum = avg( a , i );

	printf("average =%.2f\n", sum);

	return 0;

}
