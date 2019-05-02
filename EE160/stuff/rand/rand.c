#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	srand(time(NULL));

	int i;

	for(i=0; i<10; i++){
	
		int x = rand();
		int y = rand();

		printf("i %d\n", i+1);
		printf("x %d\n", x);
		printf("y %d\n", y);
		printf("\n");

	}

	return 0;
}
