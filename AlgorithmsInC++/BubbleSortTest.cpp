#include "BubbleSortTest.h"

void BubbleSortTest::DoTests()
{
    TestSort();
    TestRecursiveSort();
}

void BubbleSortTest::TestSort()
{
    cout << "Bubble Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto bs = new BubbleSorter();
    bs->Sort(v, 0, 6);
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }
    cout << "Bubble Sort Test Passed" << endl;
}

void BubbleSortTest::TestRecursiveSort()
{
    cout << "Recursive Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto bs = new BubbleSorter();
    bs->RecursiveSort(v, 0, 6);
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }
    cout << "Recursive Bubble Sort Test Passed" << endl;
}