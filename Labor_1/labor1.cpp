#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include "labor1.hpp"


// TODO: Fixen
Alter berechneAlter(const Geburtsdatum &gebdat) {
    Alter alter;

    time_t jetzt{time(0)};
    tm *ltm{localtime(&jetzt)};

    int aktuellesJahr{1900 + ltm->tm_year};
    int aktuellerMonat{1 + ltm->tm_mon};
    int aktuellerTag{ltm->tm_mday};

    alter.jahre = aktuellesJahr - gebdat.jahr;

    if (aktuellerMonat < gebdat.monat || (aktuellerMonat == gebdat.monat &&
                                          aktuellerTag < gebdat.tag)) {
        alter.jahre--;
    }

    int tagImJahr = 365 * alter.jahre / 4 - alter.jahre / 100 + alter.jahre
                                                                / 400;

    std::array<int, 12> monate{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (aktuellesJahr % 4 == 0 && (aktuellesJahr % 100 != 0 || aktuellesJahr
                                                               % 400 == 0)) {
        monate[1] = 29;
    }

    for (auto i{gebdat.monat - 1}; i < aktuellerMonat - 1; i++) {
        tagImJahr += monate[i];
    }

    tagImJahr += aktuellerTag - gebdat.tag;

    alter.tage = tagImJahr;
    alter.stunden = alter.tage * 24;

    return alter;
}

int fibonacci(int n) { // Aufgabe 3
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int labor1(std::vector<std::string> &vecArgs) {
    aufgabe_1(vecArgs);
    double zahl, sinus;
    int umgewandelt, counter{0};
    for (int i = 0; i < vecArgs.size(); i++) {
        // mit "." wird try block nicht aufgerufen!
        if (vecArgs[i].find_first_of(",") != std::string::npos) {
            try {
                // Aufgabe 2 - String to double
                std::cout << "\nAufgabe 2\n" << std::endl;
                // Ersetze "," durch "." damit die Kommazahl richtig ausgegeben wird - ohne diesen Schritt gehen die nachkommastellen verloren!
                std::replace(vecArgs[i].begin(), vecArgs[i].end(), ',', '.');
                zahl = stod(vecArgs[i]); // gibt int aus??
                std::cout << zahl << " (double) ";

                std::cout << "\nAufgabe 4\n" << std::endl;
                // Aufgabe 4
                sinus = sin(zahl);

                // Aufgabe 5
                std::cout << "\nAufgabe 5\n" << std::endl;
                std::cout << "Wandle zahl von Aufgabe 2 um in einen Integer, zahl lautet aktuell: " << zahl << std::endl;
                umgewandelt = static_cast<int>(zahl);
                std::cout << "zahl wurde erfolgreich umgewandelt in: " << umgewandelt << std::endl;

                // Aufgabe 6
                std::cout << "\nAufgabe 6\n" << std::endl;
                changeValueOfIntVector(vecArgs, umgewandelt, counter);

                // Aufgabe 7
                std::cout << "\nAufgabe 7\n" << std::endl;
                std::cout << std::hex << umgewandelt << " (HEX), " << std::dec;
            } catch (const std::exception e) {
                std::cout << vecArgs[i] << ", ";
            }
        } else {
            try {
                // Aufgabe 3
                std::cout << "\nAufgabe 3\n" << std::endl;
                int x{stoi(vecArgs[i])};
                std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
                          " ist " << fibonacci(x) << std::endl; // Hier muss was überarbeitet werden!
            } catch (const std::exception e) {
                std::cout << vecArgs[i] << ", ";
            }
        }
    }


    aufgabe_9();

    return 0;
}

void aufgabe_1(std::vector<std::string> &vecArgs) {
    // Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout ausgegeben.
    std::cout << "Aufgabe 1:\nDie Elemente im Vector sind: ";
    for (auto i: vecArgs) { // check if this is correct
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void aufgabe_2(std::vector<std::string> &vecArgs) {

}

// Aufgabe 6 try - Rechung funktioniert und ergebnis wird in Vector
// reingepackt, aber nicht an richtige position
    int changeValueOfIntVector(std::vector<std::string> &vecArgs, int umgewandelt,
                               int counter) {
        umgewandelt += 42;
        std::cout << " += 42 = " << umgewandelt << std::endl;
        std::cout << "counter ist auf: " << counter << std::endl;
        vecArgs[counter] = std::to_string(umgewandelt);
        return 0;
    }

    void aufgabe_9() {

        // Aufgabe 9
        std::vector<Person> personen{
                Person{"Max", "Musterman",
                       Geburtsdatum{1, 1, 1901},
                       berechneAlter(Geburtsdatum{1, 1, 1901})}
        };

        for (auto p: personen) {
            std::cout << "Person" << std::endl;
            std::cout << p.alter.jahre << std::endl;
            std::cout << p.alter.tage << std::endl;
            std::cout << p.alter.stunden << std::endl;
        }
    }