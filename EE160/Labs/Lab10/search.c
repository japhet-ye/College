//Japhet Ye
//search.c
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define R 100

int search(int a[], int v, int result[]); 
int main(){

    FILE *ifp;
    int flag, v, res, temp, x, N;
    int result[R], a[N];

    ifp = fopen("in_search.txt", "r");

    if (ifp == NULL){

	fprintf(stderr,"Can't open in_search.txt\n");
	exit(1);
    }

    //fscanf in_search.txt for the values of the array



    printf("Enter what digit to look for\n");
    scanf("%d", &v);

    res = search( a, v, result);

    printf("There were %d instances of %d in the array\n", res, v);


    fclose (ifp);
    return 0;
}

int search( int a[], int v, int result[]){

    int temp, count, r=0;

    for (count = 0; count<N; count++){

	temp = a[count];

        if (temp == v){
	    result[r] = count;
	    r++;
	}    
    } 

    if (r == 0){

        result[r] = -1;
        return -1;

    }

    else {

        return r;

    }
    
}
