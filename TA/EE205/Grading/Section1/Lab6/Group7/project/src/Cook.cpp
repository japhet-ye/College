#include "Cook.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Ingredient.hpp"
#include "Dish.hpp"
#include "Order.hpp"
#include <queue>
#include <stack>

using namespace std;

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

/**
 * @brief Constructs a Cook with references to a SupplyRunner and a
 * Kitchen, which it must use in the process of cooking.
 */
Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):runner(runner_),kitchen(kitchen_){}
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
    stack<Order>& orders, //create order stack
    queue<std::pair<std::size_t, Dish>>& finished_dishes){ //Create pairs of id & ordered dishes in queue
    while(!orders.empty()){ //if there are orders in the stack 
        Kitchen kitchen;
        Order currentO = orders.top(); //take an order from the stack.
        //map <string,int> recipeMap={}; //create a map to put recipes in
        //map<string,int>IngredientMap={}; //create map of all the ingredients needed
        IngredientMap ingredientMap;
        auto itOrd = currentO.get_items();
        for(unsigned i= 0; i < itOrd.size(); i++){
            for(auto it1 = recipes.begin(); it1 != recipes.end(); it1 ++){
                if(it1->first == itOrd[i]){
                    try {
                        runner.get_ingredients(it1->second);
                    }
                    catch(const char* ){
                        throw "No supplies"; //if there are no supplies
                        orders.pop();
                        return;
                    }
                    for(auto itRecipeMap = (it1->second).begin(); itRecipeMap != (it1->second).end();itRecipeMap++){
                        ingredientMap.insert(std::pair<Ingredient,unsigned> (itRecipeMap->first,itRecipeMap->second));
                    }
                }
            }
        }
        Dish currentD = kitchen.prepare_dish(std::move(ingredientMap));
        finished_dishes.push({currentO.get_id(),currentD});
        orders.pop(); //pop order off
    }
}