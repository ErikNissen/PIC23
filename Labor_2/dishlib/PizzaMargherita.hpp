#ifndef PIC23_PIZZAMARGHERITA_HPP
#define PIC23_PIZZAMARGHERITA_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../../globals.hpp"
#include "AbstractDish.hpp"

namespace dishlib {
// Aufgabe 5
	class PizzaMargherita : public AbstractDish{
	public:
		void Prepare(std::vector<std::tuple<std::string, unsigned int>> &zutaten,
		             std::vector<std::string> &schritte);

		PizzaMargherita() = delete;

		explicit PizzaMargherita(std::string _dishName);
	};

} // dishlib

#endif //PIC23_PIZZAMARGHERITA_HPP
