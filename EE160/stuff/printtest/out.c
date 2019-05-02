#include<stdio.h>
#include<stdlib.h>


int main(){

	FILE * op;
	
	op = fopen("output.txt","w");
	if (op == NULL)	
		return -1;

	fprintf(op, "Hello World\n");


	fclose(op);
	return 0;
}
