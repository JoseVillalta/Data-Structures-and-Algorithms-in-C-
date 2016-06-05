#include "ShellSortTest.h"

void ShellSortTest::DoTests()
{
    vector<int> v = { 100, 90, 60, 70, 40, 20, 50, 30, 80, 10 };
    vector<int> expected = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    auto sorter = new ShellSorter();
    sorter->Sort(v, 0, 9);

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int j = 0; j < v.size(); j++)
    {
        _ASSERT(v[j] == expected[j]);
    }
}