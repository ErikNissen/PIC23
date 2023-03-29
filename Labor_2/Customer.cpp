#include "Customer.hpp"

Customer::Customer( const std::string &cName ) : customerName(cName){

}

void Customer::ServeDish( std::unique_ptr<dishlib::AbstractDish> dish) {
	customerDish = std::move(dish); // übergabe von dish
}

std::string Customer::getName(){
	return this->customerName; // get cusomerName
}

void Customer::EatDish() {
	std::cout << customerName << " verspeist Gericht " << customerDish->GetDishName() <<
	std::endl; // dish Objekt wird vom customer verspeist
	customerDish.reset(nullptr); // gibt nullptr zurück
}