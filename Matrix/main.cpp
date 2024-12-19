#include <iostream>
#include "..\Solver\Matrix.h"
#include "..\Solver\Exercise.h"

using namespace miit::algebra;
int main()
{
	Matrix<int> matrix1(4, 5);
	std::cout << matrix1 << "\n";
	matrix1.FillRandom(-9, 9);
	std::cout << "\n" << matrix1 << "\n";


	Exercise solver(matrix1);
	std::cout << "\n" << solver.task1();
	return 0;
}