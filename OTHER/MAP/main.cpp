#include<iostream>
#include<map>

int main(){

	std::map<int,int> m={{1,2},{3,4}};
	std::map<int,int>::iterator it;

	it = m.begin();

	for(it = m.begin();it!=m.end();it++){

		std::cout<<it->first<<", "<<it->second<<std::endl;

	}

	// std::cout<<it->first<<std::endl;
	// std::cout<<it->second<<std::endl;

	// it++;
	
	// std::cout<<it->first<<std::endl;
	// std::cout<<it->second<<std::endl;

	// it->second = it->second - 1;

	// std::cout<<it->second<<std::endl;	
	std::cout<<"SUCCESS"<<std::endl;	
	return 0;

}
