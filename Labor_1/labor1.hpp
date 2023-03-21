

#ifndef PIC23_LABOR1_HPP
#define PIC23_LABOR1_HPP
#include <chrono>
#include <iostream>
int labor1(std::vector<std::string>& vecArgs);

void aufgabe_1(std::vector<std::string>& vecArgs);
void aufgabe_2(const std::string &vec);
void aufgabe_3();
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

    void setGebDat(const int tag, const int monat, const int jahr){
        geburtsdatum.tm_mday = tag;
        geburtsdatum.tm_mon = monat - 1;
        geburtsdatum.tm_year = jahr - 1900;
    }

    // Aufgabe 13
    void berechneAlter(){
        auto geburtszeitpunkt{std::chrono::system_clock::from_time_t(std::mktime(&geburtsdatum))};
        auto jetzt{std::chrono::system_clock::now()};
        auto age{std::chrono::duration_cast<std::chrono::hours>(jetzt -
                                                                geburtszeitpunkt).count()};

        alter.jahre = age / 8760;
        alter.tage = (age % 8760) / 24;
        alter.stunden = age % 24;
    }

    void alter2Textform(){
        std::string text;
        const std::array<std::string, 10> hunderte{
                "hundert", "Ein", "Zwei", "Drei", "Vier", "Fünf",
                "Sechs", "Sieben", "Acht", "Neun"
        };
        const std::array<std::string, 10> zehner{
                "zig", "Zehn", "Zwan", "Dreißig", "Vier",
                "Fünf", "Sech", "Sieb", "Acht", "Neun"
        };
        const std::array<std::string, 10> einer{
                "Null", "Eins", "Zwei", "Drei", "Vier",
                "Fünf", "Sechs", "Sieben", "Acht", "Neun"
        };
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
                    for(const auto &ch : zehner[1])
                        text += std::tolower(static_cast<int>(ch));
            else
                text += "und";
        for(const auto &ch : zehner[z])
            text += std::tolower(static_cast<int>(ch));
        text += zehner[0];


        std::cout << "Person ist " << text << " Jahre alt." << std::endl;
    }
};

#endif //PIC23_LABOR1_HPP

/*
    double zahl, sinus;
    int umgewandelt, counter{0};

    for (auto elem: vecArgs) {
        if (elem.find_first_of(".") != std::string::npos) {
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
                std::cout << std::hex << umgewandelt << " (HEX), " << std::dec;
            } catch (const std::exception e) {
                std::cout << elem << ", ";
            }
        } else {
            try {
                // Aufgabe 3
                int x{stoi(elem)};
                std::cout << std::endl << "Die Fibonacci-Zahl von " << x <<
                          " ist " << fibonacci(x) << std::endl;
            } catch (const std::exception e) {
                std::cout << elem << ", ";
            }
        }
        counter++;
    }
    std::cout << "" << std::endl;

    for (auto i: vecArgs) { // check if this is correct
        std::cout << i << ", ";
    }
    std::cout << std::endl;
 */
