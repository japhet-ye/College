#include<string>
#include<iostream>

bool is_palindrome(std::string input);

int main(){
	std::string w = "aaddaa";
	std::string x = "afasfsf";
	std::string y = "fwqgwqegq";
	std::string z = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	std::cout << "Is " << w << " a palindrome? " << is_palindrome(w) << std::endl;
	std::cout << "Is " << x << " a palindrome? " << is_palindrome(x) << std::endl;
	std::cout << "Is " << y << " a palindrome? " << is_palindrome(y) << std::endl;
	std::cout << "Is " << z << " a palindrome? " << is_palindrome(z) << std::endl;

	return 0;

}

bool is_palindrome(std::string input){

	auto back_it = input.rbegin();
	auto front_it = input.begin();

	while( (back_it != input.rend()) || (front_it != input.end()) ){
	
		if( (*back_it) != (*front_it) ){
			return 0;
		}
	
		back_it++;
		front_it++;

	}

	return 1;
}

