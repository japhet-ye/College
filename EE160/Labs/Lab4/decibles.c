//Japhet Ye
//J Squared
//September 14, 2016
//this program is designed to calculate the decible levels of
//certain ratios

#include<stdio.h>
#include<math.h>

int main()

{

	double i; //this is the ration I/IO
	double d; // this is the output
	double flag;

	//ask for input
	printf("Enter decible ration I/IO\n");
	flag = scanf("%lf", &i);

	while ( i > 0 && flag != EOF) {

		double d = 10 * log10( i );

		printf("%.2f decibles\n", d);
	
		printf("Enter decible ration I/IO\n");
		flag = scanf("%lf", &i);

	}

	printf("Not a Valid Input\n");
	
	return 0; 
	     
}	

	
	

