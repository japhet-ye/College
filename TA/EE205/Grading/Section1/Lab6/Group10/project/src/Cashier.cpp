#include "Cashier.hpp"
#include "restaurant-utility.hpp"
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <utility>


//Default Constructor
Cashier::Cashier(double money_){

    this->money = money_;
}

//return amount of money cashier has
double Cashier::get_money() const {
    std::cout << "Cashier: The cashier has " << money << std::endl;
    return this->money;
}

//receives a queue of customers and a stack of orders to put customer orders into
void Cashier::serve_customer(std::queue<Customer>& line, std::stack<Order>& orders){
    
    //generate CustomerID based upon location in stack.
    //ex. if first customer, ID number should be 0.
    int CustomerID = orders.size();

    //call customer at front of line
    Customer top = line.front();

    //split up customers order based upon order string
    std::vector<std::string> preOrder = split(top.get_order(),' ');

    //get total amount of items within order vector
    int orderSize = preOrder.size();

    //generate new vector that only stores menu items
    std::vector<std::string> finOrder;

    /**
     * input menu items into vector based on the int value before item name
     * ex. , 'Large Drink' stores -> 'Large Drink', 'Large Drink', 'Large Drink'
     */

    // item quantities are stored at every 2nd vector location, starting at i=0, so iterate i+=2
    for (int i = 0; i < orderSize; i+=2){ 
                                          
        // push menu item into finOrder vector based upon int value stored at i
        for (int j = std::stoi(preOrder[i]); j > 0; j--){ //must convert to int since originally a string  
            finOrder.push_back(preOrder[i+1]);
        }
    }

    double total;

    try {
        //push order containing only menu items
        total = calculate_order_cost(finOrder);
    }
    //calculate_order_cost throws exception if a nonmenu item is found
    catch(const char* c) {
        std::string s = c;
        if (s == "No order."){
            top.expel();
            line.pop();
            return;
        }
    }

    //charge customer and submit order if payment is successful.
    double chargeCustomer = top.charge_money(total);
    if (top.get_money() == 0){
        top.expel();
        line.pop();
        return;
    }
    else{ 
        this->money += chargeCustomer;
        Order custOrder(CustomerID,finOrder);
        orders.push(custOrder);
        line.pop();
        
    }
 
}
