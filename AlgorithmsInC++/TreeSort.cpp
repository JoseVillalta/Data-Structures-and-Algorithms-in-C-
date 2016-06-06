#include "TreeSort.h"

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

   // for (T i : temp)
   // {
   //     v.push_back(i);
   // }
}

template void TreeSort::Sort(vector<int> & v, int start, int end);