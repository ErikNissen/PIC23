#include <iostream>
#include <filesystem>
#include "dateiverwaltung.hpp"

// Aufgabe 10
const std::string read( const std::string& path ) {
	if(!std::filesystem::exists(path)){
		throw std::invalid_argument("Datei nicht gefunden.");
	}
	std::ifstream tmp(path);

	// Aufgabe 11
	if(!tmp.is_open()){
		std::cerr << "Datei "<< path <<" konnte nicht geöffnet werden." <<
		std::endl;
		return "";
	}
	return {
			( std::istreambuf_iterator<char>( tmp ) ), // Lese Zeichen für
			// Zeichen der Datei ein
			std::istreambuf_iterator<char>() // Endmarkierung
	};
}