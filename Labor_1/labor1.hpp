#ifndef PIC23_LABOR1_HPP
#define PIC23_LABOR1_HPP

#pragma once

#include <chrono>
#include <iostream>
int labor1(std::vector<std::string>& vecArgs);

static void fragen();

static void aufgabe_1(std::vector<std::string>& vecArgs);
static double aufgabe_2(std::vector<std::string>& vecArgs);
static void aufgabe_3(std::vector<std::string> &vecArgs);
static void aufgabe_4(double);
static void aufgabe_5(double);
static void aufgabe_6(std::vector<std::string>& vecArgs, int);
static void aufgabe_7();
// 8 - Definition eines eigenen Datentyps “Person” als Sturktur
static void aufgabe_9();
static void aufgabe_10(const std::string &path);
// 11 - Abfangen von C++ Exceptions beim Einlesen der Datei
//      (bspw. Datei nicht vorhanden).
// 12 - Dateiname soll über argv vom Benutzer bestimmbar sein.
// 13 -   lohnt nicht in eigene Funktion umzubauen
// 14 -   lohnt nicht in eigene Funktion umzubauen
// 15 -   lohnt nicht in eigene Funktion umzubauen
// 16 - Stream IO für Text Ein- und Ausgaben
// 17 - adäquat eingebaute Datentypen: std::...
// 18 - min. 1x Typinferenz “auto” verwenden als retrun
// 19 - einhalten C++11 Variable still "int a{5};"
// 20 - Nutzen sie Referenzen bei Funktionsargumenten, wenn möglich!
// 21 - Nutzen von “const”, wann immer möglich!
// 22 - Deklarierung der öffentlichen Funktionen (d.h. die in main.cpp
//      aufgerufenen) in der Datei labor1.hpp.
using ll = long long;

using Alter = struct{
	ll jahre;
	ll tage;
	ll stunden;
};

// Aufgabe 8
using Person = struct{
	std::string vorname{""};
	std::string nachname{""};
	std::tm geburtsdatum{0};
	Alter alter{0,0,0};
};

static Person setGebDat(Person &p, int tag, int monat, int jahr);

// Aufgabe 13
static Person berechneAlter(Person &p);

static void alter2Textform(Person &p);

#endif //PIC23_LABOR1_HPP