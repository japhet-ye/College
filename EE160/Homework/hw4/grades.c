#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"grades.h"
/*Input: input file name, as char array; matrix of names, and matrix of grades; Functionality: opens the file, extracts names into the matrix of names, and extracts grades into the matrix of grades;
Output: 0 if everything went well, and -1 otherwise*/
int extractgrades( struct person reader[]){


    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = " ./?<>";
    char* token;
    double x;
    int i=0; // counter for grades per person 
    int count=0; // counter for reader
    int numgrades;	

    fp = fopen("input.txt", "r");
    if (fp == NULL)
        return -1;

    while ((read = getline(&line,&len,fp)) != -1){
	// getline function reads until it sees NULL
	//printf("Line Length %zu : \n", read);
	
        //printf("%s\n", line); // Line is the array 
				// where we put 'reader'

        //now we have a line from the file which is 1 name and that persons grades
        for (token = strtok(line,delim);token;token = strtok(NULL,delim)){
	    //printf("token=%s\n", token);

	    // cONVERTS A STRING NUMBER TO DOUBLE NUMBER
	    x = atoi(token);
	    //debug
	    //printf("x = %lf\n", x);

            // If x=0, it is a name, so sting copy the name into reader[count].name				
	  

            if (x == 0){

		strncpy(reader[count].name,token,CHAR);
	        //printf("struct %s\n",reader[count].name);
		
	    }
            // else if x is greater than 0, it is a grade
            // so put it in reader[count].grade
	    else if (x > 0){

		reader[count].grade[i]=x;
		//printf("struct %lf \n",reader[count].grade[i]);
                i++; 
		
		
	    }

	    count++; //next person
	    i = 0;  //resetting the grade array to 
         	    //first element

	}

        //count = count + 1;
	//reader[count].size = i - 1;
	//printf("size %d\n",reader[count].size);

    }
    reader[0].namecount++;	
    //printf("size %d\n",reader[count].size);
	
    fclose(fp);

    return 0;     

}

char assaignletter(double points){


}

double avg(struct person reader[]){

    int i;
    double sum = 0;

    for (i=0;i<NST;i++){

	//sum+=


    }





}

double min( struct person reader[]){




}

double max( struct person reader[]){




}

double stddev( struct person reader[]){


}

double total( struct person reader[]){



}


