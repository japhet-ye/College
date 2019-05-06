#include "SupplyRunner.hpp"

#define TRUE 1
#define FALSE 0

//Constructor that takes in storeroom to be used w/SupplyRunner
SupplyRunner::SupplyRunner(Storeroom& storeroom_) : storeroom(storeroom_) {}

//Pulls requested ingredients from Storeroom and returns as a vector
std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
     //Check if all ingredients are present in storeroom
     bool ing_pres = TRUE;
     for(IngredientMap::iterator test = ingredients.begin();
         test!=ingredients.end(); ++test) {
          if( storeroom[test->first] < test->second ) { ing_pres = FALSE; }
     }
     //If not all ingredients present, throw an exception
     if(!ing_pres) { throw "Missing Ingredients"; }
     //If all ingredients present, update storeroom and send ingredients as vector
     unsigned ing_count = 0;
     vector<Ingredient> to_cook;
     for(IngredientMap::iterator current = ingredients.begin();
         current!=ingredients.end(); ++current ) {
          storeroom[current->first] -= current->second;
          ing_count = current->second;
          while(ing_count > 0) {
               to_cook.push_back(current->first);
               ing_count--;
          }
     }

     return to_cook;
}

