

#ifndef PIC23_LABOR1_HPP
#define PIC23_LABOR1_HPP

#include <chrono>
#include <iostream>

int labor1(std::vector<std::string>& vecArgs);

void aufgabe_1(std::vector<std::string>& vecArgs);
void aufgabe_2(const std::string &vec);
void aufgabe_3(std::vector<std::string> &vecArgs);
void aufgabe_4(double);
void aufgabe_5(double);
void aufgabe_6(std::vector<std::string>& vecArgs, const int);
void aufgabe_7();
void aufgabe_8();
void aufgabe_9();
void aufgabe_10();
void aufgabe_11();
void aufgabe_12();
void aufgabe_13();
void aufgabe_14();
void aufgabe_15();
void aufgabe_16();
void aufgabe_17();
void aufgabe_18();
void aufgabe_19();
void aufgabe_20();
void aufgabe_21();
void aufgabe_22();

// Aufgabe 8
using Alter = struct{
    int jahre;
    int tage;
    int stunden;
};

using Person = struct{
    std::string vorname;
    std::string nachname;
    std::tm geburtsdatum;
    Alter alter;

    void setGebDat(int tag, int monat, int jahr);

    // Aufgabe 13
    void berechneAlter();

    void alter2Textform() const;
};

#endif //PIC23_LABOR1_HPP

