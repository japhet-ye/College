//Japhet Ye
//September 21, 2016
//J Squared
//This program takes the average of the inputs

#include<stdio.h>

int main()
{
	float x, y, z, flag, count, avg;
	printf("Enter an integer:");
	flag = scanf("%f", &x);
	
	if ( flag == EOF )
	{
		printf("\nTERMIMATED\n");
		return 0;
	}

	count = flag;
	//printf("%f\n", count);
	//printf("%f\n", flag);
	
	printf("Enter an integer:");
	flag = scanf("%f", &y);
	    
	if (flag == EOF)
	{
		avg = x / count;
		
		printf("\nAverage of %f input is %f\n", count, avg);
		
		return 0;
	}
	    
	z = x + y;
	count = flag + count;
	//printf("%f\n", z);
	//printf("%f\n", count);
	//printf("%f\n", flag);
	while (flag != EOF)
	{    
		printf("Enter an integer:");
		flag = scanf("%f", &x);
		
		if ( flag == EOF )
		{
			avg = z / count;
			
			printf("\nAverage of %f input is %f\n", count, avg);
			return 0;
		}
		
		z = z + x;
		count = flag + count;
	
		printf("Enter an integer:");
		flag = scanf("%f", &y);

		if ( flag == EOF )
		{
			avg = z / count;

			printf("\nAverage of %f input is %f\n", count , avg);
			return 0;
		}
		
		z = z + y;
		count = flag + count;
	}

	return 0;	
}
	    
	    

