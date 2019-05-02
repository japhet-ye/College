//Japhet Ye
//infostruct.c
//JS
#include<stdio.h>
#include<string.h>
#define N 10

struct id{

    char string[N];
    int age;
    float w;

} ;

void print(struct id record);

int main() {

    struct id record;
    struct id record2;

    strcpy(record.string,"Alice");
    strcpy(record2.string,"Bob");

    record.age = 23;
    record2.age = 24;

    record.w = 160.4;
    record2.w = 202.8;

    print(record);
    print(record2);
    return 0;
}



void print(struct id record){

    printf("%s\t", record.string);
    printf("%d\t", record.age);
    printf("%f\n", record.w);

}
