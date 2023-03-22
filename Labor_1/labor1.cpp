#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include <filesystem>
#include "labor1.hpp"
#include "globals.hpp"
#include "dateiverwaltung.hpp"

// Global Variable
int placeholder;

void Person::setGebDat( const int tag, const int monat, const int jahr ) {
	geburtsdatum.tm_mday = tag;
	geburtsdatum.tm_mon = monat - 1;
	geburtsdatum.tm_year = jahr - 1900;
}

// Aufgabe 13
void Person::berechneAlter() {
	auto geburtszeitpunkt{std::chrono::system_clock::from_time_t(std::mktime(&geburtsdatum))};
	auto jetzt{std::chrono::system_clock::now()};
	auto age{static_cast<int>(std::chrono::duration_cast<std::chrono::hours>(jetzt -
	                                                                         geburtszeitpunkt).count())};
	std::cout << "Berechne das Alter von Person: '" << vorname << " " <<
	nachname << "' in Jahren, Tagen und Stunden: " << std::endl;
	alter.jahre = age / 8760;
	alter.tage = (age % 8760) / 24;
	alter.stunden = age % 24;
	std::cout << "Die Person ist: " << alter.jahre << " Jahre, " <<
	alter.tage << " Tage und " << alter.stunden << " Stunden alt." << std::endl;
}

// Aufgabe 14
void Person::alter2Textform() const {
	std::cout << "\nAufgabe 14" << std::endl;
	std::string text;
	std::stringstream umlaut;
	umlaut << "F" << ue << "nf";
	const std::array<std::string, 10> hunderte{
			"hundert", "Ein", "Zwei", "Drei", "Vier", umlaut.str(),
			"Sechs", "Sieben", "Acht", "Neun"
	};
	umlaut.clear();
	umlaut << "Drei" << ss << "ig";
	const std::array<std::string, 10> zehner{
			"zig", "Zehn", "Zwan", umlaut.str(), "Vier",
			"Fünf", "Sech", "Sieb", "Acht", "Neun"
	};
	umlaut.clear();
	umlaut << "F" << ue << "nf";
	const std::array<std::string, 10> einer{
			"Null", "Eins", "Zwei", "Drei", "Vier",
			umlaut.str(), "Sechs", "Sieben", "Acht", "Neun"
	};
	umlaut.clear();
	const int h{alter.jahre / 100};
	const int z{ ( alter.jahre % 100 ) / 10 };
	const int e{ alter.jahre % 10 };

	if(h > 0)
		text += hunderte[0] + hunderte[h];
	if(e > 0)
		text += einer[e];
	if(z > 0)
		if(z == 1)
			if (h == 0)
				text += zehner[1];
			else
				text += lower(zehner[1]);
		else
			text += "und";
	text += lower(zehner[z]) + zehner[0];


	std::cout << "Person ist " << text << " Jahre alt." << std::endl;
}

