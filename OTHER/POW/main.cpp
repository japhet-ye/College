#include<iostream>
#include<cmath>

double pow(double x, int n);


int main(){

	double p = 0.44894;
	int m = 2546;
	std::cout<< "1This is different "<<round(p) <<std::endl;

	return 0;

}


double pow(double x, int n){
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return x;

	}
	else if(n>1){
		double temp = 1;
		for(int i = 0;i<n;i++){
			temp = temp * x;
		}
		return temp;

	}
	else if(n < 0){
		double temp = 1;
		for(int i = 0;i>n;i--){
			temp = temp * x;
			std::cout<<"temp = "<<temp<<std::endl;
		}
		return (1.00/temp);

	}

}

