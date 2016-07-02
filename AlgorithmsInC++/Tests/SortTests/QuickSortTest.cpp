#include "QuickSortTest.h"
#include "RandomVector.h"
#include <algorithm>

void QuickSortTest::DoTests()
{
    TestSort();
    TestLargerInput();
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

void QuickSortTest::TestLargerInput()
{
    cout << "Sorting 1000 integers" << endl;
    vector<int> * v = new vector<int>();
    vector<int> *expected = new vector<int>();

    GetRandomVector(*v, 1000);

    //copy vector
    for (auto i : *v)
    {
        expected->push_back(i);
    }

    auto qs = new QuickSort();
    qs->Sort(*v, 0, 999);
    std::sort(expected->begin(), expected->end());

    for (int i = 0; i < v->size(); i++)
    {
        _ASSERT(v->at(i) == expected->at(i));
    }

    cout << "Yeah, QuickSort works, bro" << endl;
}