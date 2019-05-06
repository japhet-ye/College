#include "SupplyRunner.hpp"



//parameterized constructor
SupplyRunner::SupplyRunner(Storeroom& storeroom_): storeroom(storeroom_) {}

//getter
std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients){

    //declare variables
    bool foundIngredient = false;

    std::map<Ingredient, unsigned>::iterator it1 = ingredients.begin();
	std::map<Ingredient, unsigned>::iterator it2 = storeroom.begin();

    //go through list of ingredients needed by cook
    while(it1 != ingredients.end()){
        //go through ingredients in storeroom
        while(it2 != storeroom.end()){
            if((it1->first == it2->first) && (it1->second <= it2->second)){
                foundIngredient = true;
            }
            it2++;
        }
        
        if(foundIngredient == true){
            foundIngredient = false;
            it2 = storeroom.begin();
        }

        else{
            throw "Not enough ingredient/not found in storeroom";
        }

        it1++;

    }

    //reset iterators
    it1 = ingredients.begin();
    it2 = storeroom.begin();

    //go through and remove ingredients
    while(it1 != ingredients.end()){
        while(it2 != storeroom.end()){
            if(it1 -> first == it2->first){
                it2->second -= it1->second;
            }
            it2++;
        }
        it1++;
        //reset storeroom interator
        it2 = storeroom.begin();
    }

    //reset interator
    it1 = ingredients.begin();
    std::vector<Ingredient> returnIngredient;

    while(it1 != ingredients.end()){
        for(unsigned count = 0; count < it1->second; count++){
            returnIngredient.push_back(it1->first);
        }

        it1++;

    }
    return returnIngredient;

}

