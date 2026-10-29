#include "pch.h"
#include "CppUnitTest.h"


#define UNIT_TESTING


#include "../Project 6.4(1)/Project 6.4(1).cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
    TEST_CLASS(UnitTest64)
    {
    public:

        TEST_METHOD(TestMethod_MinAbsRec)
        {
            const int size = 5;
            int arr[size] = { -8, 4, -2, 9, 3 };

            int expected = -2;
            int actual = MinAbsRec(arr, size);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod_SumAbsAfterFirstZeroRec)
        {
            const int size = 6;
            int arr[size] = { 5, 0, -3, 2, -1, 4 };

            int expected = 10;
            int actual = SumAbsAfterFirstZeroRec(arr, size);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod_TransformRec)
        {
            const int size = 6;
            int arr[size] = { 10, 20, 30, 40, 50, 60 };

            TransformRec(arr, size);

            Assert::AreEqual(10, arr[0]);
            Assert::AreEqual(30, arr[1]);
            Assert::AreEqual(50, arr[2]);
            Assert::AreEqual(20, arr[3]);
            Assert::AreEqual(40, arr[4]);
            Assert::AreEqual(60, arr[5]);
        }
    };
}
