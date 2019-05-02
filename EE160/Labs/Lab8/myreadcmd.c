//Japhet Ye
//October 13, 2016
//readcmd.c
#include<stdio.h>

int skipblanks(void);
int skipOverRestOfCommand(void);

int main() {

    int cmd;

    cmd = skipblanks();
    
    while (cmd != EOF){

	if ( (cmd < 65 || cmd > 122) && (cmd > 90 || cmd < 97))
	    printf("Not A Valid Input\n");

	else
	    printf("The command is: %c\n", cmd);
		
	skipOverRestOfCommand();
	cmd = skipblanks();
	}

     return 0;

}
int skipblanks(void){

    int c;

    c = getchar();
    while (c == ' ' || c == '\t' || c=='\n')
	c = getchar();
    return c;

}


int skipOverRestOfCommand(void){

    int c;

    c = getchar();

    while (c != '\n'){
	
	if ( c == ';' )
	    return c;
	
	c = getchar();
    }
    return c;
}
