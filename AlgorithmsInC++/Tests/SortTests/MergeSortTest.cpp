#include "MergeSortTest.h"

void MergeSortTest::DoTests()
{
    //TestSort();
}

void MergeSortTest::TestSort()
{
    cout << "Merge Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto ms = new MergeSort();
    ms->Sort(v, 0, 6);
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (auto i = 0; i < (int)v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }
    cout << "Merge Sort Test Passed" << endl;

}