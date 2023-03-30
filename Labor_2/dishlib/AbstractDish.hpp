#ifndef PIC23_ABSTRACTDISH_HPP
#define PIC23_ABSTRACTDISH_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../../globals.hpp"

using zutatenliste = std::vector<std::tuple<std::string, int>>;
using ull = unsigned long long;

namespace dishlib {
// AUfgabe 4
	class AbstractDish{
	public:
		virtual void Prepare(std::vector<std::tuple<std::string, unsigned int>> &zutaten,
		                     std::vector<std::string> &schritte) = 0; // "=
							 // 0" gibt an das es pur-virtuall ist!

		const std::string GetDishName();

		void AddStep(std::string &step);

		const zutatenliste GetIngredients();

		const ull GetNumberIngredients();

		AbstractDish() = delete;

		explicit AbstractDish(std::string &_dishName);
		virtual ~AbstractDish() = default; // Virtuel da...

	protected:
		void AddIngredients(const std::string &zutat, const unsigned int &anzahl);

		std::vector<std::tuple<int, std::string>> steps;
		std::string dishName;
	private:
		zutatenliste vIngredients;
	};

} // dishlib

#endif //PIC23_ABSTRACTDISH_HPP
