#include<iostream>

unsigned int reverse_bits(unsigned int input);

int main(){
	int x = 33;
	int y = 45;
	int z = 100;

	std::cout<<"Reversing "<<x<<" gives you "<<reverse_bits(x)<<std::endl;
	std::cout<<"Reversing "<<z<<" gives you "<<reverse_bits(z)<<std::endl;
	std::cout<<"Reversing "<<y<<" gives you "<<reverse_bits(y)<<std::endl;

	return 0;
}

unsigned int reverse_bits(unsigned int input){
	
}
