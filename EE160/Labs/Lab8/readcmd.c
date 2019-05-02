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

	printf("The command is: %c\n", cmd);
	skipOverRestOfCommand();
	cmd = skipblanks();

    }

}

int skipblanks(void){

    int c;

    c = getchar();
    while (c == ' ')
	c = getchar();
    return c;

}


int skipOverRestOfCommand(void){

    int c;

    c = getchar();
    while (c != '\n')
	c = getchar();
    return c;
}
