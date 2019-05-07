#include<vector>
#include<iostream>

int find_duplicate(std::vector<int> input);

int main(){

	std::vector<int> w = {1,2,3,4,5,6,7,1};

	std::cout << "The duplicate in the array:";
	
	for(int i = 0; i < w.size();i++){
		std::cout << " " << w[i] << " ";
	}
	
	std::cout << " is " << find_duplicate(w) << std::endl;

	return 0;

}

int find_duplicate(std::vector<int> input){
	int check = input[0];

	for(int i = 1; i < input.size(); i++){
		check ^= input[i];
	}

	return check;

}
