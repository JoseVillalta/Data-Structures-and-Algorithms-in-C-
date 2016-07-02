#include "QuickSortTest.h"

void QuickSortTest::DoTests()
{
    TestSort();
}

void QuickSortTest::TestSort()
{
    cout << "Quick Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto qs = new QuickSort();
    qs->Sort(v, 0, 6);
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (auto i = 0; i < (int)v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }
    cout << "Quick Sort Test Passed" << endl;
}