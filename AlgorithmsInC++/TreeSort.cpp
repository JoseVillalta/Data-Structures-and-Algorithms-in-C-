#include "TreeSort.h"
#include <iostream>

template <typename T>
void TreeSort::Sort(vector<T> & v, int start, int end)
{
    auto bst = new BST<T>();
    for (auto item : v)
    {
        bst->Insert(item);
    }

    v.clear();
    vector<T> * temp = bst->ToVectorInOrder();

    for (int i = 0; i < temp->size(); i++)
    {
        v.push_back(temp->at(i));
    }

    delete temp;
}

template void TreeSort::Sort(vector<int> & v, int start, int end);