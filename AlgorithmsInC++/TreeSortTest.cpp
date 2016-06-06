#include "TreeSortTest.h"
#include "BinarySearchTree.h"

void TreeSortTest::DoTests()
{
    cout << "Tree Sort Test Start" << endl;
    vector<int> v = { 67, 33, 21, 84, 49, 50, 75 };
    vector<int> expected = { 21, 33, 49, 50, 67, 75, 84 };
    auto sorter = new TreeSort();
    sorter->Sort(v, 0, 6);

    for (int i = 0; i < v.size(); i++)
    {
        _ASSERT(v[i] == expected[i]);
    }

    cout << "Tree Sort Test Passed" << endl;
}