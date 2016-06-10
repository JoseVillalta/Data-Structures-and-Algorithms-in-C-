#pragma once
#include "HeapSort.h"
#include "swap.h"

template <typename T>
void HeapSort::Sort(vector<T> &v, int start, int end)
{
    int left = start;
    int right = end;
    while (right >= left)
    {
       Heapify(v,left,right);
       swap(v, left, right);
       right--;
    }
}

template <typename T>
void HeapSort::PercolateDown(vector<T> &v, int start, int end)
{
    int root = start;
    int child = root * 2 + 1;
    while (child <= end)
    {      
        if (child + 1 <= end)
        {
            if (v[child] < v[child + 1])
            {
                child++;
            }
        }
        if (v[root] < v[child])
        {
            swap(v, root, child);
        }
        root = child;
        child = child * 2 + 1;      
    }
}

template <typename T>
void HeapSort::Heapify(vector<T> & v, int start, int end)
{
    int r = end / 2 + 1;
    while (r >= 0)
    {
        PercolateDown(v, r, end);
        r--;
    }

}

template void HeapSort::PercolateDown(vector<int> & v, int start, int end);
template void HeapSort::Heapify(vector<int> & v, int start, int end);
template void HeapSort::Sort(vector<int> & v, int start, int end);