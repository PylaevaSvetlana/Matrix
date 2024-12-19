#include "Exercise.h"

using namespace miit::algebra;

miit::algebra::Exercise::Exercise(Matrix<int> matrix): matrix{ matrix } {}

Matrix<int> miit::algebra::Exercise::task1()
{
	Matrix<int> temp(matrix);
	int max = temp[0][0];
	for (int i = 0; i < temp.GetRows(); i++)
	{
		for (int j = 0; j < temp.GetColumns(); j++)
		{
			if (fabs(max) < fabs(temp[i][j]))
			{
				max = temp[i][j];
			}
		}
	}
	for (int i = 0; i < temp.GetRows(); i++)
	{
		for (int j = 0; j < temp.GetColumns(); j++)
		{
			if ((i + j) % 2 == 0)
			{
				temp[i][j] = max;
			}
		}
	}
	return temp;
}