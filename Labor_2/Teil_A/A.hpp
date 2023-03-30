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
