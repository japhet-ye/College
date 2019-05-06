#include "Cook.hpp"

Cook::Cook(SupplyRunner &runner_, Kitchen &kitchen_): 
     runner(runner_),
     kitchen(kitchen_) {}

//Prepares dish from order
void Cook::prepare_dish(stack<Order>& orders, 
                   queue<pair<size_t, Dish>>& finished_dishes) {
     //Check if order stack is empy
     if(orders.empty()) { return; }
     //Take order item from stack.
     Order& current = orders.top();
     //Get vector of order items
     vector<string> curr_it = current.get_items();
     vector<string> *supplies = new vector<string>;
     //Iterators for later

     //Process each item of order, asking SupplyRunner for ingredients,
     //Sending an IngredientMap to Kitchen, and then sending finished dish to "finished_dishes"
     for(vector<string>::iterator it=curr_it.begin();
                                  it!=curr_it.end();
                                  ++it) {
          *supplies = runner.get_ingredients(recipes[*it]);
          //Send IngredientMap to kitchen & then finished dish to queue
          Dish for_cust = kitchen.prepare_dish(this->Vect_to_map(supplies));
          finished_dishes.push( make_pair(current.get_id(), for_cust) );
cout<<"iterating through order items"<<endl;
     }
     //Pop order off queue
     orders.pop();
}



//Process vector and convert to a IngredientMap
IngredientMap Cook::Vect_to_map(vector<string> *supplies) {
          vector<string>::iterator cur_in = supplies->begin();
          vector<string>::iterator prev = cur_in;
          IngredientMap for_kit;
          unsigned counter = 0;
          while(cur_in!=supplies->end()) {
               while(*cur_in==*prev) {
cout<<"Increasing supply +1 (" << *cur_in << ")";
                    counter++;
                    prev = cur_in;
                    cur_in++;
                    if(cur_in==supplies->end()) { break; }
cout<<" Counter: " <<counter<<endl;
               }
               for_kit.insert({ *prev, counter });
cout<<"Pushed to kitchen"<<endl;
               counter = 0;
               prev=cur_in;
          }
          return for_kit;
}
               

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
