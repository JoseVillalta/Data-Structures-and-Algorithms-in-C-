#include "SelectionSortTest.h"
#include "SortableRecord.h"
#include <iostream>
#include <vector>

using namespace std;
void SelectionSortTest::DoTests()
{
    TestSort();
    TestDoubleSort();
    TestRecursiveSelectionSort();
    TestSortStudentRecords();
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

void SelectionSortTest::TestRecursiveSelectionSort()
{
    cout << "Recursive Selection Sort Start" << endl;

    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto selectionSorter = new SelectionSorter();
    
    selectionSorter->RecursiveSort(v, 0, 6);

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Recursive Selection Sort Passed" << endl;

}

void SelectionSortTest::TestSortStudentRecords()
{
    cout << "Start Selection Sort on Student Records" << endl;

    vector<SortableRecord> v;

    SortableRecord sr65;
    sr65.m_studentNum = 65;
    sr65.m_studenName = "Charlie";
    v.push_back(sr65);

    SortableRecord sr70;
    sr70.m_studentNum = 70;
    sr70.m_studenName = "Bob";
    v.push_back(sr70);

    SortableRecord sr13;
    sr13.m_studentNum = 13;
    sr13.m_studenName = "Hanna";
    v.push_back(sr13);

    SortableRecord sr57;
    sr57.m_studentNum = 57;
    sr57.m_studenName = "Dan";
    v.push_back(sr57);

    SortableRecord sr48;
    sr48.m_studentNum = 48;
    sr48.m_studenName = "Effie";
    v.push_back(sr48);

    SortableRecord sr22;
    sr22.m_studentNum = 22;
    sr22.m_studenName = "Gaby";
    v.push_back(sr22);

    SortableRecord sr85;
    sr85.m_studentNum = 85;
    sr85.m_studenName = "Alice";
    v.push_back(sr85);
    
    SortableRecord sr39;
    sr39.m_studentNum = 39;
    sr39.m_studenName = "Frank";
    v.push_back(sr39);

    cout << "Records before Sorting" << endl;
    for (auto r : v)
    {
        cout << r.m_studentNum << " ," << r.m_studenName << endl;
    }
   
    auto selectionSorter = new SelectionSorter();
    selectionSorter->Sort(v, 0, 7);

    cout << "Records after Sorting" << endl;
    for (auto r : v)
    {
        cout << r.m_studentNum << " ," << r.m_studenName << endl;
    }

    vector<SortableRecord> expected;

    expected.push_back(sr13);
    expected.push_back(sr22);
    expected.push_back(sr39);
    expected.push_back(sr48);
    expected.push_back(sr57);
    expected.push_back(sr65);
    expected.push_back(sr70);
    expected.push_back(sr85);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Selection Sort on Students Records Passed" << endl;
}