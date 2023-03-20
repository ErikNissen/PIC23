#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "Labor_1/labor1.hpp"

using namespace std;

int main(int argc, char *argv[]){

    // Aufgabe 1 Labor 1: Vektor bekommt alle argv Elemente
    vector<string> vecArgs;

    for(int i{1}; i<argc; i++)
    {
        vecArgs.emplace_back( argv[ i ] );
    }

    // Vector wird übergeben an die Function labor1 in labor1.cpp
    labor1(vecArgs);

//    cout << "Die Elemente im Vector sind: ";
//    for (auto elem: vecArgs){
//            cout << elem << ", ";
//    }
//    cout << "" << endl;
//
//// Aufgabe 2 Labor 1: Umwandlung von argv - string zu Double
//    double xyz;
//    for (auto elem: vecArgs){
//        // chek if argv is a number to convert
//
//    }

    return 0;
}