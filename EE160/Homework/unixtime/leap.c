int is_leap(int year){


   //ckecks to see if input is divisible by 4
   if ( year % 4 == 0) {

       //checks to see if it is also divisible by 100
       if ( year % 100 == 0) {

	    //checks if the input is also divisible by 400
	    if ( year % 400 == 0){
		
		return 1;
		
	    }
	    //if not dividible by 400
	    else 
	    return 0;
    	 }

       //If not divisible by 100, then its a leap year
       else {
	
	    return 1;

       } 

   }
   //not divisible by 4, not a leap year
   else 
	return 0;

}
