#include "PizzaMargherita.hpp"

namespace dishlib{
	PizzaMargherita::PizzaMargherita( std::string _dishName ) :
			AbstractDish(_dishName) {}

	void PizzaMargherita::Prepare(
			std::vector<std::tuple<std::string, unsigned int>> &zutaten,
			std::vector<std::string> &schritte
	)  {
		for(auto &_schritt : schritte){
			this->AddStep(_schritt);
		}

		for(const auto &zutat : zutaten){
			this->AddIngredients(std::get<0>(zutat),
			                     std::get<1>(zutat));
		}
		std::cout << this->GetDishName();
		std::cout << std::endl;
		std::cout << "Zutaten: " << std::endl;
		for(const auto &zutat : this->GetIngredients()){
			std::cout << std::get<1>(zutat) << "x " << std::get<0>(zutat)
			          << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Bereite zu..." << std::endl;
		for(const auto &schritt : this->steps){
			std::cout << "Schritt ";
			std::cout << std::get<0>(schritt) + 1 << ": "
			          << std::get<1>(schritt)
			          << std::endl;
		}
	}
}