#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ctime>
#include "labor1.hpp"

// Global Variable
int placeholder;

int fibonacci(int n) { // Aufgabe 3
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int labor1(std::vector<std::string> &vecArgs) {
    aufgabe_1(vecArgs);
    int umgewandelt;
    for (int i = 0; i < vecArgs.size(); i++) {
        // Es ist zu beachten, dass als "Programm argument" Kommazahlen mit einem "." versehen werden
        if (vecArgs[i].find_first_of(".") != std::string::npos) {
            try {
                aufgabe_2(vecArgs[i]);

                aufgabe_6(vecArgs, i);


                // Aufgabe 7
                std::cout << "\nAufgabe 7\n" << std::endl;
                std::cout << std::hex << umgewandelt << " (HEX), " << std::dec;
            } catch (const std::exception e) {
                std::cout << vecArgs[i] << ", ";
            }
        } else {
//            try {
//                // Aufgabe 3
//                std::cout << "\nAufgabe 3\n" << std::endl;
//                int x{stoi(vecArgs[i])};
//                std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
//                          " ist " << fibonacci(x) << std::endl; // Hier muss was überarbeitet werden!
//            } catch (const std::exception e) {
//                std::cout << vecArgs[i] << ", ";
//            }
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

// Aufgabe 2 - String to double
void aufgabe_2(const std::string &vec) {
    std::cout << "\nAufgabe 2" << std::endl;
    double zahl = stod(vec);
    std::cout << zahl << " (double) " << std::endl;
    aufgabe_4(zahl);
    aufgabe_5(zahl);
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

    // übergabe an Global Var für aufgabe_6
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
        std::cout << "Vector Erfolgreich bearbeiten!" << std::endl;
    }else{
        std::cout << "Etwas ist schiefgelaufen!" << std::endl;
    }
}

void aufgabe_9() {
    std::vector<Person> personen;
    Person p1{
            "Hans",
            "Wurst",
            std::tm{0},
            Alter{0}
    };
    p1.setGebDat(1,1,2000);

    // Aufgabe 13
    p1.berechneAlter();
    personen.emplace_back(p1);

    // Aufgabe 15
    for (auto p: personen) {
        std::cout << "Person" << std::endl;
        // Aufgabe 14 / 16 / 17 / 18
        p.alter2Textform();
    }
}