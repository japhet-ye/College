//Japhet Ye
//J Squared
//Septe,ber 8, 2016
//this program calculates the cost of a car

#include<stdio.h>


int main()
{

	//constamts
	float discount_rate = 0.12;
	float luxury_tax_base = 30000.00;
	float luxury_tax_rate = 0.10;
	float sales_tax_rate = 0.0417;

	double sticker_price;
	double discount_price;
	double taxes;
	double final_cost;

	//ask for sticker price
	printf("Enter sticker Price: \n");
	scanf("%lf", &sticker_price);

	//compute dicount price
	discount_price = sticker_price - sticker_price * discount_rate;

	//compute taxes
	taxes = ((discount_price - luxury_tax_base) * luxury_tax_rate) + (discount_price * sales_tax_rate);

	//compute final price
	final_cost = discount_price + taxes;

	//output results
	printf("Sticker Price:%.2f \n", sticker_price);
	printf("Price After %.1f%%  discount: %.2f\n", 
		discount_rate * 100, discount_price);
	printf("Taxes (luxury and sales): %.2f\n", taxes);
	printf("Total Cost: %.2f\n", final_cost);
	
	return 0;

}

	
