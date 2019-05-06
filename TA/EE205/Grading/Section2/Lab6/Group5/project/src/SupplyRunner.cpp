#include "SupplyRunner.hpp"
#include "Ingredient.hpp"
#include "Storeroom.hpp"
#include <map>
#include <vector>

SupplyRunner::SupplyRunner(Storeroom& storeroom_) :
  storeroom(storeroom_)
 {}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
  std::map<std::string, int>::iterator it;
  std::vector<Ingredient> ingredientsSupplied;

  // Loop through the storeroom with ingredients for supply runner to get and check if there are enough ingredients
  for (auto it_check = ingredients.begin(); it_check != ingredients.end(); it_check++) {
    // Check if ingredient exists and see if there is enough in the storeroom (storeroom supplies are less than needed)
    if (storeroom.find(it_check->first) == storeroom.end() || storeroom[it_check->first] < it_check->second) {
      throw "Not enough ingredients in the Storeroom.";
    }
  }
  
  // If there are enough ingredients, retrieve the ingredients, reduce storeroom count and return the ingredients in a vector.
  for (auto it_retrieve = ingredients.begin(); it_retrieve != ingredients.end(); it_retrieve++) {
    for (int i = 0; i < it_retrieve->second; i++) {
      storeroom[it_retrieve->first] = storeroom[it_retrieve->first] - 1;
      ingredientsSupplied.push_back(it_retrieve->first);
    }
  }

  return ingredientsSupplied;
}
