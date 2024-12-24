#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
	/*
	* @brief  ласс RandomGenerator, наследуемый от Generator.
	*/
	class RandomGenerator : public Generator
	{
	private:
		std::uniform_int_distribution<int> distribution;
		std::mt19937 generator;

	public:
		/*
		* @brief  онструктор.
		* @param min минимальное значение.
		* @param max максимальное значение.
		*/
		RandomGenerator(const int min, const int max);
		/*
		*@brief ћетод, возвращающий случайное число.
		*@return ¬озвращает случайное число.
		*/
		int generate() override;
	};
}