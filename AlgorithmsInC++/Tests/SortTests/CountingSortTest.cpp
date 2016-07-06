#include "CountingSortTest.h"

void CountingSortTest::DoTests()
{
    SortTest();
}

void CountingSortTest::SortTest()
{
    cout << "Starting Counting Sort" << endl;
    int in[8] = { 2, 5, 3, 0, 2, 3, 0, 3 };
    int expected[] = { 0, 0, 2, 2, 3, 3, 3, 5 };
    int out[8] = { 0 };

    auto countingSort = new CountingSort();

    countingSort->Sort(in, out, 8, 6);

    for (int i = 0; i < 8; i++)
    {
        _ASSERT(out[i] == expected[i]);
    }

    cout << "Counting Sort passed" << endl;
}