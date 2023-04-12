#ifndef PIC23_DISHFACTORY_HPP
#define PIC23_DISHFACTORY_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <conio.h>
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
			PizzaMargherita,

			// Für Iterationen
			count,
			begin = 0,
			end = count
		};
		static std::unique_ptr<AbstractDish> CreateDish(const DishType& dishType);
		static void ListDishes();
		DishFactory() = delete;
		~DishFactory() = delete;
	};
} // dishlib

#endif //PIC23_DISHFACTORY_HPP
