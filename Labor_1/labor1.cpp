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

static Person setGebDat(Person &p, const int tag, const int monat, const int
jahr
) {
	p.geburtsdatum.tm_mday = tag;
	p.geburtsdatum.tm_mon = monat - 1;
	p.geburtsdatum.tm_year = jahr - 1900;
	return p;
}

// Aufgabe 13
static Person berechneAlter(Person &p) {
	// Wandle Geburtstagsdatum in time_point um.
	auto geburtszeitpunkt{std::chrono::system_clock::from_time_t(
			std::mktime(&p.geburtsdatum))};

	// Hole das heutige Datum & Uhrzeit
	auto jetzt{std::chrono::system_clock::now()};

	// Bilde die Differenz von jetzt & geburtszeitpunkt
	auto age{std::chrono::duration_cast<std::chrono::hours>
	(jetzt - geburtszeitpunkt).count()};

	std::cout << "Berechne das Alter von Person: '" << p.vorname << " " <<
	p.nachname << "' in Jahren, Tagen und Stunden: " << std::endl;

	// Splitte age in Jahren, Tagen & Stunden auf.
	auto jahre{age / 8766l};
	auto tage{(age % 8766l) / 24l};
	auto stunden{age % 24l};

	p.alter = {jahre, tage, stunden};

	std::cout << "Die Person ist: " << p.alter.jahre << " Jahre, " << p
	.alter.tage << " Tage und " << p.alter.stunden << " Stunden alt." <<
	std::endl;

	return p;
}

// Aufgabe 14
static void alter2Textform(Person &p) {
	std::cout << "\nAufgabe 14" << std::endl;

	const auto alter{p.alter.jahre};

	std::string text;
	const std::array<std::string, 10> einer{
			"Eins", "Zwei", "Drei", "Vier",
			"Fuenf", "Sechs", "Sieben", "Acht", "Neun"
	};
	const std::array<std::string, 10> hunderte{
			"Hundert", einer[1]+"hundert",einer[2]+"hundert",
			einer[3]+"hundert", einer[4]+"hundert", einer[5]+"hundert",
			einer[6]+"hundert", einer[7]+"hundert", einer[8]+"hundert"
	};
	const std::array<std::string, 10> zehner{
			"Zwanzig", einer[2]+"ssig", einer[3]+"zig",
			einer[4]+"zig", einer[5]+"zig", einer[6]+"zig", einer[7]+"zig",
			einer[8]+"zig"
	};
	const std::array<std::string, 10> teens{
		"Zehn", "Elf", "Zwölf", einer[2]+"zehn", einer[3]+"zehn",
		einer[4]+"zehn", "Sechzehn", "Siebzehn", einer[7]+"zehn",
		einer[8]+"zehn"
	};

	if(alter == 0){
		text = "Null";
	}else if (alter < 10){
		text = einer[alter];
	}else if(alter < 20){
		text = teens[alter - 10];
	}else if (alter < 100){
		auto z{alter/10};
		auto e{alter%10};
		if(e > 0){
			if(e == 1){
				// Entfehrne das 's' von "Eins"
				text += einer[0].substr(0, einer[0].size()-1);
			}else{
				text += einer[e-1];
			}
			text += "und";
		}
		if(e == 0){
			text += zehner[z - 2];
		}else{
			text += lower(zehner[z - 2]);
		}

	}else if (alter < 1000){
		// Teile das Alter in Hunderte, Zehner und Einer auf.
		const auto h{alter/100};
		const auto z{(alter%100)/10};
		const auto e{alter % 10};

		text += hunderte[h - 1];

		if(z > 1){
			text += lower(zehner[z - 2]);
			if(e > 0){
				text += einer[e] + "und";
			}
			text += zehner[z - 2];
		}else{
			if(e > 0){
				text += teens[e];
			}else{
				text += lower(zehner[z - 1]);
			}
		}
	}


	std::cout << "Person "<<p.vorname << " "<<p.nachname<<" ist ";

	// Optional: Gebe umlaute korrekt aus.
	for (int i{0}; i < text.length(); i++) {
		if (text[i] == 'u' && text[i + 1] == 'e') {
			std::cout << ue;
			i++;
		}else if (text[i] == 'o' && text[i + 1] == 'e'){
			std::cout << oe;
			i++;
		}else if(text[i] == 'a' && text[i + 1] == 'e'){
			std::cout << ae;
			i++;
		}else if (text[i] == text[i + 1] && text[i + 1] == 's'){
			std::cout << ss;
			i++;
		}else {
			std::cout << text[i];
		}
	}
	std::cout << " (=" << alter <<") Jahre alt." << std::endl;
}

