#include <iostream>

#include "labor2.hpp"
#include "Teil_A/A.hpp"
#include "dishlib/DishFactory.hpp"
#include "Customer.hpp"
#include <random>

int lab2Main(){
	static signed int choice{-1};

	while (0 != choice ){
		std::cout << "Welcher Teil der Labor Aufgaben sollen angezeigt werden?\n"
		          << "0. Exit\n"
		          << "1. Teil A\n"
		          << "2. Teil B\n"
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

int dish(){
	/// Aufgabe 8
	using DishType = std::unique_ptr<dishlib::AbstractDish>;
	using Gericht = dishlib::DishFactory::DishType;
	using Kunde = std::unique_ptr<Customer>;

	std::vector<DishType> vDishes;

	/// Aufgabe 9
	dishlib::DishFactory df;
	// erzeuge dishes
	DishType gericht1{df.CreateDish(Gericht::PizzaMargherita)};
	DishType gericht2{df.CreateDish(Gericht::VegetableSoup)};
	// move in vektor
	vDishes.emplace_back( std::move(gericht1));
	vDishes.emplace_back( std::move(gericht2));

	/// Aufgabe 10
	std::sort( vDishes.begin(), vDishes.end(), [](const DishType &a, const
	DishType &b){ // sort mit Lambda Ausdruck []()
		return a->GetNumberIngredients() < b->GetNumberIngredients();
	});

	/// Aufgabe 11
	// Gib für jedes Gericht die Menge an Zutaten aus.
	for(const auto &dish : vDishes){
		std::cout << dish->GetDishName() << ": " <<
		dish->GetNumberIngredients() << " Zutaten" << std::endl;
	}

	/// Aufgabe 12
	std::vector<Kunde> kunden; // Vektor mit Kunden erzeugen

	std::array<std::string, 6> namen{ // Die Kunden für den Vektor
		"Hannes Mueller",
		"Anna Schneider",
		"Herbert Mayer von Lichtenstein",
		"Julia Wolf",
		"Max Mustermann",
		"Bertina Mueller"
	};

	for(auto &name : namen){ // Füge Kundenliste den Vektor Hinzu
		Kunde k{ std::move(std::make_unique<Customer>(name))};
		kunden.emplace_back( std::move(k));
	}

	/// Aufgabe 13
	for(auto &kunde : kunden){ // Jeder Kunde erhält ein dish
		// Erzeuge ein zufälligen Index
		auto index{ randomNumber(0, vDishes.size() - 1)};

		// Serviere das Gericht dem Kunden
		kunde->ServeDish( std::move(vDishes[index]));

		// Lösche das Gericht aus dem Vektor
		vDishes.erase(vDishes.begin() + index);
	}

	// Aufgabe 14
	for(const auto &kunde : kunden){
		kunde->EatDish(); // Kunde verspeist dish
	}
}