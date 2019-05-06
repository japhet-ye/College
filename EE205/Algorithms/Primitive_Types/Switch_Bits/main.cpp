#include<iostream>

unsigned int switch_bits(unsigned int input,int x, int y);

int main(){
	
	unsigned int w = 137;
	unsigned int x = 41802;
	unsigned int y = 22351;
	unsigned int z = 13273;


	std::cout<<"The result of switching the 10 and 32 bit of "<<w<<" is "<<switch_bits(w,10,32)<<std::endl;
	std::cout<<"The result of switching the 10 and 32 bit of "<<x<<" is "<<switch_bits(x,10,32)<<std::endl;
	std::cout<<"The result of switching the 10 and 32 bit of "<<y<<" is "<<switch_bits(y,10,32)<<std::endl;
	std::cout<<"The result of switching the 10 and 32 bit of "<<z<<" is "<<switch_bits(z,10,32)<<std::endl;
}


unsigned int switch_bits(unsigned int input,int x, int y){
	unsigned int mask = input & (1 << x);
	mask |= input & (1 << y);
	return input ^ mask;
}
