#include "Storeroom.hpp"
#include "Ingredient.hpp"
#include "SupplyRunner.hpp"

#include <string>
#include <vector>
#include <map>

#define FALSE 0
#define TRUE 1

//Constructor
SupplyRunner::SupplyRunner(Storeroom& storeroom_) : storeroom(storeroom_){}

//Get Ingredients
std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients){
        IngredientMap::iterator SRIT = ingredients.begin();//Initialize iterators
        IngredientMap::iterator it = storeroom.begin();//SRIT is supply runner iterator
        std::vector<Ingredient> collected;//Create output vector

        //If the list of ingredients is one ingredient long
        if(ingredients.begin() == ingredients.end()){
                for(bool found = FALSE; found == TRUE;){
                        if(SRIT->first == it->first){//If the ingredients match
                                if(SRIT->second <= it->second){found = TRUE;}//If there is enough of the ingredient
                                else throw "c";//Else throw an exception
                                }
                        if(it == storeroom.end()){//If the iterator is at the last ingredient in storeroom
                                throw "m";//Throw an exception
                                return collected;//Return an empty vector
                                }
                        else if (found != TRUE){it++;}//If the ingredient has not been found yet
                        }                       //Increment to the next ingredient
                Ingredient ing = it->first;//Create a variable that holds the name of the ingredient
                for(std::size_t ret = 0; ret < SRIT->second; ret++){//For as many of the ingredient that needs retrieving
                        it->second = it->second - 1;//Remove one from the storeroom quantity
                        collected.push_back(ing);//Add it to the collected vector
                        }
                }
        //If there are multiple ingredients
        else {for(;SRIT != ingredients.end();){
                if(SRIT->first == it->first){//If the ingredients match
                        if(SRIT->second <= it->second){//And there is enough of the ingredient
                                SRIT++;//Go to the next ingredient in the recipe
                                it = storeroom.begin();}//Start at the begining of the storeroom list
                        else throw "c";//else throw an error exception
                        }
                if(it == storeroom.end()){//If we have rached the end of the storeroom w/o finding the desired ingredient
                        throw "m";//throw an error
                        return collected;//Return an empty vector
                        }
                else it++;//Else continue to the next ingredient in the storeroom
                }
                //Begin gathering the ingredients
                for(SRIT = ingredients.begin(), it = storeroom.begin();//Restart the list and itterate once more
                    SRIT != ingredients.end();){
                        if(SRIT->first == it->first){//Check again for the correct ingredient
                                Ingredient ing = it->first;//Set a variable to the name of the ingredient
                                for(std::size_t ret = 0; ret < SRIT->second; ret++){//For the quantity needed by runner
                                        it->second = it->second - 1;//Subtract one from the store room
                                        collected.push_back(ing);//Add it to the collected vector
                                        }
                                SRIT++;//Increment to the next ingredient
                                }
                        else it++;//If the current ingredient being checked in the storeroom is not the desired ingredient
                                //Go to the next one
                        }
                }
return collected;//Once all ingredients collected via either method, return the collected vector
}

