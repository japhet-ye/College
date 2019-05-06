#include "Cashier.hpp"




//parameterized constructor
Cashier::Cashier(double money_){

    this -> money = money_;

}

//getter 
double Cashier::get_money() const{

    return money;

}

//serve customer
void Cashier::serve_customer(std::queue<Customer>& line, std::stack<Order>& orders){
    //declare variables
    double total_cost = 0;


    //get current customer from front of line
    Customer current_customer(line.front());
    
    //delete current customer from the queue
    line.pop();

    //create current_order and split_order temporary storage
    std::string current_order;
    std::vector<std::string> split_order;

    //store order into current order in raw state with deliminters "2 fries"
    current_order = current_customer.get_order();
   
    //split order using space delimiter
   char delim = ' ';
    split_order = split(current_order, delim);

    //create final vector to hold order without
    std::vector<std::string> final_order;
    
    //iterate through split order and create string without numbers
    int amount = 0;
    for(int i = 0;i< split_order.size();i++){
        if(i%2==0){
            
            amount = std::stoi(split_order[i]);


        }
        else{
            while(amount != 0){
                final_order.push_back(split_order[i]);
                amount--;
                
            }
        }
        
    }   

//calculate total cost and validates order (looks for an invalid item that is trying to be ordered)

	try {
		total_cost = calculate_order_cost(final_order);
	}
    
    //catches the throw from calculate_order_cost
	catch  (char const* c) {
		current_customer.expel();
	}

    //checking if person has enough money if not expel them 
    if(total_cost > current_customer.get_money()){
        current_customer.expel();
    }
   
    //if customer isn't expelled then take his order
    else if (false == current_customer.is_expelled()){
        //charge money
        current_customer.charge_money(total_cost);

        this -> money += total_cost;
        Order current_customer_order(orders.size(),final_order);
        orders.push(current_customer_order);
    }
}

        