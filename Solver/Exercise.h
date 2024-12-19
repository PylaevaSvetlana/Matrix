#pragma once
#include "Matrix.h"

namespace miit::algebra 
{
	class Exercise
	{
	private:
		Matrix<int> matrix;
	public:
		Exercise(Matrix<int> matrix);
		Matrix<int> task1();
	};
}