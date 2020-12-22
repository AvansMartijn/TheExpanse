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
	TEST_CLASS(TranslationMatrix3DTests)
	{
	public:

		TEST_METHOD(Translate_Point_XAxis)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(10, 0, 0);
			Vector b{ 10, 10, 10 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 20, 10, 10 };

			Assert::AreEqual(v.x, b.x);
			Assert::AreEqual(v.y, b.y);
			Assert::AreEqual(v.z, b.z);

		}

		TEST_METHOD(Translate_Point_YAxis)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(0, 10, 0);
			Vector b{ 10, 10, 10 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 10, 20, 10 };

			Assert::AreEqual(v.x, b.x);
			Assert::AreEqual(v.y, b.y);
			Assert::AreEqual(v.z, b.z);

		}

		TEST_METHOD(Translate_Point_ZAxis)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(0, 0, 10);
			Vector b{ 10, 10, 10 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 10, 10, 20 };

			Assert::AreEqual(v.x, b.x);
			Assert::AreEqual(v.y, b.y);
			Assert::AreEqual(v.z, b.z);

		}

		TEST_METHOD(Translate_Direction_ZAxis)
		{
			//1. Arrange
			ExpanseHelper helpert;
			Matrix a = helpert.getTranslationMatrix(10, 0, 0);
			Vector b{ 0, 0, -1, 0 };

			//2. Act
			b = a * b;

			//3. Assert
			Vector v{ 0, 0, -1 };

			Assert::AreEqual(v.x, b.x);
			Assert::AreEqual(v.y, b.y);
			Assert::AreEqual(v.z, b.z);

		}
	};
}