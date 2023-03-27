#include "dishlib.hpp"

// Aufgabe 3
namespace dishlib{

	void AbstractDish::AddStep(const std::string &step){
		// TODO: Fix
		/*
		this->steps.emplace_back(std::make_tuple(step, this->steps
		                                                .size() + 1));
		                                                */
	}

	std::string AbstractDish::GetDishName() {
		return this->dishName;
	}

	zutatenliste AbstractDish::GetIngredients() {
		return this->vIngredients;
	}

	int AbstractDish::GetNumberIngredients() {
		auto counter{0};
		for(const auto &zutat : this->vIngredients){
			counter++;
		}
		return counter;
	}

	void AbstractDish::AddIngredients(
			const std::string &zutat, const int &anzahl
	) {
		this->vIngredients.emplace_back(zutat,anzahl);
		std::cout << "Zutat '" << zutat << "' hinzugef"<<ue<<"gt." <<
		std::endl;
	}

	AbstractDish::AbstractDish( std::string &_dishName ) {
		this->dishName = _dishName;
	}



	void VegetableSoup::Prepare(
			std::vector<std::tuple<std::string, int>> &zutaten,
			std::vector<std::string> &schritte
	) {
		for(const auto &_schritt : schritte){
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

	void PizzaMargherita::Prepare(
			std::vector<std::tuple<std::string, int>> &zutaten,
			std::vector<std::string> &schritte
	) {
		for(const auto &_schritt : schritte){
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