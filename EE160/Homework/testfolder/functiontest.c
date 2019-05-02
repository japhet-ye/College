#include<stdio.h>

double test( double x);

int main()
{
	double x, y;
	
	printf("Enter X\n");
	scanf("%lf", &x);
	y = test(x);

	printf("%lf\n", y);	

	return 0;
}

double test( double x)
{
	double y;
	y = x + 3;
	return y;
}

