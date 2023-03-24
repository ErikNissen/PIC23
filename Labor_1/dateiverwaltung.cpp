#include <iostream>
#include <filesystem>
#include "dateiverwaltung.hpp"

// Aufgabe 10
std::string read( const std::string& path ) {
	// Prüfe, ob Datei vorhanden ist.
	if(!std::filesystem::exists(path)){
		throw std::invalid_argument("Datei "+path+" nicht gefunden.");
	}
	std::ifstream tmp(path);

	// Aufgabe 11
	// Wenn Datei nicht geöffnet werden kann, gib ein Fehler aus.
	if(!tmp.is_open()){
		std::cerr << "Datei "<< path <<" konnte nicht geöffnet werden." <<
		std::endl;
		return "";
	}
	return {
			( std::istreambuf_iterator<char>( tmp ) ), // Lese
			// Zeichen für Zeichen der Datei ein
			std::istreambuf_iterator<char>() // Endmarkierung
	};
}