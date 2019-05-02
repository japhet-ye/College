#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	srand(time(NULL));
	
	int flag, i;
	
	printf("Do you want 2 random numbers?(any number for yes\nEOF to close)\n");
	flag = scanf("%d", i);
	while(flag != EOF){
		int x = rand();
		int y = rand();

		printf("x %d\n", x);
		printf("y %d\n", y);
		printf("\n");
		
		printf("Do you want 2 random numbers?(any number for yes\nEOF to close\n)");
		flag = scanf("%d", i);

	}
	return 0;
}
