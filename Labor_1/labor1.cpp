#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include <conio.h>
#include "labor1.hpp"
#include "../globals.hpp"
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
	const auto geburtszeitpunkt{std::chrono::system_clock::from_time_t(
			std::mktime(&p.geburtsdatum))};

	// Hole das heutige Datum & Uhrzeit
	const auto jetzt{std::chrono::system_clock::now()};

	// Bilde die Differenz von jetzt & geburtszeitpunkt
	const auto age{std::chrono::duration_cast<std::chrono::hours>
	(jetzt - geburtszeitpunkt).count()};

	std::cout << "Berechne das Alter von Person: '" << p.vorname << " " <<
	p.nachname << "' in Jahren, Tagen und Stunden: " << std::endl;

	// Splitte age in Jahren, Tagen & Stunden auf.
	const auto jahre{age / 8766l};
	const auto tage{(age % 8766l) / 24l};
	const auto stunden{age % 24l};

	p.alter = {jahre, tage, stunden};

	std::cout << "Die Person ist: " << p.alter.jahre << " Jahre, " << p
	.alter.tage << " Tage und " << p.alter.stunden << " Stunden alt." <<
	std::endl;

	return p;
}

// Aufgabe 14
static const void alter2Textform(const Person &p) {
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
		const auto z{alter/10};
		const auto e{alter%10};
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
	getchar();
	static const auto zahl{aufgabe_2(vecArgs)};
	getch();
	aufgabe_3( vecArgs );
	getch();
	aufgabe_4(zahl);
	getch();
	aufgabe_5(zahl);
	getch();
	aufgabe_6(vecArgs, 0);
	getch();
    aufgabe_9();
	getch();

	std::string personendaten;
	for(const auto& arg: vecArgs){
		if(arg.find_first_of("txt") != std::string::npos){
			personendaten = arg;
		}
	}
	aufgabe_10(personendaten);

	fragen();
    return 0;
}

