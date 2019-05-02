//Japhet Ye
//imatrix.c
//JS
#include<stdio.h>


int idenity( int m[][M], int N){

    int i;

    if (M == N){

        for (i = 0; i<N;i++){

            if(m[i][i] != m[i+1][i+1]) {
                return 0;
            }
        }     

        return 1;

    }

    else {

        return 0;

    }


}
