#include "MinMaxSortTest.h"

void MinMaxSortTest::DoTests()
{
    cout << "Min Max Sort Test Start" << endl;
    vector<int> v = { 30, 80, 90, 20, 60, 70, 10, 100, 50, 40 };
    vector<int> expected = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    auto ms = new MinMaxSort();
    ms->Sort(v, 0, 9);

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }
    cout << "Min Max Sort Test Passed" << endl;
}
