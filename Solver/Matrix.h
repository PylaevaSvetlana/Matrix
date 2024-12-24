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

	template<typename T>
	std::ostream& operator<<(std::ostream& output, const Matrix<T>& matrix);

	template<typename T>
	class Matrix
	{
	private:
		std::vector<std::vector<T>> matrix;
		size_t rows;
		size_t columns;
	public:
		Matrix(size_t rows, size_t columns);
		Matrix() = default;
		~Matrix() = default;
		Matrix(const Matrix& other) = default;
		Matrix(Matrix&& other) noexcept = default;
		Matrix& operator=(const Matrix& other) = default;
		Matrix& operator=(Matrix&& other) noexcept = default;
		std::vector<T>& operator[](size_t index);
		const std::vector<T>& operator[](size_t index) const;
		size_t GetRows();
		size_t GetColumns();
		std::string ToString() const;
		void Fill(Generator& generator);
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
		if (delete_column < 0 || delete_column >= columns)
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