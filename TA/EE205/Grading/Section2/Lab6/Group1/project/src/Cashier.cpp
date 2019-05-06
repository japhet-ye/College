#include "Cashier.hpp"

Cashier::Cashier(double money_):
	money(money_){
	uid_count=0;
	}


double Cashier::get_money() const{
	return this->money;
}


void Cashier::serve_customer(std::queue<Customer>& line,std::stack<Order>& orders){
	
	// access the queue with temporary for Customer
	std::queue<Customer>& tempqueue =line;

	// access "orders" stack
	std::stack<Order>& tempstack = orders;

	double amount;
	
	if(!tempqueue.empty()){

		Customer custom = line.front();

		//money that customer has
		double customer_money = custom.get_money();

		//make order and set format
		std::string chek = custom.get_order();
		std::vector<std::string> ordering = split(chek,' ');

		//create a new vector of string
		std::vector<std::string> orderstr;
	
		// get item times
		for(int i = 0; i < ordering.size(); i+=2){
			std::string times_string = ordering[i];
			int counts = std::stoi(times_string);
			// place items in vector string
			for(int j = 0; j < counts; j++){
				orderstr.push_back(ordering[i+1]);
			}
		}

		try{
			// calculate cost and check order
			amount = calculate_order_cost(orderstr);
		}

		// if not valid
		catch (const char*){
			custom.expel();
		}

		// if customer not expelled
		if(!custom.is_expelled()){

			// check customer money money
			if(customer_money > amount){
		
				// charge customer
				amount = calculate_order_cost(orderstr);
				custom.charge_money(amount);

				//update cashregister 
				money = money + amount;

				Order finalorder(uid_count,orderstr);
				orders.push(finalorder);
				
				// make a new id for next customer
				uid_count++;
			}

			//if not enough $ expell customer
			else{
				custom.expel();
			}
		}

		// remove the customer from queue
		line.pop();
	}
}
