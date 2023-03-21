#include <iostream>
#include <vector>
#include <array>
#include <string>


#include "Labor_1/labor1.hpp"


int main(int argc, char *argv[]){

	// Aufgabe 1 Labor 1: Vektor bekommt alle argv Elemente
	std::vector<std::string> vecArgs;

	for(int i{1}; i<argc; i++)
	{
		vecArgs.emplace_back( argv[ i ] );
	}

	// Vector wird übergeben an die Function labor1 in labor1.cpp
	labor1(vecArgs);


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