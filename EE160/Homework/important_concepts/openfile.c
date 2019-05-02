//openfile.c
//generic template for opening a file
//and how to use the getline function to
//get each line from a file
//
//Japhet Ye
//JSsquared
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	FILE * fp;
	FILE * op;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char delim[] = ",";
	char* token;
        int x;

	fp = fopen("input.txt", "r"); //change file name as apropriate
	if (fp==NULL)
		return -1;

	op = fopen("output.txt", "r");//change file name as aparopriate
	if (op==NULL)
		return -1;

	while ((read=getline(&line,&len,fp))!= -1){

		printf("Line Length %zu : \n", read);
		printf("%s\n", line);

		for (token = strtok(line,delim);token;token=strtok(NULL,delim)){

			printf("token=%s\n",token);
			printf("space between token\n");
			
			x = atoi(token); //woops
			//this command changes a char number to an int number
			printf("x=%d\n",x);

		}
	}

	fclose(fp);
	fclose(op);
}