static const void fragen(){
	using namespace std;

	cout << GREEN << BOLD << endl << endl
	     << "Frage 1: "
	     << "Wann setze ich Pointer ein?"
		 << endl << RESET;
	cout << YELLOW << endl
	     << "Antwort: "
		 << endl
	     << "- Wenn man die Lebensdauer eines Objektes kontrollieren "
			"m"<<oe<<"chte."
		 << endl
		 << "- Wenn man gr"<<oe<<ss<<"ere Objekte "<<ue<<"bertragen will."
		 << endl << RESET;
	getch();
	cout << GREEN << BOLD << endl << endl
		 << "Frage 2: "
	     << "Wann setze ich Referenzen ein?"
	     << endl << RESET;
	cout << YELLOW << endl
		 << "Antwort: "
	     << endl
	     << "- Verwendung als Aliasname f"<<ue<<"r ein bereits bestehendes Objekt."
	     << endl << RESET;
	getch();
	cout << GREEN << BOLD << endl << endl
		 << "Frage 3: "
	     << "Was ist der Unterschied zwischen Pointern und Referenzen?"
	     << endl << RESET;
	cout << YELLOW << endl
		 << "Antwort: "
	     << endl
		 << "- Eine Referenz muss immer initialisiert werden und zeigt immer "
			"auf dasselbe \nObjekt.\n"
		    "- Ein Zeiger kann auf etwas anderes zeigen oder ein nullptr sein."
		 << endl
		 << "- Eine Referenz ist kein eigenst"<<ae<<"ndiges Objekt wie ein "
				"Zeiger, sondern nur ein Aliasname f"<<ue<<"r ein bereits "
														   "bestehendes "
														   "\nObjekt."
	     << "ein Pointer hat eine eigene Speicheradresse und eine Referenz hat "
			"keine, da es eine vorhandene Variable ist."
	     << endl << RESET;
	getch();
	cout << GREEN << BOLD << endl << endl
		 << "Frage 4: "
	     << "Wozu setzt man \"const\" ein?"
	     << endl << RESET;
	cout << YELLOW << endl
		 << "Antwort: "
	     << endl
	     << "- Wenn eine Variable im nachgang nicht mehr ver"<<ae<<"ndert "
			"werden soll."
	     << endl << RESET;
	getch();
	cout << GREEN << BOLD << endl << endl
		 << "Frage 5: "
	     << "Was ist call-by-value und call-by-reference? Unterschiede und "
			"Einsatzzwecke?"
	     << endl << RESET;
	cout << YELLOW << endl
		 << "Antwort: "
	     << endl
	     << "- Bei call-by-value wird eine Kopie des Arguments an die "
			"\nFunktion "
		 << ue<<"bergeben. "<<AE<<"nderungen an dem Argument innerhalb der "
			"Funktion haben keine Auswirkungen auf das urspr"<<ue<<"ngliche "
			"Argument au"<<ss<<"erhalb der Funktion."
		 << endl
		 << "- Wird verwendet, wenn die Funktion nur mit dem Wert des Arguments "
			"arbeiten muss und keine "<<AE<<"nderungen am urspr"<<ue<<"nglichen "
			"Argument vorgenommen werden sollen."
		 << endl
		 << "- Call-by-reference "<<ue<<"bergibt eine Referenz auf das "
			"Argument an die Funktion. "<<ae<<"nderungen an dem Argument "
			"innerhalb der Funktion wirken sich direkt auf das urspr"<<ue
		 << "ngliche Argument au"<<ss<<"erhalb der Funktion aus."
	     << endl
		 << "- Wird verwendet, wenn die Funktion "<<AE<<"nderungen am "
			"urspr"<<ue<<"nglichen Argument vornehmen soll oder wenn das "
		 << UE<<"bergeben einer \nKopie des Arguments zu teuer w"<<ae<<"re (z"
			".B. bei gro"<<ss<<"en Datenstrukturen)."
		 << endl << RESET;
	getch();
	cout << GREEN << BOLD << endl << endl
		 << "Frage 6: "
	     << "Eine Funktionsdeklaration beinhaltet einen Pointer als Argument, "
			"bspw. “void func(int *value);”. Inwiefern kann/muss der Aufruf "
			"dieser Funktion als call-by-value aufgefasst werden?"
	     << endl << RESET;
	cout << YELLOW << endl
		 << "Antwort: "
		 << endl
	     << "Wenn die Funktion aufgerufen wird, wird der Wert des Zeigers als "
			"call-by-value an die Funktion "<<ue<<"bergeben. Das bedeutet, "
			"dass innerhalb der Funktion eine Kopie des Zeigers erstellt wird "
			"und "<<AE<<"nderungen an dem Zeiger selbst innerhalb der "
						"\nFunktion "
			"keine Auswirkungen auf den urspr"<<ue<<"nglichen Zeiger au"<<ss<<"erhalb "
			"der Funktion haben. Allerdings kann die Funktion den Wert "
		 << ae<<"ndern, auf den der Zeiger zeigt (der int-Wert), da sie eine "
				"Kopie der Adresse dieses Werts hat."
	     << endl << RESET;
}

