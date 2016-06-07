#include "SelectionSort.h"
#include "swap.h"

template <typename T>
void SelectionSorter::Sort(vector<T> & v, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = i; j <= end; j++)
        {
            if (v[j] < v[i])
            {
                swap(v, j, i);
            }
        }
    }
}

template <typename T>
void SelectionSorter::DoubleEndedSort(vector<T> & v, int start, int end)
{
    int left = start;
    int right = end;

    while (left <= right)
    {
        int i = left+1;
        int j = right-1;
        while (i <= end && j >= start)
        {
            if (v[i] < v[left])
            {
                swap(v, i, left);
            }
            if (v[j] > v[right])
            {
                swap(v, j, right);
            }
            i++;
            j--;
        }
        left++;
        right--;
    }
}

template <typename T>
void SelectionSorter::RecursiveSort(vector<T> & v, int start, int end)
{
    if (end > start)
    {
        for (int i = start; i <= end; i++)
        {
            if (v[i] < v[start])
            {
                swap(v, i, start);
            }
        }
        RecursiveSort(v, start + 1, end);
    }
}

template void SelectionSorter::Sort(vector<int> & v, int start, int end);
template void SelectionSorter::DoubleEndedSort(vector<int> & v, int start, int end);
template void SelectionSorter::RecursiveSort(vector<int> & v, int start, int end);