#include<stdio.h>
#include<stdlib.h>


int main(){

	FILE * fp;
	int x,y,z,a,b,c;
	int check;

	fp = fopen("output2.txt", "r");
	if (fp == NULL)
		return -1;

	check = fscanf(fp,"%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);

	while(check != EOF){
		printf("x = %d\n y = %d \nz = %d \na = %d\nb = %d\nc = %d\n",x,y,z,a,b,c);
		check = fscanf(fp,"%d %d %d %d %d %d", &x,&y,&z,&a,&b,&c);
	}
	fclose(fp);
	return 0;
}
