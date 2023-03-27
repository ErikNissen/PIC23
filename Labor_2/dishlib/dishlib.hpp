#ifndef PIC23_DISHLIB_HPP
#define PIC23_DISHLIB_HPP

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../../globals.hpp"

using zutatenliste = std::vector<std::tuple<std::string, int>>;

// Aufgabe 3
namespace dishlib{

	// Aufgabe 4
	class AbstractDish{
	public:
		virtual void Prepare();

		void AddStep(const std::string &step);

		std::string GetDishName();

		zutatenliste GetIngredients();

		int GetNumberIngredients();

		AbstractDish() = delete;

		explicit AbstractDish(std::string &_dishName);

		virtual ~AbstractDish() = default;

	protected:
		void AddIngredients(const std::string &zutat, const int &anzahl);

		std::vector<std::tuple<int, std::string>> steps;
	private:
		zutatenliste vIngredients;
		std::string dishName;
	};

	// Aufgabe 5
	class VegetableSoup : AbstractDish{
	public:
		void Prepare(std::vector<std::tuple<std::string, int>> &zutaten,
					 std::vector<std::string> &schritte);

		VegetableSoup() = delete;
	};

	// Aufgabe 5
	class PizzaMargherita : AbstractDish{
	public:
		void Prepare(std::vector<std::tuple<std::string, int>> &zutaten,
		             std::vector<std::string> &schritte);

		PizzaMargherita() = delete;
	};

	// Aufgabe 6
	class DishFactory{
	public:
		enum class DishType{

		};
		std::unique_ptr<AbstractDish> CreateDish(DishType dishType);
	};
}

#endif //PIC23_DISHLIB_HPP
