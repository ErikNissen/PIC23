#ifndef PIC23_A_HPP
#define PIC23_A_HPP

#pragma once

void a_1();
void a_2();
void a_3();
void a_4();
void a_5();
void a_6();
void a_Fragen();
void trenstriche();


int lab2AMain();

class A {
public:
	// Konstruktor
	explicit A(int const); // Teil 1

	// Copy
	A(A const &); // Teil 2

	// Copy assignment
	A& operator=(A const &); // Teil 4

	// Move
	A(A &&); // Teil 3

	// Move assignment
	A& operator=(A &&); // Teil 5

	// Destruktor
	~A(); // Teil 1
private:
	int* _nptr; // nullprt int
	int* _aptr; // nullptr int array
};


#endif //PIC23_A_HPP

/*
 // Konstruktor
A::A(const int nummer) : _nptr(new int), _aptr{new int[5]}{
	// Nach ":" ist eine Initalisierungsliste
	*_nptr = nummer;
	for (auto i{0}; i < 5; i++) {
		_aptr[i] = 42;
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
	delete [] _aptr;
}

// Copy
A::A(A const &number) : _nptr(new int(*number._nptr)), _aptr{new int[5]} {
	for (auto i{0}; i < 5; i++) {
		_aptr[i] = number._aptr[i];
	}
	std::cout << "class A copy constructor: " << *_nptr << std::endl;
}

// Move
A::A(A &&nummer) : _nptr(nummer._nptr) {
	std::swap(nummer._nptr, _nptr);
	std::swap(nummer._aptr, _aptr);
	std::cout << "class A move constructor: " << *_nptr << std::endl;
}

// Copy assignment
A &A::operator=(const A &rhs) { // rhs = right-hand side
	if (this != &rhs) {
		*_nptr = *rhs._nptr; // flache Kopie
		for (auto i{0}; i < 5; i++) { // deep copy
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

 */