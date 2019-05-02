//Japhet Ye
//quadratic-complex.c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct comp {

    double real;
    double imag;

};

void quadratic( double a, double b, double c);

int main() {

    //struct comp x1;
    //struct comp x2;

    FILE *ifp, *ofp;

    ifp = fopen("input.txt", "r");

    if (ifp == NULL){

        fprintf(stderr, "Can't Open input.txt\n");
        exit(1);
    }

    ofp = fopen("output.txt", "w");

    if ( ofp == NULL ){

        fprintf(stderr, "Can't Open output.txt\n");
        exit(1);
    }

    double a, b, c, ans;

    printf("x1\t\tx2\n");		


    while ((fscanf(ifp, "%lf %lf %lf", &a, &b, &c)) != EOF){
        
         quadratic(a,b,c);

    }

}


void quadratic( double a, double b, double c){

    struct comp x1;
    struct comp x2;

    double d;
    double ans;

    if ( a != 0 ){

        d = (b * b) - (4 * a * c);
    
        if ( d > 0 || d == 0 ){

            x1.real = (-b + sqrt(d)) / ( 2 * a );
            x2.real = (-b + sqrt(d)) / ( 2 * a );
   
            x1.imag = 0;
            x2.imag = 0;
        }

        else {

            x1.real = -b / ( 2 * a );
            x2.real = x1.real;
            x1.imag = sqrt(-d) / ( 2 * a );
            x2.imag = -x1.imag;

        }

        printf("%.2f  %.2f i\t%.2f  %.2f i\n", x1.real, x1.imag, x2.real, x2.imag);

    }

    if ( a == 0 ){

        printf("%.2f\t\t0\n", c);

    }

}