static int fibonacci(int n) { // Aufgabe 3
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int labor1(std::vector<std::string> &vecArgs) {
    aufgabe_1(vecArgs);
	static const auto zahl{aufgabe_2(vecArgs)};
	aufgabe_3( vecArgs );
	aufgabe_4(zahl);
	aufgabe_5(zahl);
	aufgabe_6(vecArgs, 0);
    aufgabe_9();

	std::string personendaten;
	for(const auto& arg: vecArgs){
		if(arg.find_first_of("txt") != std::string::npos){
			personendaten = arg;
		}
	}
	aufgabe_10(personendaten);
    return 0;
}

static void aufgabe_1(std::vector<std::string> &vecArgs) {
    // Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout ausgegeben.
    std::cout << "Aufgabe 1:\nDie Elemente im Vector sind: ";
    for (const auto &i: vecArgs) { // check if this is correct
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// Aufgabe 2 - String to double
static double aufgabe_2(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 2" << std::endl;
	double zahl;
	for (const auto & vecArg : vecArgs)
		if(vecArg.find_first_of('.') != std::string::npos && vecArg
		.find_first_of("txt") == std::string::npos){

			zahl = stod(vecArg);
			std::cout << zahl << " (double) " << std::endl;
	}
	return zahl;
}

// Aufgabe 3 - Weitere Funktionälitäten: Berechen Fibonachi
static void aufgabe_3(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 3";
	for (const auto & vecArg : vecArgs) {
		try {
			int x{stoi(vecArg)};
			std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
			          " ist " << fibonacci(x);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			std::cout << "\nFibonacci kann nicht Berechnet werden! Grund ist das '" << vecArg << "' keine Zahl ist.";
		}
	}
	std::cout << std::endl;
}

// Mathematische Berechung
static void aufgabe_4(double zahl){
	double sinus;
	std::cout << "\nAufgabe 4" << std::endl;
	sinus = sin(zahl);
	std::cout << "Sinus von " << zahl << " ist: " << sinus << std::endl;
}

// Typumwandlung zu int
static void aufgabe_5(double zahl){
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
static void aufgabe_6(std::vector<std::string> &vecArgs, const int i){
	std::cout << "\nAufgabe 6" << std::endl;
	std::cout << placeholder;
	placeholder += 42;
	std::cout << " += 42 = " << placeholder << std::endl;
	vecArgs[i] = std::to_string(placeholder);
	std::cout << "check vector vecArgs[i] = " << vecArgs[i] << std::endl;
	if (vecArgs[i] == std::to_string(placeholder)){
		std::cout << "Vector wurde erfolgreich bearbeitet!" << std::endl;
		aufgabe_7();
	}else{
		std::cout << "Etwas ist schiefgelaufen!" << std::endl;
	}
}

// Gebe Ganzzahl in HEX an
static void aufgabe_7(){
	std::cout << "\nAufgabe 7" << std::endl;
	std::cout << std::hex << placeholder << " (HEX), " << std::dec << std::endl;
}

// Erzeuge ein Vektor von Personen
static void aufgabe_9() {
	std::cout << "\nAufgabe 9" << std::endl;
	static std::vector<Person> personen;
	static Person p1{
			"Hans",
			"Wurst",
			{0},
			{0, 0, 0}
	};
	p1 = setGebDat(p1, 1,1,2000);
	std::cout << "Person Namens '" << p1.vorname << " " << p1.nachname
	<< "' wurde erfolgreich erstellt" << std::endl;

	// Aufgabe 13
	std::cout << "\nAufgabe 13" << std::endl;
	p1 = berechneAlter(p1);
	personen.emplace_back(p1);

	// Aufgabe 15
	for (auto &p: personen) {
		std::cout << "\nAufgabenteil 15\nPerson" << std::endl;
		// Aufgabe 14 / 16 / 17 / 18
		alter2Textform(p);
	}
}

static void aufgabe_10(const std::string &path){
	std::cout << "\nAufgabe 10" << std::endl;
	std::string content;
	try {
		content = read( path );
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
	static std::vector<Person> daten;

	static std::stringstream ss(content);
	static std::string line;


	while( std::getline(ss, line)){
		static std::stringstream sa(line);
		static std::string token;
		static int counter{0};
		static Person p;
		p.geburtsdatum = {0};
		p.alter = {0, 0, 0};
		while ( std::getline(sa, token, ',') ){
			token = strip(token);
			if(token.find_first_of('.')!= std::string::npos){
				static std::stringstream sb(token);
				static std::string x;
				while (( std::getline(sb, x, '.')) ){
					switch ( counter ) {
						case 2: p.geburtsdatum.tm_mday = stoi(x); break;
						case 3: p.geburtsdatum.tm_mon = stoi(x) - 1; break;
						case 4: p.geburtsdatum.tm_year = stoi(x) - 1900; break;
						default: std::cerr  << "Something went wrong."
											<< std::endl;
						break;
					}
					counter++;
				}
			}else{
				switch ( counter ) {
					case 0: p.vorname = token; break;
					case 1: p.nachname = token; break;
					default: std::cerr  << "Something went wrong."
										<< std::endl;
					break;
				}
				counter++;
			}

		}
		p = berechneAlter(p);
		daten.emplace_back(p);
	}

	for(auto &person: daten){
		std::cout<<"Vorname: "<<person.vorname<<std::endl;
		std::cout<<"Nachname: "<<person.nachname<<std::endl;
		std::cout<<"Geburtstag: ";
		std::cout<<person.geburtsdatum.tm_mday<<".";
		std::cout<<person.geburtsdatum.tm_mon + 1<<".";
		std::cout<<person.geburtsdatum.tm_year + 1900<<std::endl;
		alter2Textform(person);
		std::cout<<std::endl;
	}
}