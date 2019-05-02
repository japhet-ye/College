



#include<stdio.h>
#include<math.h>

int main()
{
	float h, a, b, c;

	printf("enter a\n");
	scanf("%f", &a);

	printf("enter b\n");
	scanf("%f", &b);

	printf("enter c\n");
	scanf("%f", &c);

	h = pow(b,2) - ( 4 * a * c );

	printf("%f\n", h);
	
	return 0;

}

