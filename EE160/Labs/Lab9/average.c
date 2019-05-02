#include"average.h"


float avg( int a[], int i){

	float sum = 0;
	int c;
	float avg;
	
	sum = a[0];

	for (c = 1; c < i ; c++){

		sum = sum + a[c];
	}

	avg = sum / i;

	return avg;
}
