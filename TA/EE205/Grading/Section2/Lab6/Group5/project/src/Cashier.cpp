#include <iostream>
#include <vector>
#include <string>

#include "Cook.hpp"
#include "Customer.hpp"
#include "Cashier.hpp"

Cashier::Cashier(double money_) {
  this->money = money_;
}

double Cashier::get_money() const {
  return this->money;
}

void Cashier::serve_customer(
std::queue<Customer>& line,
std::stack<Order>& orders) {
  // Get latest customer and pop off queue
  Customer customer = line.front();
  line.pop();

  // Split by space, push to vector
  std::vector<std::string> splitItems = split(customer.get_order(), ' ');

  // for (char& c : orderItems) {
  //   std::string string;

  //   if (c != ' ') {
  //     string = string + c;
  //   } else if (c == ' ' || c == ',') {
  //     split.push_back(string);
  //   }
  // }

  // If index is even, push to quantities
  // If index is odd, push to items
  std::vector<std::string> quantities;
  std::vector<std::string> items;

  for (unsigned i = 0; i < splitItems.size(); i++) {
    if (i % 2 == 0) { // even
      quantities.push_back(splitItems[i]);
    } else if (i % 2 != 0) {
      if (!(recipes.find(splitItems[i]) == recipes.end())) {
        items.push_back(splitItems[i]);
      } else {
        customer.expel();
      }
    }
  }

  std::vector<std::string> itemsWithQuantities;

  for (unsigned i = 0; i < items.size(); i++) {
    for (auto j = 0; j < std::stoi(quantities[i]); j++) {
      itemsWithQuantities.push_back(items[i]);
    }
  }

  double orderCost = calculate_order_cost(itemsWithQuantities);

  if (customer.get_money() >= orderCost) {
    customer.charge_money(orderCost);

    this->money = this->money + orderCost;

    // Create order and pass in items
  } else {
    customer.expel();
  }

  if (!customer.is_expelled()) {
    Order order(this->uid_count, itemsWithQuantities);
    orders.push(order);
  }

  this->uid_count = this->uid_count + 1;
}