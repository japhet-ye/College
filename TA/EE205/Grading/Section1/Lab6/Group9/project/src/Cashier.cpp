#include "Cashier.hpp"

// default constructor:
// our money is the given money;
// the first order will have an id of zero; 
// because the new id must be generated at the beginning of the serve_customer()
// function, the starting id is -1, outside of the usable id number range
Cashier::Cashier(double money_) : money(money_), uid_count(-1) {}

// return our money count
double Cashier::get_money() const
{
	return this->money;
}

// transactions with money, taking orders, and moving the line of customers along
void Cashier::serve_customer
	(std::queue<Customer>& line, std::stack<Order>& orders)
{
	double orderCost; // the customer's bill
	// unique customer ID; generated at the beginning of this function
	(this->uid_count)++;

	// split the front customer's order string into a vector of strings;
	std::vector<std::string> quanOrder = split(line.front().get_order(), ' ');

	// create a vector with only the names of ordered items;
	// this vector of strings will be passed to other classes and functions
	std::vector<std::string> orderVector;

	// use the quantity of each ordered item to make a names-only order vector
	for(long unsigned int i = 0; i < quanOrder.size(); i+=2)
	{
		for(int j = 0; j < std::stoi(quanOrder[i]); j++)
		{
			orderVector.push_back(quanOrder[i+1]);
		}
	}

	// calculate the cost of the customer's order
	try
	{
		orderCost = calculate_order_cost(orderVector);
	}
	// if we caught an exception, then one of the ordered items is invalid
	catch(...)
	{
		// therefore, expel the customer
		line.front().expel();
	}

	// if the customer has not been expelled
	if(!line.front().is_expelled())
	{
		// if the customer does not have enough money to pay the bill
		if(line.front().get_money() < orderCost)
		{
			// expel the customer
			line.front().expel();
		}
		// otherwise, charge the customer and record the order
		else
		{
			// receive the payment front the customer
			this->money += line.front().charge_money(orderCost);
			// make a new order with the unique id
			Order frontOrder(this->uid_count, orderVector);
			// add the order to the order stack
			orders.push(frontOrder);
		}
	}
	// done with customer; pop the customer from the front of the queue
	line.pop();
}
