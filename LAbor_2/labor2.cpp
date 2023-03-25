#include <iostream>

#include "labor2.hpp"
#include "Teil_A/lap2a.hpp"
#include "Teil_B/lab2b.hpp"

int lab2Main(){
	static int choice{-1};

	while (0 != choice ){
		std::cout << "Welcher Teil der Labor Aufgaben sollen angezeigt werden?\n"
		          << "0. Exit\n"
		          << "1. Teil A\n"
		          << "2. Teil B\n"
		          << "Eingabe: ";
		std::cin >> std::ws >> choice;

		switch (choice) {
			case 0:
				std::cout << "Beende."<<std::endl; break;
			case 1: // Teil A
				lab2AMain();
				break;
			case 2: // Teil B
				std::cout << "Hier Gibt es noch Nichts!" << std::endl;
				break;
			default:
				std::cout << "Eingabe konnte nicht verstanden werden, bitte "
				             "versuchen Sie es erneut." << std::endl;
				break;
		}
	}
    return 0;
}