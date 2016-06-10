#include "HeapSortTest.h"

void HeapSortTest::DoTests()
{
    TestPercolateDown();
    TestHeapify();
    TestSort();
}

void HeapSortTest::TestPercolateDown()
{
    vector<int> v = { 10, 20, 30 };
    vector<int> expected = { 30, 20, 10 };

    auto heapSort = new HeapSort();
    heapSort->PercolateDown(v, 0, 2);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    vector<int> v2 = { 10, 20, 30, 40, 80, 50, 70 };
    vector<int> expected2 = { 30, 20, 70, 40, 80, 50, 10 };

    heapSort->PercolateDown(v2, 0, 7);

    for (int j = 0; j < v2.size(); j++)
    {
        _ASSERT(v2[j] == expected2[j]);
    }

    cout << "Test Percolate Down Passed" << endl;
}

void HeapSortTest::TestHeapify()
{
    vector<int> v = { 10, 20, 30, 40, 80, 50, 70 };
    vector<int> expected = { 80, 40, 70, 10, 20, 50, 30 };

    auto heapSort = new HeapSort();
    heapSort->Heapify(v,0,6);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Heapify test passed" << endl;
}

void HeapSortTest::TestSort()
{
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };

    auto heapSort = new HeapSort();
    heapSort->Sort(v, 0, 6);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Heap Sort Test Passed" << endl;

}