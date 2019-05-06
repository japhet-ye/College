#include "SupplyRunner.hpp"

SupplyRunner::SupplyRunner(Storeroom& storeroom_):
	storeroom(storeroom_){
}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients){
	//string of vectors called grab
	std::vector<std::string> grab;

	int discover = 0;
  	//iterate through ingrediants
  	for(auto i = ingredients.begin(); i != ingredients.end(); i++){
		//iterate through storeroom
    		for(auto stroom = storeroom.begin(); stroom != storeroom.end(); stroom++){
      			if(i->first == stroom->first){
        			discover = 1;
        			//check ingredients amount
        			if(i->second > stroom->second){
          				throw "SupplyRunner.get_ingredients: Not enough ingredients!";
        			}
      			}
    		}
		//throw exception
  		if(discover == 0){
   			throw "SupplyRunner.get_ingredients: Ingredient not found!";
		}
  	}
	//iterate through ingredients
  	for(auto i = ingredients.begin(); i != ingredients.end(); i++){
    		//iterate through storeroom
		for(auto stroom = storeroom.begin(); stroom != storeroom.end(); stroom++){
      			if(i->first == stroom->first){
				//for all removed ingrediant store into vector
        			for(unsigned int j = 0; j < i->second; j++){
          				grab.push_back(i->first);
          				stroom->second--;
        			}
      			}
    		}
  	}
  	return grab;
}
