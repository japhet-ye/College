#include "SupplyRunner.hpp"
#include "Storeroom.hpp"
#include "Ingredient.hpp"

#include <string>
#include <vector>
#include <map>

    /**
     * @brief Constructs a SupplyRunner with the Storeroom it gets its 
     * Ingredients from.
     */
    SupplyRunner::SupplyRunner(Storeroom& storeroom_): storeroom(storeroom_){}

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
		std::vector<Ingredient> parts;
		Storeroom duplicate = storeroom;
		// Check to see if the storeroom is empty. If so, throw const char*
		if(storeroom.empty()) throw "Empty storeroom.";
		// Start getting ingredients
		for(auto it = ingredients.begin(); it != ingredients.end(); ++it){
			// Find the ingredient in the storeroom
			auto search = storeroom.find(it->first);
			// If the ingredient isn't in the storeroom, throw const char*
			if(search == storeroom.end()) throw "Not in the Storeroom.";
			// Else, store the ingredient
			else if(search->second >= it->second){
				// Remove the ingredient in the storeroom
				storeroom[it->first] = search->second - it->second;
				// Add the ingredient to the vector
				for(it->second; it->second > 0; it->second--)
					parts.push_back(it->first);
			}
			// Otherwise, leave the storeroom as it was originally
			// and throw const char*
			else{
				storeroom = duplicate;
				throw "Not enough ingredients in the Storeroom.";
			}
		}
		// Return the vector of ingredients
		return parts;
	}
