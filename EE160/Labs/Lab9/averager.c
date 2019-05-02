//Japhet Ye
//October 20, 2016
//averager.c
#include<stdio.h>

int main(){

	int expected;
	int count;
	double sum;
	int value, flag = 1;

	flag = scanf("%d", &expected);

	while ( (flag != EOF) && (flag == 1) ){

		sum = 0;

		for (count = 0; (count < expected) && (flag == 1); count++){
			
			flag = scanf("%d", &value);
			
			if ( flag  == 0 ){
				printf("Error reading value #%d\n", count);
				flag = 0;
			}
			else
			sum += value;
		}

		printf("Average of %d value is %.2f\n", count, count!= 0 ? sum /                      count : 0.0);
		flag = scanf("%d", &expected);
	}

	return 0;

}
