#include<stdio.h>

int main(){

    for( int i = 1; i<100;i++){

		printf("%d ",i);

		if((i % 3 == 0) && (i % 5 == 0))
	    	printf("PIZPAZ\n");

		else if (i % 3 == 0)
	    	printf("PIZ\n");

		else if (i % 5 == 0)
	    	printf("PAZ\n");

		else printf("%d\n",i);
    }

    return 0;

}
