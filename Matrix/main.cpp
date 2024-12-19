#include <iostream>
#include "..\Solver\Matrix.h"

using namespace miit::algebra;
int main()
{
	Matrix<int> matrix(4, 5);
	std::cout << matrix << "\n";
	matrix.FillRandom(-9, 9);
	std::cout << "\n" << matrix << "\n";
	matrix.FillIStream(std::cin);
	std::cout << "\n" << matrix << "\n";
	return 0;
}