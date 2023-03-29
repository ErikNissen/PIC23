#ifndef PIC23_CUSTOMER_HPP
#define PIC23_CUSTOMER_HPP

#pragma once

#include <iostream>
#include <memory>

#include "DishFactory.hpp"

class Customer {
public:
	void ServeDish(std::unique_ptr<dishlib::AbstractDish>);
	void EatDish();
	std::string getName();

	Customer() = delete;
	explicit Customer(const std::string &cName);
private:
	std::unique_ptr<dishlib::AbstractDish> customerDish;
	std::string customerName;
};


#endif //PIC23_CUSTOMER_HPP
