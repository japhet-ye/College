#include "Cook.hpp"
#include "SupplyRunner.hpp"
#include "Cashier.hpp"

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):
	runner(runner_), kitchen(kitchen_){}

void Cook::prepare_dish(std::stack<Order>& orders,std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
	//1.Take an Order from the stack.
 	//2.For each order item in the Order,
	 	//3.Lookup its required ingredients in the RecipeBook.
 		//4.Then, ask the SupplyRunner to get the correct amount of ingredients.
		//5.Put the vector of ingredients into an IngredientMap.
		//6.Send the IngredientMap to the Kitchen to have it turned into adish
		//7.Put the finished Dish onto the queue, embedding it in a 
		//pair that also contains the Customer ID of origin.
	//1
	while(!orders.empty()){
	        Order order1 = orders.top();
	        std::vector<std::string> item = order1.get_items();
	        orders.pop();
	        RecipeBook recipe;
	        recipe["Fries"] = { {"Potato", 1}, {"CanolaOil", 1} };
	        recipe["Burger"] = { {"WheatBun", 2}, {"BeefPatty", 1}, {"Cheese", 1}, {"Lettuce", 1}, {"Tomato", 1} };
	        recipe["DoubleBurger"] = { {"WheatBun", 3}, {"BeefPatty", 2}, {"Cheese", 2}, {"Lettuce", 3}, {"Tomato", 1} };
	        recipe["IceCreamCone"] = { {"SugarCone", 1}, {"VanillaCream", 1} };
	        recipe["SmallDrink"] = { {"SmallCup", 1} };
	        recipe["MediumDrink"] = { {"MediumCup", 1} };
	        recipe["LargeDrink"] = { {"LargeCup", 1} };
	        recipe["Salad"] = { {"Lettuce", 1}, {"Tomato", 1}, {"SaladDressing", 1}, {"Fork", 1} };
	        recipe["#1"] = { {"MediumCup", 1}, {"Potato", 1}, {"CanolaOil", 1}, {"WheatBun", 2}, {"BeefPatty", 1}, {"Cheese", 1}, {"Lettuce", 1}, {"Tomato", 1} };
	        recipe["#2"] = { {"MediumCup", 1},{"Potato", 1},{"CanolaOil", 1},{"WheatBun", 3},{"BeefPatty", 2},{"Cheese", 2},{"Lettuce", 3},{"Tomato", 1} };
	        recipe["#3"] = { {"MediumCup", 1},{"Potato", 1},{"CanolaOil", 1},{"WheatBun", 4},{"BeefPatty", 2},{"Cheese", 2},{"Lettuce", 2},{"Tomato", 2}};
	
	        //2
		for(std::vector<std::string>::iterator it = item.begin(); it != item.end(); it++){
	          	//3,4
			std::vector<std::string> ingredi = runner.get_ingredients(recipe[*it]);
	          	IngredientMap Imap;
	          	//5
			for(std::vector<std::string>::iterator i = ingredi.begin(); i != ingredi.end(); i++){
	            		if(Imap.find(*i) == Imap.end()){
	              			Imap[*i] = 1;
	            		}
	            		else{
	              			Imap[*i]++;
	            		}
	          	}
			//7
	          	std::pair<std::size_t, Dish> dish = std::make_pair(order1.get_id(), kitchen.prepare_dish(std::move(Imap)));
		  	finished_dishes.push(dish);
	       	}
	}
}
