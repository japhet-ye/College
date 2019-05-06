#include "SupplyRunner.hpp"

// default constructor
SupplyRunner::SupplyRunner(Storeroom& storeroom_) : 
	// our storeroom will be the given storeroom
	storeroom(storeroom_) {}

// retrieve the given ingredients; all or nothing
std::vector<Ingredient> 
	SupplyRunner::get_ingredients(IngredientMap ingredients)
{
	// the basket will hold (the names of) the ingredients we take back with us
	std::vector<Ingredient> basket;
	// check if all of the ingredients asked for 
	// are all found in sufficient numbers
	
	// create an iterator
	std::map<std::string, unsigned>::iterator it = ingredients.begin();
	// iterate through our ingredients map
	while(it != ingredients.end())
	{
		// if there are not enough ingredients in the storeroom,
		// then throw const char*

		// we couldn't find the ingredient in the storeroom at all
		if(this->storeroom.find(it->first) == this->storeroom.end())
		{
			throw("Ingredient does not exist in storeroom.");
		}
		// we found the ingredient, but the amount in stock is less than we need
		else if(this->storeroom[it->first] < (it->second))
		{
			throw("Not enough of ingredient in storeroom.");
		}
		// continue through the ingredients map
		it++;
	}
	
	// there is enough of each ingredient
	for(it = ingredients.begin(); it != ingredients.end(); it++)
	{
		// remove the ingredients from the storeroom
		this->storeroom[it->first] -= (it->second);
		// add the items (string name) to our basket
		// number of names added will be number of that item added
		for (unsigned i = 0; i < it->second; i++)
		{
			basket.push_back(it->first);
		}
	}
	// return the ingredients
	return basket;
}
