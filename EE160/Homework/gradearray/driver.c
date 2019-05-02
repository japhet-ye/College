#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NSTRING 100
#define LSTRING 100


int main(void){

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = " ,.?/";
    char* token;
    int x;


    fp = fopen("input.txt", "r");
    if (fp==NULL)
	return -1;

    while ((read = getline(&line, &len, fp)) != -1) {

        printf("Line length %zu :\n", read);
	printf("%s\n", line);

	for (token = strtok(line,delim);token;token = strtok(NULL,delim)){
	
	    printf("token=%s\n",token);

	    x = atoi(token);

	    printf("x = %d\n", x);

	    if ( x != 0 ){

		//grade array input for average

	    }

    	}
 
    }

}




