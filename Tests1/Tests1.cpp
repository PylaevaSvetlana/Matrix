#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Exercise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(Task1_ValidData_Success)
		{
			RandomGenerator num(-9, 9);
			Exercise matrix(3, 5, num);
			Matrix<int> matrix2 = matrix.GetMatrix();
			matrix.task1();
			Assert::IsTrue(fabs(matrix.GetMatrix()[0][0]) >= fabs(matrix2[0][0]) && fabs(matrix.GetMatrix()[0][2]) >= fabs(matrix2[0][2]) && fabs(matrix.GetMatrix()[0][4]) >= fabs(matrix2[0][4]) &&
				fabs(matrix.GetMatrix()[1][1]) >= fabs(matrix2[1][1]) && fabs(matrix.GetMatrix()[1][3]) >= fabs(matrix2[1][3]) &&
				fabs(matrix.GetMatrix()[2][0]) >= fabs(matrix2[2][0]) && fabs(matrix.GetMatrix()[2][2]) >= fabs(matrix2[2][2]) && fabs(matrix.GetMatrix()[2][4]) >= fabs(matrix2[2][4]));
		}

		TEST_METHOD(Task2_ValidData_Success)
		{
			RandomGenerator num(-9, 9);
			Exercise matrix(3, 5, num);
			matrix.task2();
			if (matrix.GetMatrix().GetColumns() != 0)
			{
				for (size_t j = 0; j < matrix.GetMatrix().GetColumns(); ++j)
				{
					Assert::IsTrue(matrix.GetMatrix()[0][j] % 2 != 0);
				}
			}
		}
	};
}