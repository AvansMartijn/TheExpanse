#include "pch.h"
#include "CppUnitTest.h"
#include "../TheExpanse/Matrix.h"
#include "../TheExpanse/Matrix.cpp"
#include "../TheExpanse/Vector.h"
#include "../TheExpanse/Vector.cpp"

#include "../TheExpanse/ExpanseHelper.h"
#include "../TheExpanse/ExpanseHelper.cpp"

#include "../TheExpanse/TwoDObject.h"
#include "../TheExpanse/TwoDObject.cpp"


#include "../TheExpanse/ThreeDObject.h"
#include "../TheExpanse/ThreeDObject.cpp"

#include "../TheExpanse/Line.h"
#include "../TheExpanse/Line.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheExpanseTests
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(M3x2_Can_Add_M3x2)
		{
			//1. Arrange
			Matrix a(3, 2);

			a.mData[0][0] = 1;
			a.mData[0][1] = -2;

			a.mData[1][0] = 4;
			a.mData[1][1] = 0;
			
			a.mData[2][0] = -1;
			a.mData[2][1] = 7;

			Matrix b(3, 2);

			b.mData[0][0] = 3;
			b.mData[0][1] = 0;

			b.mData[1][0] = -4;
			b.mData[1][1] = -2;

			b.mData[2][0] = 5;
			b.mData[2][1] = 1;

			//2. Act
			a = a + b;

			//3. Assert
			Matrix m(3, 2);

			m.mData[0][0] = 4;
			m.mData[0][1] = -2;

			m.mData[1][0] = 0;
			m.mData[1][1] = -2;

			m.mData[2][0] = 4;
			m.mData[2][1] = 8;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(m.mData[i][j], a.mData[i][j]);
				}

			}

		}

		TEST_METHOD(M3x2_Can_Subtract_M3x2)
		{
			//1. Arrange
			Matrix a(3, 2);

			a.mData[0][0] = 1;
			a.mData[0][1] = -2;

			a.mData[1][0] = 4;
			a.mData[1][1] = 0;

			a.mData[2][0] = -1;
			a.mData[2][1] = 7;

			Matrix b(3, 2);

			b.mData[0][0] = 3;
			b.mData[0][1] = 0;

			b.mData[1][0] = -4;
			b.mData[1][1] = -2;

			b.mData[2][0] = 5;
			b.mData[2][1] = 1;

			//2. Act
			a = a - b;

			//3. Assert
			Matrix m(3, 2);

			m.mData[0][0] = -2;
			m.mData[0][1] = -2;

			m.mData[1][0] = 8;
			m.mData[1][1] = 2;

			m.mData[2][0] = -6;
			m.mData[2][1] = 6;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(m.mData[i][j], a.mData[i][j]);
				}

			}

		}

		TEST_METHOD(M3x2_Can_Multiply_Scalar)
		{
			//1. Arrange
			Matrix m(3, 2);

			m.mData[0][0] = 1;
			m.mData[0][1] = -2;

			m.mData[1][0] = 4;
			m.mData[1][1] = 0;

			m.mData[2][0] = -1;
			m.mData[2][1] = 7;

			//2. Act
			m = m * 3;

			//3. Assert
			Matrix a(3, 2);

			a.mData[0][0] = 3;
			a.mData[0][1] = -6;

			a.mData[1][0] = 12;
			a.mData[1][1] = 0;

			a.mData[2][0] = -3;
			a.mData[2][1] = 21;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(a.mData[i][j], m.mData[i][j]);
				}

			}

		}

		TEST_METHOD(M3x2_Can_Multiply_M2x3)
		{
			//1. Arrange
			Matrix a(3, 2);

			a.mData[0][0] = 1;
			a.mData[0][1] = -2;

			a.mData[1][0] = 4;
			a.mData[1][1] = 0;

			a.mData[2][0] = -1;
			a.mData[2][1] = 7;

			Matrix b(2, 3);

			b.mData[0][0] = 3;
			b.mData[0][1] = -4;
			b.mData[0][2] = 5;

			b.mData[1][0] = 0;
			b.mData[1][1] = -2;
			b.mData[1][2] = 1;

			//2. Act
			a = a * b;

			//3. Assert
			Matrix m(3, 3);

			m.mData[0][0] = 3;
			m.mData[0][1] = 0;
			m.mData[0][2] = 3;

			m.mData[1][0] = 12;
			m.mData[1][1] = -16;
			m.mData[1][2] = 20;

			m.mData[2][0] = -3;
			m.mData[2][1] = -10;
			m.mData[2][2] = 2;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(m.mData[i][j], a.mData[i][j]);
				}

			}
		}
		TEST_METHOD(M3x3_Can_Multiply_Vector)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(2, 3, 1);
			Vector b{ 1, 3, 1 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 3, 6, 1 };

			Assert::AreEqual(b.x, v.x);
			Assert::AreEqual(b.y, v.y);

		}
		TEST_METHOD(M2x2_Can_Multiply_Vector)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getScalingMatrix(2, 2, 1);
			Vector b{ 1, 3, 1 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 2, 6, 1 };

			Assert::AreEqual(b.x, v.x);
			Assert::AreEqual(b.y, v.y);

		}
		TEST_METHOD(TranslationMatrix)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(2, 3, 1);
			Vector b{ 1, 3, 1 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 3, 6, 1 };

			Assert::AreEqual(b.x, v.x);
			Assert::AreEqual(b.y, v.y);

		}

		

		TEST_METHOD(ScalingMatrix)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getScalingMatrix(2, 2, 1);
			Vector b{ 0, 3, 1 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 0, 6, 1 };

			Assert::AreEqual(b.x, v.x);
			Assert::AreEqual(b.y, v.y);

		}

		//TEST_METHOD(RotationMatrix)
		//{
		//	//1. Arrange
		//	ExpanseHelper helpert;
		//	Vector b{ 3, 3 };

		//	Matrix a = helpert.getRotationMatrix(45);

		//	//2. Act
		//	b = a * b;

		//	//3. Assert
		//	Vector v{ 0, 6 };

		//	Assert::AreEqual(b.x, v.x);
		//	Assert::AreEqual(b.y, v.y);

		//}
	};
}
