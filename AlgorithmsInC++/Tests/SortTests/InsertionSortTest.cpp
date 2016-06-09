#include "InsertionSortTest.h"

void InsertionSortTest::DoTests()
{
    cout << "Insertion Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };

    auto sorter = new InsertionSorter();
    sorter->Sort(v, 0, 6);

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Insertion Sort Test Passed" << endl;
}