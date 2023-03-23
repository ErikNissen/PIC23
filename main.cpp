#include <iostream>
#include <vector>
#include <string>
#include "Labor_1/labor1.hpp"

int main(int argc, char *argv[]) {

	int lab {-1};
	while (lab != 0) {
// Aufgabe 16 von Labor 1
		std::cout << "Welche Labor Aufgaben sollen angezeigt werden?\n"
		          << "0. Exit\n"
		          << "1. Labor1\n"
		          << "2. Labor2\n"
		          << "Eingabe: ";
		std::cin >> std::ws >> lab;

// Switch
		switch (lab) {
			case 0:
				std::cout << "Beende."<<std::endl; break;
			case 1: // Labor 1
				// Aufgabe 1 - Vektor bekommt alle argv Elemente
				static std::vector<std::string> vArgs;

				for (int i{1}; i < argc; i++) {
					vArgs.emplace_back(argv[i]);
				}

				// Vector wird übergeben an die Function labor1 in labor1.cpp
				labor1(vArgs);
				break;
			case 2: // Labor 2
				std::cout << "Hier Gibt es noch Nichts!" << std::endl;
				break;
			default:
				std::cout << "Eingabe konnte nicht verstanden werden, bitte "
				             "versuchen Sie es erneut." << std::endl;
				break;
		}
	}
	return 0;
}


//int l1(std::vector<std::string> &vecArgs) {
//    double zahl;
//    for (int i = 0; i < vecArgs.size(); i++) {
//        if (vecArgs[i].find_first_of(",") != std::string::npos) {
//            try {
//                std::cout << "\na_2\n" << std::endl;
//                std::replace(vecArgs[i].begin(), vecArgs[i].end(), ',', '.');
//                zahl = stod(vecArgs[i]);
//                std::cout << zahl << " (double) ";
//            } catch (const std::exception e) {
//                std::cout << "there was an error" << std::endl;
//            }
//        }
//    }
//}