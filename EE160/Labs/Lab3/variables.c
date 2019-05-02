//Japhet Ye
//J Squared 
//September 8, 2016
//This program is designed for 
//

#include<stdio.h>

int main()

{
	int k;
	
	float z;

	k = 1;

	printf("k=%d \n", k); 		

	k = 2.5;

	printf("k=%d \n", k); //k only prints 2 because 2.5 is a float value
			      // and k is decalred as an integer so the
			      // computer ignores the .5 and outputs 2  

	z = 2.3;

	printf("z=%f \n", z); //2.3 is a vaild float number and the computer
			      // outputs accourdingly

	k = 1 / 2;           // k is zero because 0.5 is not a vaild digit

	printf("k=%d \n", k);

	z = 1 / 2;  //its zero because 1 and 2 need to be float vaules
		    // otherwise the computer sees 0 like in k

	printf("z=%f \n", z);

	k = 1 + (1 / 2);   //0.5 is zero to the computer so it really is 1+0
			   //which is zero

	printf("k=%d \n", k);

	z = 1 + ( 1 / 2 ); //there needs to be at least one float digit
			  // since z is a float value

	printf("z=%f \n", z);

	k = 1.0 / 2.0;

	printf("k=%d \n", k); // k is defined as an integer so it will
			      //never output decimals even though you do
			      //legal float arithmetic

	k = 1.0 / 2;

	printf("k=%d \n", k);

	k = 1 / 2.0;

	printf("k=%d \n", k);

	z = 1.0 / 2.0;	// this is legal float arithmetic where at least one
			// value is a float value
   	
	printf("z=%f \n", z);
	
	z = 1.0 /2 ;
 	
	printf("z=%f \n", z);
	
	z = 1 / 2.0;

	printf("z=%f \n", z);
	
	k = z + 1;	       //k is a integer and does not read decimal values				// so it outputs 1 + 0 since 0=0.5 in
				//integer arithmetic
	
	printf("k=%d \n", k);
	
	k = z + 1.0;
	
	printf("k=%d \n", k);
	
	k = k + 1;		//legal integer arithmetic, there is no
				//decimal places to take into account 
	
	printf("k=%d \n", k);
	
	z = z + 1; 		//legal float arithmetic since z is already a
				//float value
	
	printf("z=%f \n", z);





}


