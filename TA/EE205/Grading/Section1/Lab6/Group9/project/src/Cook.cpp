#include "Cook.hpp"

// define the recipes map
// cannot use the std::map insert function
// copied from Kitchen.cpp
RecipeBook recipes = 
{	{"Fries",
	IngredientMap{ 
		{"Potato", 1},
		{"CanolaOil", 1}
		}},
	
	{"Burger",
	IngredientMap{ 
		{"WheatBun", 2},
		{"BeefPatty", 1},
		{"Cheese", 1},
		{"Lettuce", 1},
		{"Tomato", 1}
		}},

	{"DoubleBurger",
	IngredientMap{ 
		{"WheatBun", 3},
		{"BeefPatty", 2},
		{"Cheese", 2},
		{"Lettuce", 3},
		{"Tomato", 1}
		}},

	{"IceCreamCone",
	IngredientMap{ 
		{"SugarCone", 1},
		{"VanillaCream", 1}
		}},

	{"SmallDrink",
	IngredientMap{ 
		{"SmallCup", 1}
		}},

	{"MediumDrink",
	IngredientMap{ 
		{"MediumCup", 1}
		}},

	{"LargeDrink",
	IngredientMap{ 
		{"LargeCup", 1}
		}},

	{"Salad",
	IngredientMap{ 
		{"Lettuce", 1},
		{"Tomato", 1},
		{"SaladDressing", 1},
		{"Fork", 1}
		}},

	{"#1",
	IngredientMap{ 
		{"MediumCup", 1},
		{"Potato", 1},
		{"CanolaOil", 1},
		{"WheatBun", 2},
		{"BeefPatty", 1},
		{"Cheese", 1},
		{"Lettuce", 1},
		{"Tomato", 1}
		}},

	{"#2",
	IngredientMap{ 
		{"MediumCup", 1},
		{"Potato", 1},
		{"CanolaOil", 1},
		{"WheatBun", 3},
		{"BeefPatty", 2},
		{"Cheese", 2},
		{"Lettuce", 3},
		{"Tomato", 1}
		}},

	{"#3",
	IngredientMap{
		{"MediumCup", 1},
		{"Potato", 1},
		{"CanolaOil", 1},
		{"WheatBun", 4},
		{"BeefPatty", 2},
		{"Cheese", 2},
		{"Lettuce", 2},
		{"Tomato", 2}
		}}
};

// default constructor:
// our runner is the given runner,
// our kitchen is the given kitchen
Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) :
	runner(runner_), kitchen(kitchen_) {}

// put all ordered meals onto the queue
void Cook::prepare_dish(
	std::stack<Order>& orders,
	std::queue<std::pair<std::size_t, Dish>>& finished_dishes)
{
	// only act if there are orders in the stack;
	// do nothing if the stack of orders is empty
	if(!orders.empty()){

	// prepare every dish in the order
	for(long unsigned int i = 0; 
		i < orders.top().get_items().size(); i++)
	{
		// the recipe for the current order
		IngredientMap recipeMap;

		// look up the required ingredients in the RecipeBook
		if(recipes.find(orders.top().get_items()[i]) != recipes.end())
		{
			recipeMap = recipes[orders.top().get_items()[i]];
		}

		// ask the SupplyRunner to get the correct
		// amount of ingredients
		// (the SupplyRunner will bring back a vector of strings)
		std::vector<Ingredient> supplyVector 
			= this->runner.get_ingredients(recipeMap);

		// put the vector of ingredients into an IngredientMap
		// (conversion from vector of strings, to map with names and quantities)
		IngredientMap ingredients;
		for(long unsigned int j = 0; j < supplyVector.size(); j++)
		{
			// if there is already an entry for this ingredient
			if(ingredients.find(supplyVector[j]) != ingredients.end())
			{
				// increment the quantity of the ingredient
				ingredients[supplyVector[j]]++;
			}
			// otherwise, create a new entry for the ingredient
			// with quantity of 1 (since all items in the vector are 1)
			else
			{
				ingredients.insert(std::make_pair(supplyVector[j], 1));
			}
		}

		// send the IngredientMap to the Kitchen
		Dish meal = this->kitchen.prepare_dish(std::move(ingredients));

		// put the finished Dish onto the queue
		// as a pair with its Customer ID	
		finished_dishes.push(std::make_pair(orders.top().get_id(), meal));
	}
	// remove the order from the stack
	orders.pop();
	}
}
