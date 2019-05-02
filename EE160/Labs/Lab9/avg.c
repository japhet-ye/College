//Japhet Ye
//avg.c
//October 20, 2016
#include<stdio.h>

int main(){

	int next;
	long sum;
	unsigned int n;
	int result;
	double avg;

	for (sum = n = 0; (result = scanf("%d", &next)) == 1; n++){

		sum += next;

		if (result == EOF)
			printf("Warning: bad input after reading %u values\n", n);
		printf("Average of %u values is %f.\n", n, (n==0) ? 0.0 : (double) sum / n);
	}

}
