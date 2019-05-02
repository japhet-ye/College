#include<stdio.h>

int main(){

	float ans;
	float x;
	float temp;
	int flag;
	
	printf("Enter Resistor Value\n");
	flag = scanf("%f", &x);

	if (x > 0){
		temp = 1 / x;
	}

	else{
		printf("Invalid Number, Try Again\n");
		flag = scanf("%f", &x);
		if (x>0){
			temp = 1 / x;
		}
		else{
			printf("Fuck You\n");
			return 0;
		}
	}

	while (flag != EOF){

		printf("Enter Resistor Value\n");
		flag = scanf("%f", &x);
		if(x > 0){
			temp = temp + (1 / x);
		}
		else{
			ans = 1 / temp;
			printf("Equivilant Resistor is %0.2f\n", ans);
			return 0;
		}
	}

	ans = 1 / temp;
	printf("Equivilant Resistor is %0.2f\n", ans);
	return 0;
}
