//Japhet Ye
//J Squared
//Spetember 11, 2016
//This is the first homework assignment requiring us to 
//program the quadratic formula 

#include<stdio.h>

#include<math.h>

int main()

{

	//a, b , c are variables
	//z is used for anything under the squareroot is negative
	//Note: if squareroot is negative, it does not exist on the real plane
	//but rather the imaginare plave sqrt-1 is imaginary and has its own 
	//plane
	//h is used when the squareroot is positive
	//Note: when squareroot is positive it exists on the real plane
	float a, b, c, z, h, x1, x2, flag;

	//ask for variables
	printf("Enter A\n");
	scanf("%f", &a);

	//if (flag == EOF)
	//{
	   // printf("TERMINATED\n");
	    //return 0;
	//}

	printf("Enter B\n");
	scanf("%f", &b);
	
	//if (flag == EOF)
	//{
	   // printf("TERMINATED\n");
	   // return 0;
	//}
	    

	printf("Enter C\n");
	scanf("%f", &c);

	//if (flag == EOF) 
	//{
	    //printf("TERMINATED");
	    //return 0;
	//}

	//b sqaured minus 4ac
	
	 h = pow(b,2) - (4 * a * c);

	//looping to make sure the user wants more calculations
	//h > 0 so the function is on the real plane
	while ( h > 0 )
	{
	    float x1 = ( -b + sqrt(h) ) / ( 2 * a );
	    float x2 = ( -b - sqrt(h) ) / ( 2 * a );

	    printf("(x-%.2f)(x-%.2f)\n", x1, x2);
	    
	    printf("Enter A\n");
	    scanf("%f", &a);

	    printf("Enter B\n");
	    scanf("%f",&b);

	    printf("Enter C\n");
	    scanf("%f", &c);
	    
	    float h = pow(b,2) - ( 4 * a * c );
   	}
	
	printf("Not A Real Function\n");

	return 0;	 
}
