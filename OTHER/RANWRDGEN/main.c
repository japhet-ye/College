#include<iostream>
#include<cstdlib>
#include<string>
#include<unistd.h>

int main(){

	int wordlength;
	unsigned int t = 50;
	srand(time(NULL));
	std::string a;
	usleep(t);
	int x = rand() % 26;
	
	std::cout<<"Choose the length of the word"<<std::endl;
	std::cin>>wordlength;

	for(int i = 0;i<wordlength+1;i++){
		a.push_back('A' + x);

		usleep(t);
	
		x = rand() % 26;

	}

	std::cout<<"Your Word Was: "<<a<<std::endl;
	
}
