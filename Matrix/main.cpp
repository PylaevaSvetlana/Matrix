#include <iostream>
#include "..\Solver\Matrix.h"
#include "..\Solver\Exercise.h"

using namespace miit::algebra;
int main()
{
	Matrix<int> matrix(3,5);
	std::cout << matrix << "\n";
	RandomGenerator matrix1(-9, 9);
	matrix.Fill(matrix1);
	std::cout << "\n" << matrix << "\n";

	Exercise solver(3, 5, matrix1);
	solver.TaskOutput();
	return 0;
}