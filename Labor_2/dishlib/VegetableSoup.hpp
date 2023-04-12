#ifndef PIC23_VEGETABLESOUP_HPP
#define PIC23_VEGETABLESOUP_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../../globals.hpp"
#include "AbstractDish.hpp"

namespace dishlib {
// Aufgabe 5
	class VegetableSoup : public AbstractDish{
	public:
		void Prepare(std::vector<std::tuple<std::string, unsigned int>> &zutaten,
		             std::vector<std::string> &schritte);

		VegetableSoup() = delete; // del def. konstr.

		VegetableSoup(std::string);
	};

} // dishlib

#endif //PIC23_VEGETABLESOUP_HPP
