#include <iostream>
#include <vector>
#include <array>

#include "labor1.hpp"

using namespace std;

int labor1(std::vector<std::string>& vecArgs){

    // Aufgabe 1 Labor 1: alle argv Elemente im Vecotr werden mit cout ausgegeben.
    cout << "Die Elemente im Vector sind: ";
    for (auto elem: vecArgs){
        cout << elem << ", ";
    }
    cout << "" << endl;

    // Aufgabe 2 Labor 1: Umwandlung von argv - string zu Double
    double xyz;
    for (auto elem: vecArgs){
        // chek if argv is a number to convert
        try{
            xyz = stod(elem);
            cout << "In den argv ist mindestens eine Kommazahl enthalten gewesen, die erste Kommazahl ist: " << xyz << endl;
            break;
        } catch (const exception e){
            // Nothing
        }
    }

    return 0;
}