int fibonacci(int n) { // Aufgabe 3
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int labor1(std::vector<std::string> &vecArgs) {
    aufgabe_1(vecArgs);
	auto zahl{aufgabe_2(vecArgs)};
	aufgabe_3( vecArgs );
	aufgabe_4(zahl);
	aufgabe_5(zahl);
	aufgabe_6(vecArgs, 0);
    aufgabe_9();

	std::string personendaten;
	for(auto arg: vecArgs){
		if(arg.find_first_of('txt') != std::string::npos){
			personendaten = arg;
		}
	}
	aufgabe_10(personendaten);
    return 0;
}

void aufgabe_1(std::vector<std::string> &vecArgs) {
    // Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout ausgegeben.
    std::cout << "Aufgabe 1:\nDie Elemente im Vector sind: ";
    for (const auto &i: vecArgs) { // check if this is correct
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// Aufgabe 2 - String to double
double aufgabe_2(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 2" << std::endl;
	double zahl;
	for (int i = 0; i < vecArgs.size(); i++)
		if(vecArgs[i].find_first_of('.') != std::string::npos && vecArgs[i]
		.find_first_of('txt') == std::string::npos){

			zahl = stod(vecArgs[i]);
			std::cout << zahl << " (double) " << std::endl;
	}
	return zahl;
}

// Aufgabe 3 - Weitere Funktionälitäten: Berechen Fibonachi
void aufgabe_3(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 3";
	for (int i = 0; i < vecArgs.size(); i++) {
		try {
			int x{stoi(vecArgs[i])};
			std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
			          " ist " << fibonacci(x);
		} catch (const std::exception e) {
			std::cout << "\nFibonacci kann nicht Berechnet werden! Grund ist das '" << vecArgs[i] << "' keine Zahl ist.";
		}
	}
	std::cout << std::endl;
}

// Mathematische Berechung
void aufgabe_4(double zahl){
	double sinus;
	std::cout << "\nAufgabe 4" << std::endl;
	sinus = sin(zahl);
	std::cout << "Sinus von " << zahl << " ist: " << sinus << std::endl;
}

// Typumwandlung zu int
void aufgabe_5(double zahl){
	int umgewandelt;
	std::cout << "\nAufgabe 5" << std::endl;
	std::cout << "Wandle zahl von Aufgabe 2 um in einen Integer, zahl lautet aktuell: "
	          << zahl<< std::endl;
	umgewandelt = static_cast<int>(zahl);
	std::cout << "zahl wurde erfolgreich umgewandelt und lautet: " << umgewandelt << std::endl;

	// übergabe an Global Var für aufgabe 6 und 7
	placeholder = umgewandelt;
}

// Ändern einer Ganzzahl im vector
void aufgabe_6(std::vector<std::string> &vecArgs, const int i){
	std::cout << "\nAufgabe 6" << std::endl;
	std::cout << placeholder;
	placeholder += 42;
	std::cout << " += 42 = " << placeholder << std::endl;
	vecArgs[i] = std::to_string(placeholder);
	std::cout << "check vector vecArgs[i] = " << vecArgs[i] << std::endl;
	if (vecArgs[i] == std::to_string(placeholder)){
		std::cout << "Vector wurde Erfolgreich bearbeiten!" << std::endl;
		aufgabe_7();
	}else{
		std::cout << "Etwas ist schiefgelaufen!" << std::endl;
	}
}

// Gebe Ganzzahl in HEX an
void aufgabe_7(){
	std::cout << "\nAufgabe 7" << std::endl;
	std::cout << std::hex << placeholder << " (HEX), " << std::dec << std::endl;
}

// Erzeuge ein Vektor von Personen
void aufgabe_9() {
	std::cout << "\nAufgabe 9" << std::endl;
	std::vector<Person> personen;
	Person p1{
			"Hans",
			"Wurst",
			std::tm{0},
			Alter{0}
	};
	p1.setGebDat(1,1,2000);
	std::cout << "Person Namens '" << p1.vorname
	<< "' wurde erfolgreich erstellt" << std::endl;

	// Aufgabe 13
	std::cout << "\nAufgabe 13" << std::endl;
	p1.berechneAlter();
	personen.emplace_back(p1);

	// Aufgabe 15
	for (auto p: personen) {
		std::cout << "Person" << std::endl;
		// Aufgabe 14 / 16 / 17 / 18
		p.alter2Textform();
	}
}

void aufgabe_10(const std::string &path){
	std::cout << "\nAufgabe 10" << std::endl;
	std::string content{ read( path ) };

	std::vector<Person> daten;

	std::stringstream ss(content);
	std::string line;


	while( std::getline(ss, line)){
		std::array<std::string, 5> tmp;
		std::stringstream sa(line);
		std::string token;
		int counter{0};
		while ( std::getline(sa, token, ',') ){

			if(token.find_first_of('.')!= std::string::npos){
				std::stringstream sb(token);
				std::string x;
				while (( std::getline(sb, x, '.')) ){
					tmp[counter] = x;
					counter++;
				}
			}else{
				tmp[counter] = token;
				counter++;
			}
		}
		Person p{
			tmp[0],
			tmp[1]

		};
		//TODO: FIX
		p.setGebDat(
				stoi(tmp[2]),
				stoi(tmp[3]),
				stoi(tmp[4])
				);
		p.berechneAlter();
		daten.emplace_back(p);
	}

	for(auto &person: daten){
		std::cout<<"Vorname: "<<person.vorname<<std::endl;
		std::cout<<"Nachname: "<<person.nachname<<std::endl;
		std::cout<<"Geburtstag: ";
		std::cout<<person.geburtsdatum.tm_mday<<".";
		std::cout<<person.geburtsdatum.tm_mon<<".";
		std::cout<<person.geburtsdatum.tm_year<<".";
		person.alter2Textform();
		std::cout<<std::endl;
	}
}