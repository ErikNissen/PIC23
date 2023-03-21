

#ifndef PIC23_LABOR1_HPP
#define PIC23_LABOR1_HPP

int labor1(std::vector<std::string>& vecArgs);

int changeValueOfIntVector(std::vector<std::string>& vecArgs, int, int);
void aufgabe_1(std::vector<std::string>& vecArgs);
void aufgabe_2(std::vector<std::string>& vecArgs);
void aufgabe_3();
void aufgabe_4();
void aufgabe_5();
void aufgabe_6();
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
