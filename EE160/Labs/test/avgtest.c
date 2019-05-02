#include<stdio.h>

int main()
{
	double x, y, z, flag;
	printf("Enter Digit:");
	flag = scanf("%lf", &x);
	
	if ( flag == EOF )
	{
	    printf("TERMINATED\n");
	    return 0;
	}
	
	printf("Enter Digit:");
	flag = scanf("%lf", &y) + flag;

	if ( flag == EOF )
	{
	    printf("TERMINATED\n");
	    return 0;
	}
	
	z = ( x + y ) / flag;
	
	printf("%lf\n", z);

	return 0;

}
	
	
