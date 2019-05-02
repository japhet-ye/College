//Japhey Ye
//pryamid.c
//
#include<stdio.h>

int main(){

    char c;
    int flag, h, r, co, printb, printc = 0;
    
    printf("Enter Character to print\n");
    flag = scanf("%c", &c);

    printf("Enter height of pyramid\n");
    flag = scanf("%d", &h);

    //while ( flag != EOF ){

        //printf("Enter height of pyramid\n");
	//scanf("%d", &h);

	for (r=1;r<=h;r++){
	
	    for (co=1;co<=(h-r);co++){
		
		printf(" ");		
	    }
	
	    while (printc != ((2*r)-1)){	
		printf("%c", c);
		printc++;
	    }
	    printc = 0;
	    printf("\n");

	}

	//printf("Enter Character to print\n");
	//scanf("%c", &c);

	//printf("Enter height of pyramid\n");
	//flag = scanf("%d", &h);


    //}
    return 0;


}
