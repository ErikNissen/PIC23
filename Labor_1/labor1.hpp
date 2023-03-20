

#ifndef PIC23_LABOR1_HPP
#define PIC23_LABOR1_HPP

int labor1(std::vector<std::string>& vecArgs);

int changeValueOfIntVector(std::vector<std::string>& vecArgs, int, int);

void aufgabe_9();

// Aufgabe 8
using Geburtsdatum = struct{
	int tag;
	int monat;
	int jahr;
};

using Alter = struct{
	int jahre;
	int tage;
	int stunden;
};

using Person = struct{
	std::string vorname;
	std::string nachname;
	Geburtsdatum geburtsdatum;
	Alter alter;
};

#endif //PIC23_LABOR1_HPP
