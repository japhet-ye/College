#include "Cook.hpp"

#include <vector>

//parameterized constructor
Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_):runner(runner_),kitchen(kitchen_){}

//prepares dish from single order
void Cook::prepare_dish(std::stack<Order>& orders, std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
//initialize variables
    std::vector<std::string> items_in_order;

    std::pair<std::size_t, Dish> finished_item;

    bool found_ingredients = false;


//checks to see if there is an order
if(orders.empty() == 0){

    //create temporary order to hold current order from stack
    Order current_order = orders.top();

    //remove order from the stack
    orders.pop();

    //gets order into form of vector of strings
    items_in_order = current_order.get_items();

    //Create Recipe Book for all types of orders
    RecipeBook recipes{
        {
                     {"Fries",
                        {
                          {"Potato", 1},
                          {"CanolaOil", 1}
                        }
                     },
                     {"Burger",
                        {
                          {"WheatBun", 2},
                          {"BeefPatty", 1},
                          {"Cheese", 1},
                          {"Lettuce", 1},
                          {"Tomato", 1}
                        }
                     },

                     {"DoubleBurger",
                        {
                          {"WheatBun", 3},
                          {"BeefPatty", 2},
                          {"Cheese", 2},
                          {"Lettuce", 3},
                          {"Tomato", 1}
                        }
                     },
                     {"IceCreamCone",
                        {
                          {"SugarCone", 1},
                          {"VanillaCream", 1}
                        }
                     },
                     {"SmallDrink",
                        {
                          {"SmallCup", 1}
                        }
                     },
                     {"MediumDrink",
                        {
                          {"MediumCup", 1}
                        }
                     },
                     {"LargeDrink",
                        {
                          {"LargeCup", 1}
                        }
                     },
                     {"Salad",
                        {
						   {"Lettuce", 1},
						   {"Tomato", 1},
						   {"SaladDressing", 1},
						   {"Fork", 1}
                        }
                     },
                     {"#1",
                        {
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
                     {"#2",
                        {
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
                     {"#3",
                        {
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

    //create iterator to go through recipes
    auto it = recipes.begin();

    //iterate through order vector to see what ingredients you need
    for(int i = 0; i < items_in_order.size(); i++){

        //iterate through recipe book to see what ingredients are needed for order
        while(it != recipes.end() && found_ingredients == false){
        
            //if order matches the recipe name
            if(items_in_order[i] == it->first){
                //get ID to put on order
                finished_item.first = current_order.get_id();
               
                //look to see if there is enough of the ingredients from supply runner
                try{
                    runner.get_ingredients(it->second);
                }
                //looks for the supply runners throw
                catch (char const* c){
                    throw c;
                }

                //if try passed, ingrdients were found in storeroom and taken out of stock count
                found_ingredients = true;

                //pass recipe to kitchen to prepare dish
                finished_item.second = kitchen.prepare_dish(std::move(it->second));
                
                //push finished disk into queue as a pair of ID number and finished dish
                finished_dishes.push(finished_item);

            }

            //look at next recipe if it doesnt match
            else it++;
        }
        //reset iterators and conditions for next item in the order
        found_ingredients = false;
        it = recipes.begin();


    }


}
}

