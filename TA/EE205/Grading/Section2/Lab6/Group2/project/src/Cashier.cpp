#include "Cashier.hpp"
#include "Order.hpp"
#include "Customer.hpp"
#include "restaurant-utility.hpp"
#include "Dish.hpp"

#include <queue>
#include <stack>

        /**
         * @brief Constructs the Cashier with a set amount of money.
         */
        Cashier::Cashier(double money_):
			money(money_), 
			uid_count(0){}

        /**
         * @brief Gets the amount of money that the cashier holds.
         */
        double Cashier::get_money() const{
			return this->money;
		}

        /**
         * @brief Serves a customer by taking them off the queue, and possibly 
         * putting an order, if valid, onto the order stack.
         * - Retrieves the customer from the queue, popping them off.
         *
         * - Receives the customer's desired order items in string format:
         *
         *      <number-of-items> <name-of-item-with-no-spaces>
         *   
         *      - Multiple items are separated simply by a space
         *
         * - If the Cashier detects an order for an invalid item that is not on 
         *   the menu, it must expel() the customer.
         *
         * - Must calculate the cost of all the items ordered, and charge the 
         *   customer.
         *
         *      - It the customer does not have enough money to pay, do not 
         *      charge the customer, but instead, expel() them.
         *
         * - Once paid for, the order items must be consolidated into an Order, 
         *   which is tagged with the unique customer ID generated at the
         *   beginning of this function, and then push it onto the stack.
         *
         * @see Customer
         * @see Order
         */
        void Cashier::serve_customer(
                std::queue<Customer>& line,
                std::stack<Order>& orders){
			// Get the order ID
			std::size_t id = this->uid_count;
				// Update the order ID
				this->uid_count++;
			// Place order in a vector with <number-of-items> <name-of-item>
			std::vector<std::string> item = split(line.front().get_order(), ' ');
			std::vector<std::string> list;
			double charged;
			int amount;
			int k = 0;
			for(unsigned i = 0; i < item.size(); i++){
				// Get the amount of the item
				amount = stoi(item[i]);
				// Get the name of the item
				i++;
				// Store the item in the vector
				while(amount > 0){
					// Adjust the size and capacity of the vector storing
					// the items
					list.resize(list.size() + 1);
					if(list.size() >= list.capacity())
						list.reserve(list.capacity() + 10);
					// Store the item
					list[k] = item[i];
					// Move to the next space in the vector
					k = k + 1;;
					// If there are duplicates, store the item again
					amount = amount - 1;
				}
			}
			// Pay for the order
			try{
				calculate_order_cost(list);
			}
			// Not a valid order? Throw them out!
			catch (char const* c)
			{
				line.front().expel();
				line.pop();
				return;
			}
			// Calculate the cost
			double cost = calculate_order_cost(list);
			// Not enough money? Throw them out!
			if(cost > line.front().get_money()){
				charged = line.front().charge_money(cost);
				line.front().refund_money(charged);
				line.front().expel();
				line.pop();
				return;
			}
			else
			{
				// Pay and update the amount of money in the cashier
				line.front().charge_money(cost);
				this->money = this->money + cost;
			}

			// Make Order
			Order* order = new Order(id, list);
			// Move order to stack
			orders.push(*order);
			line.pop();
		}
