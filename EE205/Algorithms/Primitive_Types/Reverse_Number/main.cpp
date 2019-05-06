#include<iostream>

unsigned int reverse_number(unsigned int input);

int main(){

	int x = 33;
	int y = 45;
	int z = 100;

	std::cout<<"Reversing "<<x<<" gives you "<<reverse_number(x)<<std::endl;
	std::cout<<"Reversing "<<z<<" gives you "<<reverse_number(z)<<std::endl;
	std::cout<<"Reversing "<<y<<" gives you "<<reverse_number(y)<<std::endl;

	return 0;

}

unsigned int reverse_number(unsigned int input){
	unsigned int output = input % 10;
	input /= 10;
	while(input > 0){
		output *= 10;
		output += input % 10;
		input /= 10;
	}
	return output;
}
