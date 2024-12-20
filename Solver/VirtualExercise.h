#pragma once
#include"Matrix.h"

namespace miit::algebra
{
	class VirtualExercise
	{
	protected:

		Matrix<int> matrix;

		virtual void task1() = 0;

		virtual void task2() = 0;

	public:

		explicit VirtualExercise(int rows, int columns, Generator& generator);
		virtual ~VirtualExercise() = default;
		void TaskOutput();
	};
}



