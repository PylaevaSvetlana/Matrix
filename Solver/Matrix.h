#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Generator.h"

namespace miit::algebra
{
	template<typename T> class Matrix;
	/*
	* @brief Оператор "<<" для класса Matrix.
	*/
	template<typename T>
	std::ostream& operator<<(std::ostream& output, const Matrix<T>& matrix);
	/*
	* @brief Класс Matrix.
	*/
	template<typename T>
	class Matrix
	{
	private:
		/*
        * @brief Вектор Матрица.
	    */
		std::vector<std::vector<T>> matrix;
		/*
	    * @brief Строки.
	    */
		size_t rows;
		/*
		* @brief Столбцы.
		*/
		size_t columns;
	public:
		/**
		* @brief Конструктор.
		* @param rows количество строк.
		* @param cols количество столбцов.
		*/
		Matrix(size_t rows, size_t columns);
		/*
	    * @brief Консртуктор.
	    */
		Matrix() = default;
		/*
		* @brief Десртуктор.
		*/
		~Matrix() = default;
		/*
        * @brief Оператор копирования.
        */
		Matrix(const Matrix& other) = default;
		/*
		* @brief Оператор перемещения.
		*/
		Matrix(Matrix&& other) noexcept = default;
		/*
		* @brief Оператор присваивания копированием.
		*/
		Matrix& operator=(const Matrix& other) = default;
		/*
		* @brief Оператор присваивания перемещением.
		*/
		Matrix& operator=(Matrix&& other) noexcept = default;
		/*
		* @brief Оператор доступа к строке.
		* @param index индекс строки.
		* @return Ссылку на вектор строки матрицы.
		*/
		std::vector<T>& operator[](size_t index);
		/*
		* @brief Оператор доступа к строке.
		* @param index индекс строки
		* @return Ссылку на вектор строки матрицы.
		*/
		const std::vector<T>& operator[](size_t index) const;
		/*
		* @brief Метод получения колличества строк.
		* @return Колличество строк матрицы.
		*/
		size_t GetRows();
		/*
		* @brief Метод получения колличества столбцов.
		* @return Колличество столбцов матрицы.
		*/
		size_t GetColumns();
		/*
		* @brief Метод сериализации в строку ToString().
		* @return Возвращает строковое представление матрицы.
		*/
		std::string ToString() const;
		/*
		* @brief Метод заполения матрицы значениями.
		* @param generator генератор.
		*/
		void Fill(Generator& generator);
		/*
		* @brief Метод удаления столбца матрицы.
		* @param delete_column столбец, который нужно удалить.
		*/
		void DeleteColumn(size_t delete_column);
	};

	template<typename T>
	std::ostream& operator << (std::ostream& output, const Matrix<T>& matrix)
	{
		output << matrix.ToString();
		return output;
	}

	template<typename T>
	Matrix<T>::Matrix(size_t rows, size_t columns)
	{
		if (rows < 0 || columns < 0)
		{
			throw std::out_of_range("Матрица не существует");
		}
		this->rows = rows;
		this->columns = columns;
		this->matrix.assign(rows, std::vector<T>(columns));
	}

	

	template<typename T>
	std::vector<T>& Matrix<T>::operator[](size_t index)
	{
		if (index >= rows || index<0) 
		{
			throw std::out_of_range("Выход за границы допустимых значений");
		}
		return matrix[index];
	}

	template<typename T>
	const std::vector<T>& Matrix<T>::operator[](size_t index) const
	{
		if (index >= rows || index < 0)
		{
			throw std::out_of_range("Выход за границы допустимых значений");
		}
		return matrix[index];
	}

	template<typename T>
	size_t Matrix<T>::GetRows()
	{
		return rows;
	}

	template<typename T>
	size_t Matrix<T>::GetColumns()
	{
		return columns;
	}

	template<typename T>
	std::string Matrix<T>::ToString() const
	{
		std::stringstream buffer{};
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				buffer << matrix[i][j] << " ";
			}
			buffer << "\n";
		}
		return buffer.str();
	}

	template<typename T>
	void Matrix<T>::Fill(Generator& generator)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				matrix[i][j] = generator.generate();
			}
		}
	}

	template<typename T>
	void Matrix<T>::DeleteColumn(size_t delete_column)
	{
		if (delete_column >= columns)
		{
			throw std::out_of_range("Выход за границы допустимых значений");
		}
		for (size_t i = 0; i < rows; ++i)
		{
			matrix[i].erase(matrix[i].begin() + delete_column);
		}
		--columns;
	}
}