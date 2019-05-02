#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = " ,.-?;:";
    char* token;

    fp = fopen("tokenize.txt", "r");
    if (fp == NULL)
	return -1;

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s\n", line);

	/****   AT THIS POINT YOU HAVE A STRING CALLED line *****  /
 * 	* this is the place to put the tokenizing code */
        /* tokenize array caled line */

        for (token = strtok(line, delim); token; token = strtok(NULL, delim))
        {
            printf("token=%s\n", token);
        }

    }

    fclose(fp);
    if (line)
        free(line);
    return 0;
}
