#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "Labor_1/labor1.hpp"

int main(int argc, char *argv[]) {
    int lab {-1};
    while (lab != 0) {
// Eingabe
        std::cout << "Welche Labor Aufgaben sollen angezeigt werden?\n"
                  << "0. Exit\n"
                  << "1. Labor1\n"
                  << "2. Labor2\n"
                  << std::endl;
        std::cin >> lab;

// Switch
        switch (lab) {
            case 1: // Labor 1
                // Aufgabe 1 - Vektor bekommt alle argv Elemente
                std::vector<std::string> vecArgs;

                for (int i{1}; i < argc; i++) {
                    vecArgs.emplace_back(argv[i]);
                }

                // Vector wird übergeben an die Function labor1 in labor1.cpp
                labor1(vecArgs);
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