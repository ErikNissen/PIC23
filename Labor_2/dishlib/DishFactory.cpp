#include "DishFactory.hpp"

auto getInput(){
	std::vector<std::tuple<std::string, unsigned int>> _zutaten;
	std::cout << "Bitte geben Sie die Zutaten"
				 " ein und beenden Sie mit Enter\n(z.B.: 2 "
				 "Apfel, 3 "
				 "Zwiebel)"
				 << std::endl;
	bool running{true};
	while ( running ){
		while (true) {
			std::cout << _zutaten.size() + 1 << ". ";
			std::string input, zutat, anzahl;
			std::cin.clear();
			std::cin.sync();
			std::getline(std::cin, input);
			std::stringstream ss(input);

			ss >> anzahl >> zutat;
			ss.clear();
			ss.sync();
			input.clear();

			if(zutat.empty() && !_zutaten.empty()){
				running = false;
				break;
			}else if(!zutat.empty()){
				try {
					std::stoi( anzahl );
				} catch ( const std::exception &e ) {
					std::cout << anzahl << " ist keine Zahl.";
				}
				try {
					std::stoi(zutat);
					std::cout << zutat << " ist keine Zutat.";
				}catch ( const std::exception &e ){
					_zutaten.emplace_back(zutat, stoi(anzahl));
					break;
				}
			}else{
				std::cout << "Gericht muss min. eine Zutat beinhalten."
						  << std::endl;
			}
		}
	}

	std::cout << "Bitte geben Sie die Zubereitungsschritte "
	             " an und beenden Sie mit Enter"
	          << std::endl;

	std::vector<std::string> _schritte;
	while ( true ){
		std::cout << _schritte.size() + 1 << ". ";
		static std::string input;
		std::cin.clear();
		std::cin.sync();
		input.clear();
		getline(std::cin, input, '\n');
		if(input.empty() && !_schritte.empty()){
			break;
		}else if(!input.empty()){
			_schritte.emplace_back(input);
		}else if(input.empty() && _schritte.empty()){
			std::cout << "Gericht muss min. ein Zubereitungsschritt "
						 "beinhalten." << std::endl;
		}
	}

	return std::make_tuple(_zutaten, _schritte);
}

namespace dishlib{
	std::unique_ptr<AbstractDish>
	 DishFactory::CreateDish(const DishFactory::DishType& dishType ) {
		std::cout << std::endl << "Gericht: ";
		switch ( dishType ) {
			case DishType::PizzaMargherita: {
				std::cout << "Pizza Margherita" << std::endl;
				static auto tmp{ getInput() };

				static PizzaMargherita p{ "Pizza Margherita" };
				p.Prepare( std::get<0>(tmp), std::get<1>( tmp ) );

				return std::make_unique<PizzaMargherita>( p );
			}

			case DishType::VegetableSoup:{
				std::cout << "Suppe" << std::endl;
				static auto tmp{ getInput() };

				VegetableSoup v{"Suppe"};
				v.Prepare(std::get<0>( tmp ), std::get<1>( tmp ));

				return std::make_unique<VegetableSoup>(v);
			}
			default:
				std::cerr << "Irgendetwas ist schief gelaufen!" << std::endl;
				break;
		}
	}

	void DishFactory::ListDishes() {
		auto counter{1};
		for(auto d{DishType::begin};
			d < DishType::end;
			d = static_cast<DishType>(static_cast<size_t>(d) + 1)){
			std::cout << counter << ". ";
			counter++;
			switch ( d ) {
				case DishType::VegetableSoup:
					std::cout << "Suppe" << std::endl;
					break;
				case DishType::PizzaMargherita:
					std::cout << "Pizza Margherita" << std::endl;
				default:
					break;
			}
		}
	}
}