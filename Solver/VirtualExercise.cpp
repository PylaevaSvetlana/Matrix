#include "VirtualExercise.h"

miit::algebra::VirtualExercise::VirtualExercise(size_t rows, size_t columns, Generator& generator)
{
	this->matrix = Matrix<int>{ rows,columns };
	matrix.Fill(generator);
}

void miit::algebra::VirtualExercise::TaskOutput()
{
	task1();
	std::cout << matrix << "\n";
	task2();
	std::cout << matrix;
}

miit::algebra::Matrix<int> miit::algebra::VirtualExercise::GetMatrix()
{
	return matrix;
}
