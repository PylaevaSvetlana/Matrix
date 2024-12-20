#include "VirtualExercise.h"

miit::algebra::VirtualExercise::VirtualExercise(int rows, int columns, Generator& generator)
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
