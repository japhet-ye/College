#include "Cashier.hpp"
#include "Order.hpp"
#include "Customer.hpp"

#include "restaurant-utility.hpp"

#include <queue>
#include <stack> 

Cashier::Cashier(double money_){
    this->money = money_;
}

double Cashier::get_money() const{
    return this->money;
}

void Cashier::serve_customer(std::queue<Customer>& line, std::stack<Order>& orders){
    Customer c(0,"");
    double cost = 0;
    std::size_t ID = 0;
    //std::cout<<ID<<std::endl;
    std::string unsplitOrder;
    std::vector<std::string> o1, o2;

    int amt = 0;

    while(!line.empty()){
        cost = 0;
        //Get first customer in the queue
        c = line.front();

        std::cout<<" ID: "<<ID<<std::endl;

        //Get their order
        unsplitOrder = c.get_order();
        //Seperate each word in the string into a vector of strings
        o1 = split(unsplitOrder,' ');
        for(int i = 0;i<o1.size();i++){
            std::cout<<o1[i]<<std::endl;
        }

        //Go through each string in the vector
        for(int n = 0;n < o1.size();n++){
        
            //At even indexs and index 0
            if(n%2 == 0){
                //convert the string into an integer(this is the amount of the item in the order)
                amt = stoi(o1[n]);
                std::cout<<"o1"<<amt<<std::endl;

                //amt -= 48;
            }
            //At the odd indexs
            else{
                //Add the item amt amount of times to a new vector of stings
                for(int z = 0;z < amt;z++){
                   // o2.reserve(1);
                   std::cout<<"o1"<<o1[n]<<std::endl;
                    o2.push_back(o1[n]);
                }
            }
        }

        //Calculate total
        try{
            cost = calculate_order_cost(o2);
        }
        //If the order is not on the menu
        catch(const char *){
            //expel the customer
            std::cout<<"catch"<<std::endl;
            c.expel();
            line.pop();
            return;
        }
        //Check if coustomer can afford it
        if(cost <= c.get_money()){
            //Charge them
            c.charge_money(cost);
            //Add the money to the cashregister
                        std::cout<<cost<<std::endl;
            money+=cost;
                    std::cout<<money<<std::endl;
            //Place the order
            std::cout<<"IN: ";
            std::cout<<ID<<std::endl;
            Order o(ID,o2);
            orders.push(o);
            //std::cout<<ID<<std::endl;
            ++ID;
            std::cout<<"After ++:: ";
            std::cout<<ID<<std::endl;
        }
        //If they can't afford it 
        else{
            //expel the customer
            c.expel();
            line.pop();
            return;
        }
            std::cout<<ID<<std::endl;

        //Get rid of the first customer in the queue
        line.pop();
        for(int w = 0;w<o2.size();){
            o2.pop_back();
        }
    }
    //ID++;
    
}