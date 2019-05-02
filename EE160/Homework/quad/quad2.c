//J Squared
//quadfinal.c
//Homework 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    FILE *ifp, *ofp;
    double a, b, c, h, x1, x2, flag;

    //opens input file for reading
    ifp = fopen("input.txt", "r");

    //boots if file cannot be opened
    if ( ifp == NULL )
    {
        fprintf(stderr, "Can't Open input.txt\n");
        exit(1);
    }
 
    //opens output file for writing
    ofp = fopen("output.txt", "w");

    if ( ofp == NULL )
    {
        fprintf(stderr, "Can't Open output.txt\n");
        exit(1);
    }

    printf("A\tB\tC\tX1\t\t\tX2\n");
  
    //loop scan, reads file until the end of the file
    while (fscanf(ifp,"%lf %lf %lf", &a, &b, &c)!= EOF)
    {
        //checks if a = 0
	if ( a != 0 )
	{
	    //removes the need to check for b since if b = 0, h will be negative            //anyway, and also makes the syntax for the sqrt to be one variable
	    h = pow(b,2) - ( 4 * a * c );
	    //inaginary answer route
	    if ( h < 0 )
	    {
	        //printf("reading\n");
		h = abs(h);
		printf("Imaginary Answer\n");
		printf("%.2f\t%.2f\t%.2f\t%.2f+%.2fi/2%.2f\t%.2f-%.2fi/2%.2f\n",                a, b, c, b, h, a, b, h, a);
		//fscanf(ifp,"%lf %lf %lf", &a, &b, &c);
	    }
	    //real answer route
	    //note if h = 0, then it is a perfect square
	    if ( h > 0 && h == 0 )
	    {
	        x1 = (-b + sqrt(h)) / (2 * a);
		x2 = (-b - sqrt(h)) / (2 * a);

		printf("Real Answer\n");
		printf("%.2f\t%.2f\t%.2f\t%.2f\t\t\t%.2f\n",a,b,c,x1,x2);
		fprintf(ofp, "%f %f\n", x1, x1);
	    }
	    
	}    
	//linear answer route
        if ( a == 0) 
	{
	    x1 = -b/c;
	    printf("Linear Answer\n");
	    printf("%.2f\t%.2f\t%.2f\t%.2f\t\t\t0\n", a, b, c, x1);
	
	}
	
	
    	//flag = fscanf("%f %f %f", &a, &b, &c);
    }
    //end of file actions
    fclose (ifp);
    fclose (ofp);
    
    return 0;
}
