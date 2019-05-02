
#include <stdio.h> 
//#include"matrix"
#define SIZE 10
#define M 3
int  identity(int m[ ][M], int N) ;

int main() {

	FILE *ifp, *ofp;

	ifp = fopen("in_matrix.txt", "r");	//open file for reading
	//if file cannot be opened, report error
	if (ifp == NULL) {		
		fprintf(stderr, "Can't open input file in.txt\n");
		return -1;
	}

	int m[SIZE][M];		//make SIZE sufficiently large 
	int N;
	int i = 0;
	int j = 0;
	int num_rows = 0;
        int id;

	//read from file, store in matrix
	while (fscanf(ifp, "%d ", &m[i][j]) != EOF) {
		j++;
		if (j == M) { i++; j = 0; num_rows++;}

	}
	//at this point, we counted all rows
	N = num_rows;   	//It must be that N <= SIZE

	//print the matrix you read in
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}

        id = identity(m, N);

        if (id == 1){

	    printf("Matrix is an Identity Matrix\n");

	}

        else {

            printf("Matrix is not an Identity Matrix\n");

	}


	//close the file
	fclose (ifp); 
}


int  identity(int m[ ][M], int N) {

        int i;

        if (M==N){

	    for (i=0; i<N;i++){

		if(m[i][i] != m[i+1][i+1]){
   
                    return 0;

                }

            }

            return 1;

        }

        else{
	    return 0;
        }   


}
