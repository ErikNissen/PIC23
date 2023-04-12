#include "VegetableSoup.hpp"

namespace dishlib{
	VegetableSoup::VegetableSoup(std::string _dishName) :
			AbstractDish(_dishName) {}

	void VegetableSoup::Prepare(
			std::vector<std::tuple<std::string, unsigned int>> &zutaten,
			std::vector<std::string> &schritte
	) {
		for(auto &_schritt : schritte){
			this->AddStep(_schritt);
		}

		for(const auto &zutat : zutaten){
			this->AddIngredients(std::get<0>(zutat),
			                     std::get<1>(zutat));
		}

		for(const auto &schritt : this->steps){
			std::cout   << std::get<1>(schritt) << ". "
			            << std::get<0>(schritt)
			            << std::endl;
		}
	}
}
