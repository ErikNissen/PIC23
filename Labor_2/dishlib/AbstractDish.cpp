#include "AbstractDish.hpp"

namespace dishlib{
	void AbstractDish::AddStep(std::string &step){
		auto size{ this->steps.size()};
		auto tmp{ std::make_tuple(size, step)};
		this->steps.emplace_back(tmp);
	}

	const std::string AbstractDish::GetDishName() {
		return this->dishName;
	}

	const zutatenliste AbstractDish::GetIngredients() {
		return this->vIngredients;
	}

	const ull AbstractDish::GetNumberIngredients() {
		size_t counter{0};
		for(const auto &i : this->vIngredients){
			if(get<1>(i) > 1){
				counter += get<1>(i);
			}else{
				counter++;
			}
		}
		return counter;
	}

	void AbstractDish::AddIngredients(
			const std::string &zutat, const unsigned int &anzahl
	) {
		this->vIngredients.emplace_back(zutat,anzahl);
		std::cout << "Zutat '" << zutat << "' hinzugef"<<ue<<"gt." <<
		          std::endl;
	}

	AbstractDish::AbstractDish( std::string &_dishName ) :
	dishName(_dishName)
	{}
}