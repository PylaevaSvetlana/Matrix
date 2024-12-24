#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
	/*
	* @brief Класс IStreamGenerator, наследуемый от Generator.
	*/
	class IStreamGenerator : public Generator
	{
	private:
		std::istream& in;

	public:
		/*
		* @brief Конструктор.
		* @param in поток ввода.
		*/
		IStreamGenerator(std::istream& in = std::cin);
		/*
	   * @brief Метод генерации значения с клавиатуры.
	   * @return Введеное значение.
	   */
		int generate() override;
	};
}
