#include <iostream>
#include <SupplyRunner.hpp>
#include <Storeroom.hpp>
#include <vector>
using namespace std;
bool flag;

// supply runner -->ingredient, std::vector, std::move()/rvalues, Storeroom, std::map
// get ingredients from the store room
SupplyRunner::SupplyRunner(Storeroom& storeroom_):storeroom(storeroom_)  { }

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
    // for each ingredient in the IngredientMap 
    for(auto it = ingredients.begin();it!=ingredients.end();it++){
        flag = 1;
        // check if the ingrdient exists
        if((this->storeroom.find(it->first)) == this->storeroom.end()){
            // set error flag
            flag = 0;
            // if doesn't exists then throw
            throw "Ingredient not found";
        }
        // check if there is enough of ingredient
        else if((this->storeroom.find(it->first))->second < it->second){
            // set error flag
            flag = 0;
            // if there is not enough then throw
            throw "Not enough ingedients";
        }
    }
    
    //create vector to return ingredients
    vector<Ingredient> ans;

    // check if all ingredients exists and there is enough
    if(flag == 1) {
        // go through ingredient map
        for(auto it = ingredients.begin();it!=ingredients.end();it++){
            // append each ingredient to the ans vector how ever many times is needed
            for(int i = it->second; i > 0; i--) {
                ans.push_back(it->first);
            }
            // update the amount of ingredients in the storeroom
            this->storeroom.find(it->first)->second -= it->second;
        }
        //return ingredients as vector
        return ans;
    }
}


