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

		explicit VirtualExercise(size_t rows, size_t columns, Generator& generator);
		virtual ~VirtualExercise() = default;
		void TaskOutput();
		Matrix<int> GetMatrix();
	};
}



