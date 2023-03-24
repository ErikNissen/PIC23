#include <iostream>
#include <vector>
#include <array>
#include "lab2a.hpp"

int lab2AMain(){
// Teil 1
	{
		A a1{3};
	}
// Teil 2
	{
		A a1{3};
		A a2{a1};
		A a3{A{4}};
	}
// Teil 3
	{
		std::vector<A> v;
		v.emplace_back(A{5});
	}
// Teil 4
	{
		A a5{5};
		A a6{8};
		a6 = a5;
	}
// Teil 5
	{
		A a7(9);
		a7 = A(10);
	}
// Teil 6
	{
		A a8{11};
//		A a9{move(a8)};
	}

	// Fragen beantworten

/*
	- Warum wird bei “A a3{A{4}};“ in Teil A.2 kein Kopierkonstruktor aufgerufen?
	- Warum wird in Teil A.3 “class A destructor: nullptr” ausgegeben?
	- Warum wird in Teil A.5 “class A destructor: 9” ausgegeben?
	- Inwiefern verhält sich Teil A.6 anders als Teil A.2?
*/
}

// Konstruktor
A::A(const int nummer) : _nptr(new int), _aptr{new int[5]{}}{
	// Nach ":" ist eine Initalisierungsliste
	*_nptr = nummer;
	for (auto& i : _aptr) {
		*i = 42;
	}
	std::cout << "class A constructor: " << *_nptr << std::endl;
}

// Destruktor
A::~A() {
	std::cout << "class A destructor: " << *_nptr << std::endl;
	// Heap frei machen von den beiden Pointer
	delete _nptr;
	for (auto& i : _aptr) {
		delete i;
	}
}
