#include<stdio.h>

int main(){
	int x;
	int y;
	char a;
	char b;

	int *p1 = &x;int *p2 = &y;
	char *p3 = &a; char *p4 = &b;

	printf("%d\n%d\n",p1,p2);
	printf("%d\n%d\n",p3,p4);

	return 0;
}
