#include "Cashier.hpp"
#include "Customer.hpp"
#include "Order.hpp"

#include "restaurant-utility.hpp"

#include <queue>
#include <stack>

Cashier::Cashier(double money_): money(money_), uid_count(0){}

double Cashier::get_money() const{return this->money;}

void Cashier::serve_customer( std::queue<Customer>& line, std::stack<Order>& orders){
        //Get the next customer in line
        Customer serv(line.front());
        line.pop();//Pop them off the queue
        //Gather order
        std::vector<std::string> vectorder = split(serv.take_order(), ' ');

        //Turn order into only menu items
        std::vector<std::string> nnvectorder;//Make a new order vector
        for(int it = 0; it < vectorder.size();){
                int count = stoi(vectorder[it]);//Convert the quantity ordered
                                                //From string to int
                std::string item = vectorder[it+1];//Take the next index as the
                                                   //Ordered item
                for(int it1 = 0; it1 < count; it1++){//For the quantity declared
                                                     //as the quantity ordered
                        nnvectorder.push_back(item);//Add the ordered item to
                                                    //The vector
                        }
                it = it + 2;//Go to the next 2 items
                }
        //See if their order contains only valid items  
        try{calculate_order_cost(nnvectorder);}
                catch (const char* str) {serv.expel(); return;}
        //Calculate cost
        if(serv.get_money() < calculate_order_cost(nnvectorder)){
                //If the customer has insufficent funds
                serv.expel();//EXPEL THEM!
                }
        else{
                money += serv.charge_money(calculate_order_cost(nnvectorder));
                //Add the money to the cashier's total
        //Push the Order to Cook
        Order porder(this->uid_count, nnvectorder);//Create an order
        orders.push(porder);//Push it to the order stack
        this->uid_count++;//Increment the cashier's serve count
        }
}

