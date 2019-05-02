//Japhet Ye
//September 15, 2016
//

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

int main() {

	FILE *ifp, *ofp;
	double r, a, v;

	ifp = fopen("radius.txt", "r");
	
	if (ifp == NULL) {
	 	fprintf(stderr, "Can't open input file in.txt\n");
	 	exit(1);
	}

	ofp = fopen("out.txt", "w");

	if ( ofp == NULL ) {

	     fprintf(stderr, "Can't Open Output file out.txt\n");
	     exit(1);
	}

	printf("DATA\tResult1\tResult2\n");
	
	while (fscanf(ifp, "%lf", &r)!=EOF){

	    a = 4 * PI * r * r;
	    v = 4.0 / 3.0 * r * r * r;

	    printf("%.2f\t%.2f\t%.2f\n", r, a, v);

            fprintf(ofp,"%.2f\t%.2f\t%.2f\n", r, a, v); 

	}

	fclose (ifp);
        fclose (ofp);

        return 0;
}
 
