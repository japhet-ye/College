
#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"
#include "Ingredient.hpp"
#include "Order.hpp"
#include "Storeroom.hpp"

#include <queue>
#include <stack>
#include <vector>
#include <map>

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):runner(runner_),kitchen(kitchen_){} 

RecipeBook recipes = {
    {
        {"Fries", {
                      {"Potato", 1},
                      {"CanolaOil", 1}
                  }
        },
        {"Burger", {
                       {"WheatBun", 2},
                       {"BeefPatty", 1},
                       {"Cheese", 1},
                       {"Lettuce", 1},
                       {"Tomato", 1}
                   }
        },
        {"DoubleBurger", {
                             {"WheatBun", 3},
                             {"BeefPatty", 2},
                             {"Cheese", 2},
                             {"Lettuce", 3},
                             {"Tomato", 1}

                         }
        },
        {"IceCreamCone", {
                             {"SugarCone", 1},
                             {"VanillaCream", 1}
                         }
        },
        {"SmallDrink", {
                           {"SmallCup", 1}
                       }
        },
        {"MediumDrink", {
                            {"MediumCup", 1}
                        }
        },
        {"LargeDrink", {
                           {"LargeCup", 1}
                       }
        },
        {"Salad", {
                      {"Lettuce", 1},
                      {"Tomato", 1},
                      {"SaladDressing", 1},
                      {"Fork", 1}
                  }
        },
        {"#1", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 2},
                   {"BeefPatty", 1},
                   {"Cheese", 1},
                   {"Lettuce", 1},
                   {"Tomato", 1}

               }
        },
        {"#2", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 3},
                   {"BeefPatty", 2},
                   {"Cheese", 2},
                   {"Lettuce", 3},
                   {"Tomato", 1}
               }
        },
        {"#3", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 4},
                   {"BeefPatty", 2},
                   {"Cheese", 2},
                   {"Lettuce", 2},
                   {"Tomato", 2}
               }
        }
    }
};


void Cook::prepare_dish(std::stack<Order>& orders, std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
    IngredientMap ingredients;
    std::vector<Ingredient> neededIngredients;  

    //do nothing if sent an empty stack of orders
    if (orders.empty()){return;}

    else{ 
            //get each item from the stack of orders
            for(int i = 0; i<(int)orders.top().get_items().size(); i++){

                //create customerID for dish
                int CustomerID = orders.top().get_id();

                //find item in recipe book
                if(recipes.find(orders.top().get_items().at(i)) != recipes.end()){
                    std::string dishToMake = orders.top().get_items().at(i);

                    //send supplyrunner to get ingredients for that dish
                    neededIngredients = runner.get_ingredients(recipes.at(dishToMake));

                    //create list of ingredients to send to kitchen
                    for(int j = 0; j<(int)neededIngredients.size();j++){

                        //check for multiple of same ingredient, then increase quantity in map
                        //should only happen if ingredient is already inserted into map
                        if(neededIngredients[j] == neededIngredients[j-1]) {
                            ingredients.at(neededIngredients[j])++;
                        }

                        //if no multiple ingredients or first ingredient to repeated, insert into map
                        else {
                            ingredients.insert(std::pair<std::string, unsigned> (neededIngredients[j],1));
                        }
                    }

                //create dish then push into stack
                std::pair<std::size_t , Dish> dish (CustomerID , kitchen.prepare_dish(std::move(ingredients)));
                finished_dishes.push(dish);   

                }//end of recipe

            }//end of order

        //pop completed orders
        orders.pop();   
    }
}