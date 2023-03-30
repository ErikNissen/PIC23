#include "Customer.hpp"

Customer::Customer( std::string cName ) : customerName(std::move(cName)){

}

void Customer::ServeDish( std::unique_ptr<dishlib::AbstractDish> dish) {
	customerDish = std::move(dish); // übergabe von dish
}

const std::string Customer::getName(){
	return this->customerName; // get cusomerName
}

void Customer::EatDish() {
	if( this->customerDish == nullptr){
		std::cout << this->customerName << " hat kein Gericht bekommen." <<
		std::endl;
		return;
	}
	std::cout << customerName << " verspeist Gericht " << customerDish->GetDishName() <<
	std::endl; // dish Objekt wird vom customer verspeist
	customerDish.reset(nullptr); // gibt nullptr zurück
}