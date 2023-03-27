#include <iostream>
#include <vector>
#include <array>
#include "lap2a.hpp"
#include "../globals.hpp"

int lab2AMain(){
// Teil 1
	{
		std::cout << "\nTeil 1 : " << std::endl;
		A a1{3};
	}
// Teil 2
	{
		std::cout << "\nTeil 2 : " << std::endl;
		A a1{3};
		A a2{a1};
		A a3{A{4}};
	}
// Teil 3
	{
		std::cout << "\nTeil 3 : " << std::endl;
		std::vector<A> v;
		v.emplace_back(A{5});
	}
// Teil 4
	{
		std::cout << "\nTeil 4 : " << std::endl;
		A a5{7};
		A a6{8};
		a6 = a5;
	}
// Teil 5
	{
		std::cout << "\nTeil 5 : " << std::endl;
		A a7(9);
		a7 = A(10);
	}
// Teil 6
	{
		using namespace std;
		std::cout << "\nTeil 6 : " << std::endl;
		A a8{11};
		A a9{move(a8)};
	}
// Fragen beantworten
	{
		std::cout << "\nFragen beantworten: " << std::endl;

		std::cout << "Warum wird bei \"A a3{A{4}};\" in Teil A.2 kein Kopierkonstruktor aufgerufen?" << std::endl;
		std::cout << "Wir rufen in a3 nicht einen wert sondern eine Klasse auf, die ein Parameter verwendet, "
		          << "daher wird der Kopierkonstruktor auch nicht aufgerufen.\n"
		          << std::endl; // Antwort

		std::cout << "Warum wird in Teil A.3 \"class A destructor: nullptr\" ausgegeben?" << std::endl;
		std::cout << "Durch swap wird der Wert von _nptr auf null gesetzt, da dies der Wert von move._nptr ist.\n"
		          << std::endl; // Antwort

		std::cout << "Warum wird in Teil A.5 \"class A destructor: 9\" ausgegeben?" << std::endl;
		std::cout << "Es wird 9 ausgegeben, da beide Werte mit \"swap\" vertauscht werden.\n"
		          << std::endl; // Antwort

		std::cout << "Inwiefern verh"<< ae <<"lt sich Teil A.6 anders als Teil A.2?" << std::endl;
		std::cout << "In A.6 wird f" << ue << "r a9 der wert \"move(a8)\" zugewiesen, da es sich um einen move handelt, \nwerden die werte mit einander vertauscht. \n"
		          << "In A.2 wird f" << ue << "r a3 der wert \"A{4}\" zugewiesen, es wird also die Klasse Aufgerufen mit dem Wert 4 \nals Parameter und dieser wird dann a3 zugewiesen."
		          << std::endl; // Antwort
	}
	return 0;
}

// Konstruktor
A::A(const int nummer) : _nptr(new int), _aptr{nullptr}{ // _aptr{new int[5]{}
	// Nach ":" ist eine Initalisierungsliste
	*_nptr = nummer;
	for (auto i = 0; i < 5; i++) {
		_aptr[i] = new int{42};
	}
	std::cout << "class A constructor: " << *_nptr << std::endl;
}

// Destruktor
A::~A() {
	if (nullptr == _nptr) {
		std::cout << "class A destructor: nullptr" << std::endl;
	}
	if (nullptr != _nptr) {
		std::cout << "class A destructor: " << *_nptr << std::endl;
	}

	// clear heap
	delete _nptr;
	for (auto i = 0; i < 5; i++) {
		delete _aptr[i];
	}

}

// Copy
A::A(const A &nummer) : _nptr(new int(*nummer._nptr)), _aptr{nullptr} {
	for (auto i = 0; i < 5; i++) {
		_aptr[i] = new int(*nummer._aptr[i]);
	}
	std::cout << "class A copy constructor: " << *_nptr << std::endl;
}

// Move
A::A(A &&nummer) : _nptr(new int), _aptr{nullptr}  {
	std::swap(nummer._nptr, _nptr);
	std::swap(nummer._aptr, _aptr);
	std::cout << "class A move constructor: " << *_nptr << std::endl;
}

// Copy assignment
A &A::operator=(const A &rhs) { // rhs = right-hand side
	if (this != &rhs) {
		*_nptr = *rhs._nptr; // flache Kopie
		for (int i = 0; i < 5; i++) { // deep copy
			_aptr[i] = rhs._aptr[i];
		}
	}
	std::cout << "class A copy assignment operator: " << *rhs._nptr << std::endl;
	return *this;
}

// Move assignment
A &A::operator=(A &&nummer) {
	std::swap(nummer._nptr, _nptr);
	std::swap(nummer._aptr, _aptr);
	std::cout << "class A move assignment operator: " << *_nptr << std::endl;
}
