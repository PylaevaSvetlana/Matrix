#pragma once
#include"Matrix.h"

namespace miit::algebra
{
	/*
	* @brief Класс VirtualExercise вирутальный.
	*/
	class VirtualExercise
	{
	protected:
		/*
	    * @brief Матрица целых чисел.
	    */
		Matrix<int> matrix;
		/*
		* @brief Первое задание виртуальное.
		*/
		virtual void task1() = 0;
		/*
		* @brief Второе задание виртуальное.
		*/
		virtual void task2() = 0;

	public:
		/**
		* @brief Конструктор.
		* @param rows количество строк.
		* @param cols количество столбцов.
		* @param generator генератор.
		*/
		explicit VirtualExercise(size_t rows, size_t columns, Generator& generator);
		/**
		* @brief Деструктор.
		*/
		virtual ~VirtualExercise() = default;
		/**
		* @brief Метод выполнения заданий.
		*/
		void TaskOutput();
		/**
		* @brief Метод получения матрицы.
		* @return Возвращает матрицу.
		*/
		Matrix<int> GetMatrix();
	};
}



