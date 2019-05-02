#include <stdio.h>

void main () {

        //declare variables
        float x, y, xmin, xmax, slope, y_inter;

        //initialize variables
        float sumx = 0, sumy = 0, sumxx = 0, sumxy = 0;
        int count  = 0;

        //prints beginning of line 1 in output file
        printf("p = [");

        //gets first x and y values, incr count, and prints first y value
        int flag = scanf("%f %f", &x, &y);
        xmax = x;
        xmin = x;

        //as long as there are more inputs, run this loop
        while (flag != EOF) {

                //updates xmin and xmax
                if (x > xmax)
                        xmax = x;
                if (x < xmax)
                        xmin = x;

                //calcs sum of x, sum of y, sum of x*y, sum of x*x
                sumx = sumx + x;
                sumy = sumy + y;
                sumxx = sumxx + x*x;
                sumxy = sumxy + x*y;

                //prints y value on first line (p = [y, y,...)
                printf("%.2f", y);

                //increment count by 1
                count++;

                //gets new x and y, updates flag
                flag = scanf("%f %f", &x, &y);

                //inserts comma and space after input if  more inputs
                if (flag != EOF)
                        printf(", ");

        }


        //closes first line, prints second line
        printf("];");
        printf("\nx = linspace(%.2f, %.2f, %d);", xmin, xmax, count);

        //calculate the slope and y intercept
        slope = (sumx*sumy - count*sumxy) / (sumx*sumx - count*sumxx);
        y_inter = (sumx*sumxy - sumxx*sumy) / (sumx*sumx - count*sumxx);

        //prints third line
        printf("\ny =%.2f * x + %.2f;", slope, y_inter);

        //prints fourth and fifth line
        printf("\nplot(x, y ,x ,p, 'go')");
        printf("\ntext(0.5,100,'y = %.2f * x + %.2f');\n", slope, y_inter);

}
