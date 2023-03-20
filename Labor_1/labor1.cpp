#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include "labor1.hpp"

using namespace std;

// TODO: Fixen
Alter berechneAlter(const Geburtsdatum &gebdat){
	Alter alter;

	time_t jetzt{time(0)};
	tm *ltm{localtime(&jetzt)};

	int aktuellesJahr{1900 + ltm->tm_year};
	int aktuellerMonat{1 + ltm->tm_mon};
	int aktuellerTag{ltm->tm_mday};

	alter.jahre = aktuellesJahr - gebdat.jahr;

	if(aktuellerMonat < gebdat.monat || (aktuellerMonat == gebdat.monat &&
	aktuellerTag < gebdat.tag)){
		alter.jahre--;
	}

	int tagImJahr = 365 * alter.jahre / 4 - alter.jahre / 100 + alter.jahre
			/ 400;

	std::array<int, 12> monate{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(aktuellesJahr % 4 == 0 && (aktuellesJahr % 100 != 0 || aktuellesJahr
	% 400 == 0)){
		monate[1] = 29;
	}

	for(auto i{gebdat.monat - 1}; i < aktuellerMonat - 1; i++){
		tagImJahr += monate[i];
	}

	tagImJahr += aktuellerTag - gebdat.tag;

	alter.tage = tagImJahr;
	alter.stunden = alter.tage * 24;

	return alter;
}

int fibonacci(int n){ // Aufgabe 3
	if(n <= 1){
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int labor1(std::vector<std::string>& vecArgs){
	double zahl, sinus;
	int umgewandelt, counter{0};

	// Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout ausgegeben.
	std::cout << "Die Elemente im Vector sind: ";
	for (auto elem: vecArgs){
		if(elem.find_first_of(".") != string::npos){
			try {
				// Aufgabe 2
				zahl = stod(elem);

				std::cout << zahl << " (double) ";

				// Aufgabe 4
				sinus = sin(zahl);

				// Aufgabe 5
				umgewandelt = static_cast<int>(zahl);
				std::cout << "\n" << umgewandelt;

				// Aufgabe 6
				changeValueOfIntVector(vecArgs, umgewandelt, counter);

				// Aufgabe 7
				std::cout << hex << umgewandelt << " (HEX), " << dec;
			}catch (const exception e) {
				std::cout << elem << ", ";
			}
		}else{
			try{
				// Aufgabe 3
				int x{stoi(elem)};
				std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
				" ist " << fibonacci(x)<< std::endl;
			} catch ( const exception e ) {
				std::cout << elem << ", ";
			}
		}
		counter++;
	}
	std::cout << "" << std::endl;

	for(auto i:vecArgs){ // check if this is correct
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	aufgabe_9();

	return 0;
}

// Aufgabe 6 try - Rechung funktioniert und ergebnis wird in Vector
// reingepackt, aber nicht an richtige position
int changeValueOfIntVector(std::vector<std::string>& vecArgs, int umgewandelt,
						   int counter){
	umgewandelt += 42;
	cout << " += 42 = " << umgewandelt << endl;
	cout << "counter ist auf: " << counter << endl;
	vecArgs[counter] = to_string(umgewandelt);
	return 0;
}

void aufgabe_9(){

//	Person p1 {.vorname = "Herbet"};
//	vector<string> Personen;
//	Personen.emplace_back(p1);

	// Aufgabe 9
	vector<Person> personen{
			Person{"Max", "Musterman",
			       Geburtsdatum{1,1,1901},
				   berechneAlter(Geburtsdatum{1, 1, 1901})}
	};

	for(auto p: personen){
		cout << "Person"<<endl;
		cout << p.alter.jahre<<endl;
		cout << p.alter.tage<<endl;
		cout << p.alter.stunden<<endl;
	}
}