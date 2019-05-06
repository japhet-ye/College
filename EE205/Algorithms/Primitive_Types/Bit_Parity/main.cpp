#include<iostream>

bool bit_parity(unsigned int input);

int main(){
	
	unsigned int x = 1;
	unsigned int y = 3;
	unsigned int z = 7;

	std::cout<<"The bit parity of "<<x<<" is: "<<bit_parity(x)<<std::endl;
	std::cout<<"The bit parity of "<<y<<" is: "<<bit_parity(y)<<std::endl;
	std::cout<<"The bit parity of "<<z<<" is: "<<bit_parity(z)<<std::endl;

	return 0;
}

bool bit_parity(unsigned int input){
	bool output = 0;

	while(input != 0){
		input &= input - 1;
		output ^= 1;
	}

	return output;
}

