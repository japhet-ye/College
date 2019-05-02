#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"grades.h"


int main(){

    struct person reader[NST];
    int x;
    int i,j,z=0;
    double average[NST];

    x = extractgrades(reader);

    
 
    for (i=0;i<NST;i++){

	printf("%s \n",reader[i].name);

    }
}
