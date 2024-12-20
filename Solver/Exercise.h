#pragma once
#include "Matrix.h"
#include "VirtualExercise.h"

namespace miit::algebra 
{
	class Exercise :public miit::algebra::VirtualExercise
	{
	public:
		Exercise(int rows, int columns, Generator& generator);
		void task1() override;
		void task2() override;
	};
}