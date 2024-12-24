#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace Tests2Matrix
{
	TEST_CLASS(Tests2Matrix)
	{
	public:

		TEST_METHOD(Constructor_ValidData_Success)
		{
			Matrix<int> matrix(2, 2);
			Assert::IsTrue(matrix[0][0] == 0 && matrix[0][1] == 0 && matrix[1][0] == 0 && matrix[1][1] == 0);
		}

		TEST_METHOD(Iterator_ValidData_Success)
		{
			Matrix<int> matrix(2, 2);
			matrix[1][0] = 5;
			matrix[1][1] = -7;
			std::vector<int> matrix2{ 0,0 };
			std::vector<int> matrix3{ 5,-7 };
			Assert::IsTrue(matrix[0] == matrix2 && matrix[1] == matrix3);
		}

		TEST_METHOD(GetRows_ValidData_Success)
		{
			Matrix<int> matrix(2, 3);
			size_t rows = 2;
			Assert::IsTrue(matrix.GetRows() == rows);
		}

		TEST_METHOD(GetColumns_ValidData_Success)
		{
			Matrix<int> matrix(2, 3);
			size_t columns = 3;
			Assert::IsTrue(matrix.GetColumns() == columns);
		}

		TEST_METHOD(ToString_ValidData_Success)
		{
			Matrix<int> matrix(2, 2);
			matrix[0][0] = -1;
			matrix[0][1] = 3;
			matrix[1][0] = 5; 
			matrix[1][1] = -7;
			std::string matrix2 = "-1 3 \n5 -7 \n";
			Assert::IsTrue(matrix.ToString() == matrix2);
		}

		TEST_METHOD(DeleteColumn_ValidData_Success)
		{
			size_t columns_number = 3;
			Matrix<int> matrix(2, columns_number);
			matrix.DeleteColumn(1);
			Assert::IsTrue(matrix.GetColumns() != columns_number);
		}
	};
}