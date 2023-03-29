#include "DishFactory.hpp"

auto getInput(){
	std::vector<std::tuple<std::string, unsigned int>> _zutaten;
	std::cout << "Bitte geben Sie die Zutaten"
				 " ein und beenden Sie mit dem Wort 'e e'\n(z.B.: 2 "
				 "Apfel, 3 "
				 "Zwiebel)"
				 << std::endl;
	bool running{true};
	while ( running ){

		std::cout << _zutaten.size() + 1 << ". ";
		std::string zutat, anzahl;
		while (true) {
			std::cin >> anzahl >> zutat;

			if(zutat == "e" or anzahl == "e"){
				running = false;
				break;
			}
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
		}
	}

	std::cout << "Bitte geben Sie die Zubereitungsschritte "
	             " an und beenden Sie 'e'"
	          << std::endl;

	std::vector<std::string> _schritte;
	running = true;
	while ( running ){
		std::cout << _schritte.size() + 1 << ". ";
		static std::string tmp;
		std::cin >> std::ws >> tmp;
		if(tmp == "e"){
			running = false;
			break;
		}else{
			_schritte.emplace_back(tmp);
		}
	}

	return std::make_tuple(_zutaten, _schritte);
}

namespace dishlib{
	std::unique_ptr<AbstractDish>
	 DishFactory::CreateDish(const DishFactory::DishType& dishType ) {
		switch ( dishType ) {
			case DishType::PizzaMargherita: {
				static auto tmp{ getInput() };

				static PizzaMargherita p{ "Pizza Margherita" };
				p.Prepare( std::get<0>(tmp), std::get<1>( tmp ) );

				return std::make_unique<PizzaMargherita>( p );
			}

			case DishType::VegetableSoup:{
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
}