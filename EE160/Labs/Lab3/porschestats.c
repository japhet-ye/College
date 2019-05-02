//Japhet Ye
//J Squared
//September 8, 2016
//This program calculates the amount of gas a car uses


#include<stdio.h>

int main()

{
	//DECLAER VARIABLES
	
	//variable input
	double gallons_pumped;
	double price_of_gas;
	double miles_driven;

	//variable for calculation
	double total_price;
	double miles_per_gallon = 30;
	double cost_per_mile;
	

	//ask for variables
	printf("Enter Number of Gallons Pumped:");
	scanf("%lf", &gallons_pumped);	

	printf("Enter Price per Gallon:");
	scanf("%lf", &price_of_gas);
	
	printf("Enter Miles Driven Since Then:");
	scanf("%lf", &miles_driven);

	//calculation
	total_price = gallons_pumped * price_of_gas;

	cost_per_mile = total_price * (miles_per_gallon / miles_driven);
			

	//display of variables
	printf("%lf Gallons Pumped\n", gallons_pumped);

	printf("$%lf Per Gallon\n", price_of_gas);
	
	printf("$%lf Total Price of fill up\n", total_price);
	printf("%lf Miles Per Gallon\n", miles_per_gallon);
	printf("$%lf Per Mile\n", cost_per_mile);  
	
}	
