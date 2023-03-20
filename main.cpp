#include <iostream>
#include <vector>
#include <array>
#include <string>


#include "Labor_1/labor1.hpp"

using namespace std;

int main(int argc, char *argv[]){

	// Aufgabe 1 Labor 1: Vektor bekommt alle argv Elemente
	vector<string> vecArgs;

	for(int i{1}; i<argc; i++)
	{
		vecArgs.emplace_back( argv[ i ] );
	}

	// Vector wird übergeben an die Function labor1 in labor1.cpp
	labor1(vecArgs);


	return 0;
}