#include "pch.h"
#include "CppUnitTest.h"
#include "../TheExpanse/Matrix.h"
#include "../TheExpanse/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheExpanseTests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		
		TEST_METHOD(Matrix_Can_Multiply_Scalar)
		{
			//1. Arrange
			Matrix m(3, 3);

			m.mData[0][0] = 1;
			m.mData[0][1] = 2;
			m.mData[0][2] = 3;

			m.mData[1][0] = 1;
			m.mData[1][1] = 2;
			m.mData[1][2] = 3;

			m.mData[2][0] = 1;
			m.mData[2][1] = 2;
			m.mData[2][2] = 3;

			//2. Act
			m = m * 3;

			//3. Assert
			Matrix a(3, 3);

			a.mData[0][0] = 3;
			a.mData[0][1] = 6;
			a.mData[0][2] = 9;
			
			a.mData[1][0] = 3;
			a.mData[1][1] = 6;
			a.mData[1][2] = 9;
			
			a.mData[2][0] = 3;
			a.mData[2][1] = 6;
			a.mData[2][2] = 9;

			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					Assert::AreEqual(a.mData[i][j], m.mData[i][j]);
				}
				
			}

		}

		TEST_METHOD(Matrix_Can_Multiply_Matrix)
		{
			//1. Arrange
			Matrix m(3, 3);

			m.mData[0][0] = 1;
			m.mData[0][1] = 2;
			m.mData[0][2] = 3;

			m.mData[1][0] = 1;
			m.mData[1][1] = 2;
			m.mData[1][2] = 3;

			m.mData[2][0] = 1;
			m.mData[2][1] = 2;
			m.mData[2][2] = 3;

			Matrix ms(3, 3);

			ms.mData[0][0] = 1;
			ms.mData[0][1] = 1;
			ms.mData[0][2] = 1;

			ms.mData[1][0] = 1;
			ms.mData[1][1] = 1;
			ms.mData[1][2] = 1;

			ms.mData[2][0] = 1;
			ms.mData[2][1] = 1;
			ms.mData[2][2] = 1;

			//2. Act
			m = m * ms;

			//3. Assert
			Matrix a(3, 3);

			a.mData[0][0] = 3;
			a.mData[0][1] = 6;
			a.mData[0][2] = 9;

			a.mData[1][0] = 3;
			a.mData[1][1] = 6;
			a.mData[1][2] = 9;

			a.mData[2][0] = 3;
			a.mData[2][1] = 6;
			a.mData[2][2] = 9;

			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					Assert::AreEqual(a.mData[i][j], m.mData[i][j]);
				}

			}

		}
	};
}
