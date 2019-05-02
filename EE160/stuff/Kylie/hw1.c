#include<stdio.h>

float jog(int total);
float holo(float total);

int main(){

	/*variables that need to be scanned in*/
	float fminutes, fseconds;
	/*total minutes as calculated by each company*/
	int totaljog = 0;
	float totalholo = 0;
	/*bill from each comapny*/
	float jogprice,holoprice;
	/*conversion variable for floats*/
	int iminutes = 0;
	/*check for while loop*/
	int check = 1;

	/*initial scan for variables in file*/
	check = scanf("%f %f",&fminutes,&fseconds);
	
	/*while loop for the file*/
	while (check != EOF){
		/*converts minutes and seconds to decimal seconds
 * 		2minutes 30 seconds = 2.5 minutes*/
		fminutes = fminutes + (fseconds / 60);
		/*Holo takes this total and round later*/
		totalholo = fminutes + totalholo;
		/*Jog needs to round each call first*/
		/*replace this with your round up function delete this 
 * 		comment later*/
		iminutes = round_to_int(fminutes);
		/*Jog calculates from rounded minutes*/
		totaljog = totaljog + iminutes;
		/*scans next line*/
		check = scanf("%f %f",&fminutes,&fseconds);
	}
	/*gets total price from minutes*/
	jogprice = jog(totaljog);
	holoprice = holo(totalholo);
	
	/*print price*/
	printf("Bill from Jog:$%.2f\n",jogprice);
	printf("Bill from Holo:$%.2f\n",holoprice);

	return 0;
}

float jog(int total){
	float price;
	/*Need to cast since price calculation has a decimal number*/
	price = 0.05 * (float)total;

	return price;
}
float holo(float total){
	float price;
	int minutestotal;
	
	/*rounds total to nearest integer*/
	/*again placeholder for your round function*/
	minutestotal = round_to_int(total);
	/*need to cast since price calculation has a decimal number*/
	price = 0.07 * (float) total;

	return price;

}

