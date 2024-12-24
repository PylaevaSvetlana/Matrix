#pragma once
#include "Matrix.h"
#include "VirtualExercise.h"

namespace miit::algebra 
{
	class Exercise :public miit::algebra::VirtualExercise
	{
	public:
		Exercise(size_t rows, size_t columns, Generator& generator);
		void task1() override;
		void task2() override;
			};
}