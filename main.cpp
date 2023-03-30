#include <iostream>
#include <vector>
#include <string>
#include "Labor_1/labor1.hpp"
#include "Labor_2/labor2.hpp"

int main(int argc, char *argv[]) {
	while (true) {
// Aufgabe 16 von Labor 1
		std::cout << "Welche Labor Aufgaben sollen angezeigt werden?"
				  << std::endl
		          << "0. Exit"
				  << std::endl
		          << "1. Labor1"
				  << std::endl
		          << "2. Labor2"
				  << std::endl
		          << "Eingabe: ";
		int lab;
		std::cin >> std::ws >> lab;

// Switch
		switch (lab) {
			case 0:
				std::cout << "Beende."<<std::endl; exit(0);
			case 1: // Labor 1
				// Aufgabe 1 - Vektor bekommt alle argv Elemente
				static std::vector<std::string> vArgs;

				for (auto i{1}; i < argc; i++) {
					vArgs.emplace_back(argv[i]);
				}

				// Vector wird übergeben an die Function labor1 in labor1.cpp
				labor1(vArgs);
				break;
			case 2: // Labor 2
				lab2Main();
				std::cout << "Hier Gibt es noch Nichts!" << std::endl;
				break;
			default:
				std::cout << "Eingabe konnte nicht verstanden werden, bitte "
				             "versuchen Sie es erneut." << std::endl;
				break;
		}
	}
}