#include <iostream>
#include <vector>
#include <array>
#include "lap2a.hpp"


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
        std::cout << "\nTeil 6 : " << std::endl;
		A a8{11};
        A a9{std::move(a8)};
	}

	// Fragen beantworten
    std::cout << "\nFragen beantworten: \n" << std::endl;
/*
	- Warum wird bei “A a3{A{4}};“ in Teil A.2 kein Kopierkonstruktor aufgerufen?
	- Warum wird in Teil A.3 “class A destructor: nullptr” ausgegeben?
	- Warum wird in Teil A.5 “class A destructor: 9” ausgegeben?
	- Inwiefern verhält sich Teil A.6 anders als Teil A.2?
*/
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
A::A(A const &number) : _nptr(new int(*number._nptr)), _aptr{nullptr} {
    for (auto i = 0; i < 5; i++) {
        _aptr[i] = new int(*number._aptr[i]);
    }
    std::cout << "class A copy constructor: " << *_nptr << std::endl;
}

// Move
A::A(A &&nummer) {
    std::swap(nummer._nptr, _nptr);
    std::swap(nummer._aptr, _aptr);
    std::cout << "class A move constructor: " << *_nptr << std::endl;
}

// Copy assignment
A& A::operator=(A const &rhs){ // rhs = right-hand side
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