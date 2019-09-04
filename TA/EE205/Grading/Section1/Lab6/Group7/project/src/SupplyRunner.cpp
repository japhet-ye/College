#include <map>
#include <iostream>
#include <vector>
#include "SupplyRunner.hpp"
using namespace std;
/**
 * @brief Constructs a SupplyRunner with the Storeroom it gets its 
 * Ingredients from.
 */
SupplyRunner::SupplyRunner(Storeroom& storeroom_):storeroom(storeroom_) {}
/**
 * @brief Gets ingredients from the Storeroom, if they exist, as a vector.
 *
 * @note Will remove ingredients from the storeroom if all the ingredeints 
 * asked for are all found in sufficient numbers.
 *
 * @throws const char* if there are not enough ingredients in the Storeroom.
 *
 * @note Upon not finding enough ingredients to return, the SupplyRunner 
 * will not modify the Storeroom in any way, including removing Ingredients 
 * from the Storeroom (decreasing the Ingredient count on the map).
 */

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients){
    std::vector<Ingredient> foodvect;
    for(auto i = ingredients.begin(); i != ingredients.end(); i++){
        if(storeroom.count(i->first)){
            if(storeroom.at(i->first) >= i->second){}
            else
                throw "Not enough";
        }
        else 
            throw "Missing Ingredient";
    }
    for(auto i = ingredients.begin(); i != ingredients.end(); i++){
        //extract ingredient count in storeroom
        int ingredcount = storeroom.at(i->first);
        //update count by subtraction
        ingredcount -= i->second;
        //update count in storeroom
        storeroom.at(i->first)=ingredcount;
        for(unsigned int x = 0; x < i->second; x++){
        //add ingredients to ingredient vector by appending
            foodvect.push_back(i->first);
        }
    }
    return foodvect;
}