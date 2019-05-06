#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>

RecipeBook recipes = {
	{"Fries", {
			{"Potato", 1},
			{"CanolaOil", 1}}},
	{"Burger", {
			{"WheatBun", 2},
			{"BeefPatty", 1},
			{"Cheese", 1},
			{"Lettuce", 1},
			{"Tomato", 1}}},
	{"DoubleBurger", {
			{"WheatBun", 3},
            {"BeefPatty", 2},
            {"Cheese", 2},
            {"Lettuce", 3},
            {"Tomato", 1}}},
	{"Salad", {
            {"Lettuce", 1},
            {"Tomato", 1},
			{"SaladDressing", 1},
			{"Fork", 1}}},
    {"IceCreamCone", {
            {"SugarCone", 1},
            {"VanillaCream", 1}}},
    {"SmallDrink", {
            {"SmallCup", 1}}},
	{"MediumDrink", {
            {"MediumCup", 1}}},
    {"LargeDrink", {
            {"LargeCup", 1}}},
    {"#1", {
			{"MediumCup", 1},
			{"Potato", 1},
			{"CanolaOil", 1},
			{"WheatBun", 2},
            {"BeefPatty", 1},
            {"Cheese", 1},
            {"Lettuce", 1},
            {"Tomato", 1}}},
    {"#2", {
			{"MediumCup", 1},
            {"Potato", 1},
            {"CanolaOil", 1},
            {"WheatBun", 3},
            {"BeefPatty", 2},
            {"Cheese", 2},
            {"Lettuce", 3},
            {"Tomato", 1}}},
    {"#3", {
			{"MediumCup", 1},
            {"Potato", 1},
            {"CanolaOil", 1},
            {"WheatBun", 4},
            {"BeefPatty", 2},
            {"Cheese", 2},
            {"Lettuce", 2},
            {"Tomato", 2}}}
	};
        /**
         * @brief Constructs a Cook with references to a SupplyRunner and a
         * Kitchen, which it must use in the process of cooking.
         */
        Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_): runner(runner_), kitchen(kitchen_){}

        /**
         * @brief Prepares Dishes from a single order.
         *
         * - Take an Order from the stack.
         * - For each order item in the Order,
         *      - Lookup its required ingredients in the RecipeBook.
         *      - Then, ask the SupplyRunner to get the correct amount of 
         *      ingredients.
         *      - Put the vector of ingredients into an IngredientMap.
         *      - Send the IngredientMap to the Kitchen to have it turned into a 
         *      dish.
         *      - Put the finished Dish onto the queue, embedding it in a pair 
         *      that also contains the Customer ID of origin.
         */
        void Cook::prepare_dish(
                std::stack<Order>& orders,
                std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
		if(orders.empty()) return;
		std::size_t uid = orders.top().get_id();
		std::vector<Ingredient> list = orders.top().get_items();
			orders.pop();
		IngredientMap dish;
		std::vector<Ingredient> store;

		for(unsigned k = 0; k < list.size(); k++){
			auto search = recipes.find(list[k]);
			store = runner.get_ingredients(search->second);
			for(unsigned j = 0; j < store.size(); j++){
				auto it = dish.find(store[j]);
				if(it == dish.end()){
					dish.emplace(store[j], 1);
				}
				else
					it->second++;
			}
			std::pair<std::size_t, Dish> product(uid, kitchen.prepare_dish(std::move(dish)));
			dish.clear();
			finished_dishes.push(product);
		}
		}
