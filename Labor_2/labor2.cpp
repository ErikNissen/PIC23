#include <iostream>

#include "labor2.hpp"
#include "Teil_A/A.hpp"
#include "dishlib/DishFactory.hpp"
#include "Customer.hpp"
#include <random>

int lab2Main(){
	static signed int choice{-1};

	while (0 != choice ){
		std::cout << std::endl
				  << "Welcher Teil der Labor Aufgaben sollen angezeigt werden?"
				  << std::endl
		          << "0. Exit"
				  << std::endl
		          << "1. Teil A"
				  << std::endl
		          << "2. Teil B"
				  << std::endl
		          << "Eingabe: ";
		std::cin >> std::ws >> choice;

		switch (choice) {
			case 0:
				std::cout << "Beende."<<std::endl; break;
			case 1: // Teil A
				lab2AMain();
				break;
			case 2: // Teil B
				dish();
				break;
			default:
				std::cout << "Eingabe konnte nicht verstanden werden, bitte "
				             "versuchen Sie es erneut." << std::endl;
				break;
		}
	}
    return 0;
}

void dish(){
	/// Aufgabe 8
	std::cout << std::endl << "Aufgabe 8" << std::endl;
	using DishType = std::unique_ptr<dishlib::AbstractDish>;
	using Gericht = dishlib::DishFactory::DishType;
	using Kunde = std::unique_ptr<Customer>;

	std::cout << "Erzeuge vDishes" <<std::endl;
	std::vector<DishType> vDishes;

	/// Aufgabe 9
	getch();
	std::cout << std::endl << "Aufgabe 9" << std::endl;
	using df = dishlib::DishFactory;

	// erzeuge dishes
	std::cout << "Erzeuge Gerichte" << std::endl;
	DishType gericht1{df::CreateDish(Gericht::PizzaMargherita)};
	DishType gericht2{df::CreateDish(Gericht::VegetableSoup)};

	// move in vektor
	std::cout << "Verschiebe Gerichte in vDishes" << std::endl;
	vDishes.emplace_back( std::move(gericht1));
	vDishes.emplace_back( std::move(gericht2));

	/// Aufgabe 10
	getch();
	std::cout << std::endl << "Aufgabe 10" << std::endl;
	std::cout << "Sortiere Vektor nach Anzahl der Zutaten der Gerichte" <<
	std::endl;
	std::sort( vDishes.begin(), vDishes.end(), [](const DishType &a, const
	DishType &b){ // sort mit Lambda Ausdruck []()
		return a->GetNumberIngredients() > b->GetNumberIngredients();
	});


	/// Aufgabe 11
	getch();
	std::cout << std::endl << "Aufgabe 11" << std::endl;
	// Gib für jedes Gericht die Menge an Zutaten aus.
	for(const auto &dish : vDishes){
		std::cout << dish->GetDishName() << ": " <<
		dish->GetNumberIngredients() << " Zutaten" << std::endl;
	}

	/// Aufgabe 12
	getch();
	std::cout << std::endl << "Aufgabe 12" << std::endl;
	std::cout << "Erzeuge ein Vektor mit Kunden" << std::endl;
	std::vector<Kunde> kunden; // Vektor für Kunden

	std::array<std::string, 6> namen{ // Die Kunden für den Vektor
			"Hannes Mueller",
			"Anna Schneider",
			"Herbert Mayer von Lichtenstein",
			"Julia Wolf",
			"Max Mustermann",
			"Bertina Mueller"
	};

	std::cout << "Kunden: " << std::endl;
	for(auto &name : namen){ // Füge Kundenliste den Vektor Hinzu
		Kunde k{ std::move(std::make_unique<Customer>(name))};
		kunden.emplace_back( std::move(k));
		std::cout << name << std::endl;
	}

	/// Aufgabe 13
	getch();
	std::cout << std::endl << "Aufgabe 13" << std::endl;
	for(auto &kunde : kunden){ // Jeder Kunde erhält ein dish
		if(vDishes.empty()){
			std::cout << "Keine Gerichte mehr verf"<<ue<<"gbar." << std::endl;
			break;
		}
		// Erzeuge ein zufälligen Index
		auto index{ randomNumber(0, vDishes.size() - 1)};
		std::cout << "Person " << kunde->getName() << " bekommt das Gericht "
		<< vDishes[index]->GetDishName() << std::endl;

		// Serviere das Gericht dem Kunden
		kunde->ServeDish( std::move(vDishes[index]));

		// Lösche das Gericht aus dem Vektor
		vDishes.erase(vDishes.begin() + static_cast<signed long long>(index));
	}

	// Aufgabe 14
	getch();
	std::cout << std::endl << "Aufgabe 14" << std::endl;
	std::cout << "Kunden verspeisen die Gerichte" << std::endl;
	for(const auto &kunde : kunden){
		kunde->EatDish(); // Kunde verspeist dish
	}
}