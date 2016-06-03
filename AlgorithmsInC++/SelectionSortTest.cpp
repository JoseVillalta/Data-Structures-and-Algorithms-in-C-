#include "SelectionSortTest.h"
#include <iostream>
#include <vector>

using namespace std;
void SelectionSortTest::DoTests()
{
    TestSort();
    TestDoubleSort();
}

void SelectionSortTest::TestSort()
{
    cout << "Selection Sort Test" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto selectionSorter = new SelectionSorter();

    selectionSorter->Sort(v, 0, 6);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Selection Sort test passed" << endl;
}

void SelectionSortTest::TestDoubleSort()
{
    cout << "Double Ended Selection Sort Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto selectionSorter = new SelectionSorter();

    selectionSorter->DoubleEndedSort(v, 0, 6);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Double Ended Selection Sort Passed" << endl;

}