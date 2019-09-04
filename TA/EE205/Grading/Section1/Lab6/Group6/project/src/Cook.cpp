#include "Cashier.hpp"
#include "Cook.hpp"
#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Ingredient.hpp"
#include <queue>
#include <stack>
#include <string>

using Ingredient = std::string;
using IngredientMap = std::map<Ingredient, unsigned>;
using RecipeBook = std::map<std::string, std::map<Ingredient, unsigned>>;

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):runner(runner_),kitchen(kitchen_) { }

// prepare dish of single order
void Cook::prepare_dish(std::stack<Order>& orders, 
                std::queue<std::pair<std::size_t,Dish>>& finished_dishes) {
    // check if there order(s) on stack
    if(!orders.empty()) {
        // take order from stack
        std::vector<std::string> items = orders.top().get_items();
        // define stuff
        IngredientMap im, nim;
        Dish meal;
        std::map<Ingredient, unsigned>::iterator itr;
        std::map<std::string, std::map<Ingredient, unsigned>>::iterator it;
        std::pair<std::size_t, Dish> wid;
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
        //for the item in the order
        for(long unsigned int i = 0; i < items.size(); i++) { 
            
            //look up required ingredients in recipe book
            it = recipes.find(items[i]);
            im = it->second;
            
            //send to supply runner
            std::vector<Ingredient> ing = this->runner.get_ingredients(im);
            
            //put ingredients into ingredient map
            //iterate through ing vector and change to type ingredientMAP
            for(long unsigned int j = 0; j < ing.size(); j++) {
                itr = nim.find(ing[j]);
                if(itr==nim.end()) {
                    nim.insert(itr, std::pair<Ingredient, unsigned>(ing[j], 1));
                }
                else {
                    itr->second++;
                }
            } 
            
            //send ingredient map to kitchen
            meal = this->kitchen.prepare_dish(std::move(nim));
            
            //put dish on queue w ID
            wid.first = orders.top().get_id();
            wid.second = meal;
            finished_dishes.push(wid);
        }
        orders.pop();
    }
}
