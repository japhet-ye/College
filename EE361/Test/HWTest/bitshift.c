#include<stdio.h>

int binary_conversion(int num);

int main(){
	int a = 27 ^ (1 << 3);
	int test = 1 << 3;

	int test2 = (-1 >> 27); //& (-2);
	printf("test2 = %d\n",test2);

	int binary27 = binary_conversion(27);
	int binarytest = binary_conversion(test);
	int binaryanswer = binary_conversion(a);

	printf("binary27 = %d\nbinarytest = %d\n",binary27,binarytest);
	printf("binaryanswer = %d\n",binaryanswer);
	printf("test = %d\na = %d\n",test,a);

	return 0;
}

int binary_conversion(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}
