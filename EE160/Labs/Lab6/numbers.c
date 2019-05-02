//Japhet Ye
//sumof.c
//September 28, 2016
//J Squared
#include<stdio.h>
//#define DEBUG 
int main()
{
    int count = 0,countpos = 0,countneg = 0;
    int evencount = 0,oddcount = 0,evenposcount = 0,negoddcount = 0;
    int x=0,y=0,z=0,sum=0,sumpos=0,sumneg=0,sumeven=0,sumodd=0,sumevenpos=0,sumnegodd=0;
    double flag;

    printf("Enter a Number:\n");
    flag = scanf("%d", &x);

    #ifdef DEBUG

    printf("%d", x);

    #endif

    while ( flag != EOF ){

        count = count + flag;
    
	#ifdef DEBUG

	printf("count %lf\n", count);
	printf("x %d\n", x);
	

	#endif
	
        if ( x > 0 )
        {
    	    if ( x % 2 == 0 )
	    {
	        evencount = evencount + 1;
	        
		evenposcount = evenposcount + 1;
	        
		sumeven = sumeven + x;
		
		sumevenpos = sumevenpos + x;

		#ifdef DEBUG
		
		printf("evencount %d\n", evencount);
		printf("evenposcount %d\n", evenposcount);
		printf("sumeven %d\n", sumeven);
		printf("sumevenpos %d\n", sumevenpos);
		
		#endif
	    }
	
	    else {
	    
	        oddcount = oddcount + 1;
		
		sumodd = sumodd + 1;

		#ifdef DEBUG

		printf("oddcount %d\n", oddcount);
		printf("sumodd %d\n", sumodd);

		#endif
	    }
	
	    countpos = countpos + 1;
	    
	    sumpos = sumpos + x;

	    #ifdef DEBUG
	    
	    printf("countpos %d\n", countpos);
	    printf("sumodd %d\n", sumodd);

	    #endif
        }

        if ( x < 0 )
        {
	    countneg = countneg + 1;

	    #ifdef DEBUG
	    
    	    printf("countneg %d\n", countneg);
	    
	    #endif
	
	    if ( x % 2 == 0 )
	    {
	        evencount = evencount + 1;
		
		sumeven = sumeven + x;

		#ifdef DEBUG
		
		printf("evencount %d\n", evencount);
		printf("sumeven %d\n", sumeven);
		
		#endif
	    }
   
	    else {
	     
	        oddcount = oddcount + 1;
	        
		negoddcount = negoddcount + 1;
	   	
		sumnegodd = sumnegodd + x;

		sumodd = sumodd + x; 
		
		#ifdef DEBUG

		printf("oddcount %d\n", oddcount);
		printf("negoddcount %d\n", negoddcount);
		printf("sumnegodd %d\n", sumnegodd);
		printf("sumodd %d\n", sumodd);

		#endif

	    }
	    
	    sumneg = sumneg + x;
	    
	    #ifdef DEBUG

	    printf("sumneg %d", sumneg);

	    #endif

	}
        
	sum = x + sum;

	#ifdef DEBUG

	printf("sum %d\n", sum);
	
	#endif

	printf("Enter a number:\n");
	flag = scanf("%d", &x);     
}	

    printf("The Sum of %d inputs is %d\n", count, sum);
    printf("The Sum of %d positive inputs is %d\n", countpos, sumpos);
    printf("The Sum of %d negative inputs is %d\n", countneg, sumneg);
    printf("The Sum of %d even inputs is %d\n", evencount, sumeven);
    printf("The Sum of %d odd inputs is %d\n", oddcount, sumodd);
    printf("The Sum of %d even positive inputs is %d\n", evenposcount, sumevenpos);
    printf("The Sum of %d negative odd numbers is %d\n", negoddcount, sumnegodd);

    return 0;        
}
