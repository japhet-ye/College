#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char* token;
	char delim[] = " ";

	int i = 0;

	int a[100];
	int j = 0;


	fp = fopen("input.txt","r");
	if (fp == NULL){
		printf("cannot open input.txt\n");
		return 0;
	}

	while((read=getline(&line,&len,fp))!=-1){
		for(token=strtok(line,delim);token;token=strtok(NULL,delim)){
			if (i == 1){
				a[j] = atoi(token);
				j++;
			}
			i++;
		}
		i = 0;
	}
	for(j = 0;j<3;j++){
		printf("a[j] = %d\n",a[j]);
	}
	return 0;

}
