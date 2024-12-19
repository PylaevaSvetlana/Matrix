#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"

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
		int rows;
		int columns;
	public:
		Matrix(int rows, int columns);
		~Matrix() = default;
		Matrix(const Matrix& other);
		Matrix(Matrix&& other) noexcept;
		Matrix& operator=(const Matrix& other);
		Matrix& operator=(Matrix&& other) noexcept;
		std::vector<T> operator[](int index);
		const std::vector<T> operator[](int index) const;
		int GetRows();
		int GetColumns();
		std::string ToString() const;
		void FillRandom(int min, int max);
		void FillIStream(std::istream& in);
	};

	template<typename T>
	std::ostream& operator << (std::ostream& output, const Matrix<T>& matrix)
	{
		output << matrix.ToString();
		return output;
	}

	template<typename T>
	Matrix<T>::Matrix(int rows, int columns) 
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
	Matrix<T>::Matrix(const Matrix& other) :matrix{ other.matrix }, rows{ other.rows }, columns{ other.columns } {}

	template<typename T>
	Matrix<T>::Matrix(Matrix&& other) noexcept: matrix { std::move(other.matrix) }, rows{ std::move(other.rows) }, columns{ std::move(other.columns) } {}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix& other)
	{
		if (this != &other)
		{
		this->rows = other.rows;
		this->columns = other.columns;
		this->matrix = other.matrix;
		}
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
	{
		if (this != &other)
		{
		this->rows = std::move(other.rows);
		this->columns = std::move(other.columns);
		this->matrix = std::move(other.matrix);
		}
		return *this;
	}

	template<typename T>
	std::vector<T> Matrix<T>::operator[](int index)
	{
		if (index >= rows || index<0) 
		{
			throw std::out_of_range("Выход за границы допустимых значений");
		}
		return matrix[index];
	}

	template<typename T>
	const std::vector<T> Matrix<T>::operator[](int index) const
	{
		if (index >= rows || index < 0)
		{
			throw std::out_of_range("Выход за границы допустимых значений");
		}
		return matrix[index];
	}

	template<typename T>
	int Matrix<T>::GetRows()
	{
		return rows;
	}

	template<typename T>
	inline int Matrix<T>::GetColumns()
	{
		return columns;
	}

	template<typename T>
	inline std::string Matrix<T>::ToString() const
	{
		std::stringstream buffer{};
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				buffer << matrix[i][j] << " ";
			}
			buffer << "\n";
		}
		return buffer.str();
	}

	template<typename T>
	void Matrix<T>::FillRandom(int min, int max)
	{
		RandomGenerator generator(min, max);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = generator.generate();
			}
		}
	}
	
	template<typename T>
	void Matrix<T>::FillIStream(std::istream& in)
	{
		IStreamGenerator generator(in);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = generator.generate();
			}
		}
	}
}