//Japhet Ye
//J squared S
//pos_power.c
//September 29, 2016
float pos_power ( float x, float y){

    float z, start, stop = y;

    if ( y < 0 ){

        return -1;
    
    }

    if ( y == 1 ) {

        return x;

    }

    if ( y == 0 ) {

	return 1;

    }

    z = x * x;
    
    while ( stop > 0  && stop != 2 ) {

	z = z * x;

	stop = stop - 1;

    }

    return z;


}
