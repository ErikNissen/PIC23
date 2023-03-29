#ifndef PIC23_DISHFACTORY_HPP
#define PIC23_DISHFACTORY_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../../globals.hpp"
#include "AbstractDish.hpp"
#include "PizzaMargherita.hpp"
#include "VegetableSoup.hpp"

namespace dishlib {
// Aufgabe 6
	class DishFactory{
	public:
		enum class DishType{
			VegetableSoup,
			PizzaMargherita
		};
		std::unique_ptr<AbstractDish> CreateDish(const DishType& dishType);
	};

} // dishlib

#endif //PIC23_DISHFACTORY_HPP
