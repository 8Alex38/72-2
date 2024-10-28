#include "pch.h"
#include "CppUnitTest.h"
#include "../72-2/72-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72_2
{
    TEST_CLASS(UnitTest72_2)
    {
    public:

        void TestMethodWithoutAssert()
        {
            const int k = 5;
            const int n = 2;
            int** matrix = new int* [k];
            for (int i = 0; i < k; ++i) {
                matrix[i] = new int[n];
            }

            matrix[0][0] = 1; matrix[0][1] = 2;
            matrix[1][0] = 3; matrix[1][1] = 4;
            matrix[2][0] = 5; matrix[2][1] = 6;
            matrix[3][0] = 7; matrix[3][1] = 8;
            matrix[4][0] = 9; matrix[4][1] = 0;

            int result = findMaxOfMinsInOddRows(matrix, k);
            int expected = 7;

            std::cout << "Expected: " << expected << ", Actual: " << result << std::endl;
            if (result == expected) {
                std::cout << "Test passed!" << std::endl;
            }
            else {
                std::cout << "Test failed!" << std::endl;
            }

            for (int i = 0; i < k; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(TestFindMaxOfMinsInOddRows)
        {
            TestMethodWithoutAssert();
        }
    };
}
