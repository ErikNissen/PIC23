#ifndef PIC23_LAP2A_HPP
#define PIC23_LAP2A_HPP

#pragma once

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
	int* _nptr { nullptr }; // nullprt int
	int* _aptr[5] { nullptr }; // nullptr int array
//	int* _aptr { nullptr }; // nullptr int array
};


#endif //PIC23_LAP2A_HPP
