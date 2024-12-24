#pragma once
#include "Matrix.h"
#include "VirtualExercise.h"

namespace miit::algebra 
{
	/*
	* @brief Класс Exercise наследуемый от VirtualExercise.
	*/
	class Exercise :public miit::algebra::VirtualExercise
	{
	public:
		/**
		* @brief Конструктор.
		* @param rows количество строк.
		* @param cols количество столбцов.
		* @param generator генератор.
		*/
		Exercise(size_t rows, size_t columns, Generator& generator);
		/*
	    * @brief Первое задание.
	    */
		void task1() override;
		/*
		* @brief Второе задание.
		*/
		void task2() override;
	};
}