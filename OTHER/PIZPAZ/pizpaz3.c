#include<stdio.h>

int main(){

    int number;
    int check = 1;
    int flag = 42;

    while (flag != EOF){ 
         while (check == 1){
            printf("What number to PIZPAZ do you want?: ");
            flag = scanf("%d",&number);
	    printf("\n");

	    if(flag == EOF)
	        return 0;
	    	
	    else if(number < 1)
	         printf("Please enter a valid number\n");

	    else
	        check = 0;

        }

        for( int i = 1; i<(number + 1);i++){

	    printf("%d ",i);

	    if((i % 3 == 0) && (i % 5 == 0))
	        printf("PIZPAZ\n");

	    else if (i % 3 == 0)
	        printf("PIZ\n");

	    else if (i % 5 == 0)
	        printf("PAZ\n");

	    else printf("PUPPY\n");
        }
	
	check = 1;

    }

}
