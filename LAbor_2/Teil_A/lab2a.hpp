#ifndef PIC23_LAB2A_HPP
#define PIC23_LAB2A_HPP

int lab2AMain();

class A {
public:
	// Konstruktor
	A(int const);

	// Destruktor
	~A();
private:
	int* _nptr { nullptr }; // nullprt int
	int* _aptr[5] { nullptr }; // nullptr int array
};


#endif //PIC23_LAB2A_HPP
