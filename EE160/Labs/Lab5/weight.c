//Japhet Ye
//September 22, 2016
//J Squared
//This program calculates the weighted average
//
//
#include<stdio.h>

int main()
{

	float x, y, z, w1, w2, wt, avg, flag, count;

	printf("Enter Value and It's Weight:\n");
	flag = scanf("%f %f", &x, &w1);

	if ( flag == EOF )
	{
		printf("TERMINATED\n");
		return 0;
	}

	z = x * w1;
	wt = w1;
	//printf("%f flag", flag);
	count = flag - 1;
	
	printf("Enter Value and It's weight:\n");
	flag = scanf("%f %f", &y, &w2);

	if ( flag == EOF )
	{
		avg = z / wt;
		printf("The Weighted Average of %f input is %f\n", count, avg);
		return 0;
	}
	
	z = ( y * w2 ) + z;
	wt = w1 + w2;
	count = ( flag - 1 ) + count;
	
	while ( flag != EOF )
	{
		printf("Enter Value and It's Weight\n");
		flag = scanf("%f %f", &x, &w1);

		if ( flag == EOF )
		{
			avg = z / wt;
			printf("The Weighted Average of %f input is %f\n", count			, avg);
			return 0;
		}

		z = ( x * w1 ) + z;
		wt = w1 + wt;
		count = ( flag - 1 ) + count;

		printf("Enter Value and It's Weight\n");
		flag = scanf("%f %f", &y, &w2);
		
		z = ( y * w2 ) + z;
		wt = w2 + wt;
		count = ( flag - 1 ) + count;
	
		if ( flag == EOF )
		{
			avg = z / wt;
			printf("The weighted Average of %f input is %f\n", count
				, avg);
			return 0;
		}
	}
	
}
