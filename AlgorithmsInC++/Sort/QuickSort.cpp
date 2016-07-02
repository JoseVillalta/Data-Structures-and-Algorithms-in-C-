#include "QuickSort.h"

template <typename T>
void QuickSort::Sort(vector<T> &v, int start, int end)
{
    if (start < end)
    {
        int p = Partition(v, start, end);
        Sort(v, start, p - 1);
        Sort(v, p + 1, end);
    }
}

template <typename T>
int QuickSort::Partition(vector<T> &v, int start, int end)
{
    int left = start;
    int right = end;

    T pivot = v[start];

    while (left < right)
    {
        while (v[right] > pivot)
            right--;
        
        while (left < right && v[left] <= pivot)
            left++;

        if (left < right)
            swap(v, left, right);
    }

    int pos = right;
    v[start] = v[pos];
    v[pos] = pivot;

    return pos;
}

template void QuickSort::Sort(vector<int> &v, int start, int end);
template int QuickSort::Partition(vector<int> &v, int start, int end);