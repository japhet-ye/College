#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"grades.h"

#define NST 50
#define RST 50
#define CHAR 50

int main(void){

    int w = 0;
    double grades[NST];
    char name[NST];
    double average[NST];
    char filename[CHAR];
    double avge,mini,maxs,min1,max1;
    double minim[NST];
    double minim2[NST];
    double maxim2[NST];
    double variance[NST];
    double maxim[NST];
    int x,y,search=0;
    int i,j,start,end;
    double gradesm[NST][RST];
    char namem[NST][CHAR];

    /*printf("Enter Name of Innput File\n");
    scanf("%s", filename[CHAR]);*/    

    x = extractgrades(name,grades,NST,CHAR);

    printf("xmain=%d\n",x);

    start = 1; 
    end = x;
    y = 1;

    for(i=0;i<NST;i++){

	if(grades[i] == -1){

	    search = search + 1;
	    printf("search %d\n", search);
	}
    }

    
    for(i=0;(i<NST)&&(i<search);i++){

	for(j=1;(grades[y]>0)&&(j<=x);j++){

	    gradesm[i][j]=grades[y];
	    printf("%.2f ",gradesm[i][j]);
	    y++;

	}
	y++;

	printf("\n");


    }

    printf("\n\n");

    for (i=0;(i<NST)&&(end<23);i++){
	
        avge = avg(grades,start,end);
        average[i]=avge;
	printf("average %lf\n",average[i]);
	printf("start %d end %d\n",start,end);

	start = end + 2;
	end = end + end + 1;

    }

    start = 0;
    end = x;

    for(i=0;(i<NST)&&(end<NST);i++){

	mini = min(grades,start,end);
	minim[i] = mini;
	maxs = max(grades,start,end);
	maxim[i] = maxs;
	printf("maximum %lf\n",maxim[i]);
	printf("minimum %lf\n",minim[i]);
	printf("start %d end %d\n",start,end);

	start = end + 2;
	end = end + end + 1;
	

    }

    //finding the min max,max,avg,and variance for    //each assaignment (going down)
    for(j=1;(j<NST)&&(j<=x);j++){

	max1 = gradesm[0][0];
        min1 = gradesm[0][0];

	for(i=1;(i<=search)&&(i<NST);i++){
	    
            if (gradesm[i][j] < min1){
	
                printf("grade min %lf\n", gradesm[i][j]);
		minim2[w] = gradesm[i][j];
	       	w++;
	    
	    }    

	    if (gradesm[i][j] > max1){

	        printf("grade max %lf\n", gradesm[i][j]);
		maxim2[w] = gradesm[i][j];
		w++;
	    }

	}

    }

    

}
