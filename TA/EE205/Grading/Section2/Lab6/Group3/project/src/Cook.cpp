#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>

using Ingredient = std::string;
using IngredientMap = std::map<Ingredient, unsigned>;
using RecipeBook = std::map<std::string, std::map<Ingredient, unsigned>>;

extern RecipeBook recipes;

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) : runner(runner_), kitchen(kitchen_){}

void Cook::prepare_dish(
                std::stack<Order>& orders,
                std::queue<std::pair<std::size_t, Dish>>& finished_dishes){
//Initializing Variables
        /* "Currently Preparing"
         *  Used to indicate index of the dish being prepared in the order vector */
        std::size_t CP;

        /* "Currently Preparing Name"
         * Used to indicat the name of the dish declared by CP*/
        std::string CP_Name;

        /* "Recipe Book Iterator"
         * Used to iterate through the RecipeBook*/
        RecipeBook::iterator RBIT;

        /* The name and quantity of ingredients required to prepare the dish
         * Given to the SupplyRunner to collect the needed ingredients */
        IngredientMap to_gather;

        /* The vector of ingredients returned by the runner
         * Converted into the ingredient map GathIM */
        std::vector<Ingredient> gathered;

        /* "Prepared Dish" 
         * Used to hold the prepared dish returned by the kitchen
         * Given to FinOrd as the dish component of the pair */
        Dish PD;

        /* "Gathered IngredientMap" 
         * Used to convert ingredients from the gathered vector
         * into an IngredientMap
         * Given to the Kitchen to prepare the appropriate dish */
        IngredientMap GathIM;

        /*"Gathered Iterator"
         * Used to iterate through the gathered vector */
        std::size_t GIT;

        /* "GIT Name"
         * Used to indicate the name of an ingredient in the gathered vector
         * Given to IngVect along GIT_Quantity in the form of
         * std::pair<Ingredient, std::size_t> */
        std::string GIT_Name;

        /* "GIT Quantity"
         * Used to indicate the quantity of an ingredient
         * in the gathered vector
         * See GIT_Name for additional details */
        std::size_t GIT_Quantity = 0;
        /* "Ingredient Vector"
         * Used to hold a vector of ingredient pairs
         * Ingredient pairs hold the quantity of the ingredient and the name
         * of the ingredient */
        std::vector<std::pair<Ingredient, std::size_t>> IngVect;

        /* Used to keep track of how far through the gathered vector we are
         * Is added with GIT_Quantity to act as an iterator */
        std::size_t count = 0;

        /* "Finished Order"
         * Used to hold the order number and dish
         * Is pushed out to the queue finished_dishes
         * finished_dishes is given to the function during the function call */
        std::pair<std::size_t, Dish> FinOrd;

//Begining Cooking Process
        //If no orders are on the stack
        if(orders.empty())
                return;//Do nothing

        //Otherwise take an order off the stack
        Order prep {orders.top()};
        orders.pop();
        //Get the desired items from the order
        std::vector<std::string> tab {prep.get_items()};
        for(CP = 0; CP < tab.size(); CP++){//For each item on the tab
                CP_Name = tab[0];//Get the name of the item to be prepared
                for(RecipeBook::iterator RBIT = recipes.begin();
                RBIT != recipes.end();){//Iterate through the recipe book
                        if(RBIT->first == CP_Name){//If recipe is found
                                to_gather = RBIT->second;// Get the list of ingredients
                                gathered = runner.get_ingredients(to_gather);//Give list to runner to collect
                                GIT_Name = gathered[0]; //Get the name of the first ingredient in the vector
                                for(GIT = 0; GIT < gathered.size(); GIT++){//Iterate through the entire vector
                                        if(GIT_Name == gathered[GIT]){//If the name matches
                                                GIT_Quantity++;//Increase the quantity of ingredient
                                                }
                                        else{//If the names do not match
                                                IngVect.push_back( std::make_pair(/*Add the ingredient and it's*/
                                                        GIT_Name,GIT_Quantity));  /*Quantity to IngVect*/
                                                count = count + GIT_Quantity;//Set count to the index of new ingredient
                                                GIT_Name = gathered[count]; //Set the name to the index of new ingrediemt
                                                GIT_Quantity = 1;//Set the current quantity of the ingredient to 1
                                                }
                                        }
                                IngVect.push_back(std::make_pair(
                                                GIT_Name,GIT_Quantity));//Add the last ingredient to IngVect
                                PD = kitchen.prepare_dish(IngredientMap(
                                                IngVect.begin(), IngVect.end()));//Give the IngredientMap to the kitchen
                                std::pair<std::size_t, Dish> FinOrd
                                                        {prep.get_id(), PD};//Create finished order
                                finished_dishes.push(FinOrd);//Push the finished order to the queue
                                CP++;
                                }
                        RBIT++;//If the recpie is not found at the index, go to the next index
                        }
                }
}
