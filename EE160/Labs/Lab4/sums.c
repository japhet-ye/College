//Japhet Ye
//September 14, 2016
//J Squared
//This program sums the two inputs given

#include<stdio.h>

int main()

{

	double x;
	double y;
	double z;
	double flag;
	
	printf("Enter First Digit ^D to Cancel\n");
	flag = scanf("%lf", &x);


	printf("Enter Next Digit ^D to terminate\n");
	flag = scanf("%lf", &y);
	
	z = x + y;
	
	if ( flag == EOF )
	    {
	        
		printf("%.1f\n", z);
	        printf("TERMINATED\n");
	   	return 0;
	    }
	    
	//printf("%.2f\n", z);
	
	while ( flag != EOF )
	    {

	        printf("Enter Next Digit ^D to terminate\n");
	        flag = scanf("%lf", &x);
	
	        if ( flag == EOF)
	        { 
	    	    printf("TERMINATED\n");
	    	    return 0;
	        } 
	
	        z = z + x;

	        printf("%.1f\n", z);
	    
	        printf("Enter Next Digit ^D to terminate\n");
	        flag = scanf("%lf", &y);
	
	        if ( flag == EOF)
	        {
	    	    printf("TERMINATED\n");
	    	    return 0;
	        }

	        z = z + y;

	        printf("%.2f\n", z);
	    }
	
	return 0;
}

	
