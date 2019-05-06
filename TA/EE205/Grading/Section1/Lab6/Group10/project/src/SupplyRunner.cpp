#include "Storeroom.hpp"
#include "Ingredient.hpp"
#include "SupplyRunner.hpp"
#include <string>
#include <vector>
#include <map>

SupplyRunner::SupplyRunner(Storeroom& storeroom_):storeroom(storeroom_){}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients){
    std::vector<Ingredient> stuffToCook;
    IngredientMap::iterator i;
    int test=0;
    
    //test to see if storeroom has enough ingredients
    try{

        //iterate through map
        for(i=ingredients.begin();i!=ingredients.end();i++){ 
            //checks if storeroom has that ingredient
            if(storeroom.count(i->first) == 1){
                //if found, verify that there is enough of that ingredient in storeroom
                if(i->second <= storeroom[i->first]){
                    test++;
                }
                //if not enough throw error
                else {
                    throw "e";
                }
            }
            //if not found throw error
            else{
                throw "e";
            }
        }
    }
    catch (const char*){
        throw "Not enough ingredients";
    }  

    
    //try-catch statement should generate a test number that matches the size of the ingredient map
    //this means that all ingredients are found and storeroom has enough each ingredient
    if(test==(int)ingredients.size()){
        //iterate through ingredient map
        for(i=ingredients.begin();i!=ingredients.end();i++){
            //find ingredient in storeroom
            if(storeroom.find(i->first) != storeroom.end()){
                //push ingredient name into std::vector<Ingredient>
                //should repeat based upon how much of each ingredient needed
                for(int j = 0; j<(int)i->second; j++){
                    stuffToCook.push_back(i->first);
                }
                //if storeroom quantity is greater than needed ingredient amount
                //subtract needed ingredient amount from storeroom quantity
                if(storeroom.at(i->first) > i->second){
                    storeroom.at(i->first) = storeroom.at(i->first) - i->second;
                }
                
                //if ingredient amount is same as storeroom quantity
                //remove ingredient from storeroom
                else {
                    storeroom.erase(i->first);
                }
            }
            
        }
    }

return stuffToCook;
}
