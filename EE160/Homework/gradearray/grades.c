#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"grades.h"
/*Input: input file name, as char array; matrix of names, and matrix of grades; Functionality: opens the file, extracts names into the matrix of names, and extracts grades into the matrix of grades;
Output: 0 if everything went well, and -1 otherwise*/
int extractgrades( char name[], double grades[], int NST, int CHAR){


    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = " ,./?<>";
    char* token;
    double x;
    int i=0;
    int ii=0;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
        return -1;

    while ((read = getline(&line,&len,fp)) != -1){

	printf("Line Length %zu : \n", read);
        printf("%s\n", line);

        for (token = strtok(line,delim);token;token = strtok(NULL,delim)){

	    printf("token=%s\n", token);

	    x = atoi(token);
	    
	    printf("x = %lf\n", x);

	    if (x > 0){
		grades[i] = x;
		//i++;
   	        printf("grade=%lf\n",grades[i]);
		i++;
	    }
	
	    else {

		grades[i] = -1;
		//i++;
		printf("grade = %lf\n",grades[i]);
		i++;
		
		ii++;
	
	    }

	    
        }

	/*for(i=0;i<NST;i++){

	    printf("grade=%lf\n",grades[i]);

	}*/


    }

    i=1;

    while (grades[i] != -1){

	i++;

    }
    
    i=i-1;
    return i;

}

char assaignletter(double points){


}

double avg(double grades[], int start, int end){

    int i;
    double sum = 0.0;
    double av;
    double counter = 1;
    for(i=start; i<=end; i++){

	printf("%lf\n",grades[i]);
	if (grades[i] > -1){

	    sum = grades[i] + sum;
	    counter++;

        }
    }

    counter = counter - 1;

    printf("%lf\n",counter);
    printf("%lf\n",sum);

    if (sum>0){

        av = sum/counter;
	return av;

    }

}

double min( double grades[], int start, int end){

    int i;
    double min = grades[start];

    for (i=(start+1);i<=end;i++){

	if(grades[i] < min){
	
	    min = grades[i];

	}


    }

    return min;


}

double max( double grades[], int start, int end){

    int i;
    double max = grades[start];

    for (i=(start + 1);i<=end;i++){

	if(grades[i] > max){

	    max = grades[i];

	}

    }

    return max;


}

double stddev( double a[], int NST){


}

double total( double a[], int NST){



}


