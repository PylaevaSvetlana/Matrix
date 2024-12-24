#include "Exercise.h"

using namespace miit::algebra;

miit::algebra::Exercise::Exercise(size_t rows, size_t columns, Generator& generator):VirtualExercise{ rows,columns ,generator } {}

void miit::algebra::Exercise::task1()
{
	int max = matrix[0][0];
	for (size_t i = 0; i < matrix.GetRows(); i++)
	{
		for (size_t j = 0; j < matrix.GetColumns(); j++)
		{
			if (fabs(max) < fabs(matrix[i][j]))
			{
				max = matrix[i][j];
			}
		}
	}
	for (size_t i = 0; i < matrix.GetRows(); i++)
	{
		for (size_t j = 0; j < matrix.GetColumns(); j++)
		{
			if ((i + j) % 2 == 0)
			{
				matrix[i][j] = max;
			}
		}
	}
}

void miit::algebra::Exercise::task2() 
{
	for (size_t j = matrix.GetColumns(); j > 0; --j)
	{
		if ((matrix[0][j-1]) % 2 == 0)
		{
			matrix.DeleteColumn(j-1);
		}
	}
}