//Japhet Ye
//piGrLe.c
#include<stdio.h>
#include<math.h>
double power(double x);
double abso(double y);
int main(){

    double numer, k, denom, n, sum = 0, frac, er, erc;
    int flag;

    //printf("Enter N Value for Gregory-Liebniz series\n");
    //flag = scanf("%lf", &n);

    printf("Enter error for PI\n");
    flag = scanf("%lf", &er);

    while (flag != EOF){
	
	erc = 1;
	
	for(k = 1; erc>=er; k++){

	    numer = 4 * power(k);
	    denom = (2*k) - 1;
	
	    //printf("%lf\n", numer);
	    //printf("%lf\n");


	    frac = numer/denom;

	    //printf("%lf\n", frac);

	    sum = sum + frac;
	    //sum = sum * 4;

	    erc = sum - M_PI;

	    printf("%lf\n", erc);

	    erc = abso(erc);

	}
	
	printf("%lf\n", sum);
	printf("%lf\n", erc);
	sum = 0;

	//printf("Enter Value N for Gregory-Liebniz series\n");
	//flag = scanf("%lf", &n);

	printf("Enter Error for PI\n");
    	flag = scanf("%lf", &er);
    }


    return 0;



}

double power(double x){

    double y = -1, n;

    for (n = 0; n<x; n++){

	y = y * -1;
    }
    return y;

}

double abso(double y){

    if (y<0){
	y = y * -1;
	return y;
    }

    else
        return y;

}