static const void aufgabe_1(std::vector<std::string> &vecArgs) {
    // Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout
	// ausgegeben.
    std::cout << "Aufgabe 1:\nDie Elemente im Vector sind: ";
    for (auto &i: vecArgs) { // check if this is correct
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// Aufgabe 2 - String to double
static double aufgabe_2(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 2" << std::endl;
	double zahl;
	for (auto & vecArg : vecArgs)
		if(vecArg.find_first_of('.') != std::string::npos && vecArg
		.find_first_of("txt") == std::string::npos){

			zahl = stod(vecArg);
			std::cout << zahl << " (double) " << std::endl;
	}
	return zahl;
}

// Aufgabe 3 - Weitere Funktionälitäten: Berechen Fibonachi
static const void aufgabe_3(std::vector<std::string> &vecArgs) {
	std::cout << "\nAufgabe 3";
	for (const auto & vecArg : vecArgs) {
		try {
			int x{stoi(vecArg)};
			std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
			          " ist " << fibonacci(x);
		} catch (const std::exception &e) {
			std::cout << "\nFibonacci kann nicht Berechnet werden! Grund ist "
						 "das '" << vecArg << "' keine Zahl ist.";
		}
	}
	std::cout << std::endl;
}

// Mathematische Berechung
static const void aufgabe_4(double zahl){
	double sinus;
	std::cout << "\nAufgabe 4" << std::endl;
	sinus = sin(zahl);
	std::cout << "Sinus von " << zahl << " ist: " << sinus << std::endl;
}

// Typumwandlung zu int
static const void aufgabe_5(double zahl){
	int umgewandelt;
	std::cout   << "\nAufgabe 5" << std::endl;
	std::cout   << "Wandle zahl von Aufgabe 2 um in einen Integer, zahl "
				   "lautet aktuell: " << zahl<< std::endl;
	umgewandelt = static_cast<int>(zahl);
	std::cout   << "zahl wurde erfolgreich umgewandelt und lautet: "
				<< umgewandelt << std::endl;

	// übergabe an Global Var für aufgabe 6 und 7
	placeholder = umgewandelt;
}

// Ändern einer Ganzzahl im vector
static const void aufgabe_6(std::vector<std::string> &vecArgs, const int i){
	std::cout << "\nAufgabe 6" << std::endl;
	std::cout << placeholder;
	placeholder += 42;
	std::cout << " += 42 = " << placeholder << std::endl;
	vecArgs[i] = std::to_string(placeholder);
	std::cout << "check vector vecArgs[i] = " << vecArgs[i] << std::endl;
	if (vecArgs[i] == std::to_string(placeholder)){
		std::cout << "Vector wurde erfolgreich bearbeitet!" << std::endl;
		getch();
		aufgabe_7();
	}else{
		std::cout << "Etwas ist schiefgelaufen!" << std::endl;
	}
}

// Gebe Ganzzahl in HEX an
static const void aufgabe_7(){
	std::cout << "\nAufgabe 7" << std::endl;
	std::cout << std::hex << placeholder << " (HEX), " << std::dec << std::endl;
}

// Erzeuge ein Vektor von Personen
static const void aufgabe_9() {
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
	getch();
	std::cout << "\nAufgabe 13" << std::endl;
	p1 = berechneAlter(p1);
	personen.emplace_back(p1);

	// Aufgabe 15
	getch();
	for (auto &p: personen) {
		std::cout << "\nAufgabenteil 15\nPerson" << std::endl;
		// Aufgabe 14 / 16 / 17 / 18
		alter2Textform(p);
	}
}

static const void aufgabe_10(std::string &path){
	std::cout << "\nAufgabe 10" << std::endl;
	std::string content;
	while(true) {
		try {
			content = read( path );
			break;

		} catch ( std::exception &e ) {
			std::cerr << e.what() << std::endl;
			std::cout << "Programm [b]eenden oder [P]fad ändern?" << std::endl;
			static std::string tmp;

			std::cin >> std::ws >> tmp;
			if( lower(tmp) == "b"){
				exit(0);
			}else if(lower(tmp) == "p"){
				path = tmp;
			}
		}
	}
	static std::vector<Person> daten;

	static std::stringstream ss(content);
	static std::string line;


	while( std::getline(ss, line)){
		std::stringstream sa(line);
		std::string token;
		int counter{0};
		Person p;
		p.geburtsdatum = {0};
		p.alter = {0, 0, 0};
		while ( std::getline(sa, token, ',') ){
			token = strip(token);
			if(token.find_first_of('.')!= std::string::npos){
				std::stringstream sb(token);
				std::string x;
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
		std::cout<<person.geburtsdatum.tm_year + 1900 <<std::endl;
		alter2Textform(person);
		std::cout<<std::endl;
	}
}