#include "MergeSortTest.h"
#include "RandomVector.h"
#include <algorithm>

void MergeSortTest::DoTests()
{
    TestSort();
    TestBiggerInputs();
    CountingInversions();
}

void MergeSortTest::CountingInversions()
{
    cout << "Counting Inversions" << endl;
    vector<int> v = { 2, 1, 3, 1, 2 };
    auto ms = new MergeSort();
    ms->Sort(v, 0, 4);

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

void MergeSortTest::TestBiggerInputs()
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

    auto ms = new MergeSort();
    ms->Sort(*v, 0, 999);
    std::sort(expected->begin(), expected->end());

    for (int i = 0; i < v->size(); i++)
    {
        _ASSERT(v->at(i) == expected->at(i));
    }

    cout << "Merge Sort test passed" << endl;
}