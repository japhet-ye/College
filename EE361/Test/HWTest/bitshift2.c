#include<stdio.h>

int main(){
	int a = (27 ^ (1 << 3));
	int  b = (-1 >> 27) & (-2);
	
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
