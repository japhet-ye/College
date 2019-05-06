#include "Cashier.hpp"
#include "Customer.hpp"
#include "restaurant-utility.hpp"
using namespace std;

//Constructs cashier with set amount of money
Cashier::Cashier(double money_){
    this->money = money_;
}

//Getter
double Cashier::get_money() const {
    return this->money;     
}

void Cashier::serve_customer(std::queue<Customer>& line, std::stack<Order>& orders){
    int id;
    for(id = 0; !line.empty(); id++){
    //while(!line.empty()){   //while there are customers in the line 

        Customer customer = line.front();
        std::string ord = customer.get_order();     //get the order of the customer 
        vector<string> feedme = split(ord,' ');   //parses order into pairs
        vector<string> feedme2;                     //actual order, all words no numbers
        for(int i = 0; i < (int)feedme.size(); i+=2)     //translate whole order (feedme -> feedme2)
        {
            for(int t = stoi(feedme[i]); t > 0; t--){
                feedme2.push_back(feedme[i+1]);
            }
        }

        Order order(id, feedme2);   //create order object for customer
        double pay = 0; 
        try{
            pay = calculate_order_cost(feedme2); 
        }
        catch(const char*){
                customer.expel();   //expel if their order was invalid 
        }
        if(!customer.is_expelled())
        {
            double wallet = customer.get_money();  //get amount of money customer has
            if (pay <= wallet){      //if the amount the customer has is greater or equal to the cost 
                customer.charge_money(pay);    //charge the cost of the meal to the customer
                this->money += pay;
                orders.push(order);    //add order to stack
            }
            else {  //customer did not have enough money 
                    customer.expel();   //expel if their order was invalid   
            }
        }
        line.pop();     //remove customer from queue
    }
}