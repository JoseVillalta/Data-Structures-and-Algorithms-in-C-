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

}

template void SelectionSorter::Sort(vector<int> & v, int start, int end);
template void SelectionSorter::DoubleEndedSort(vector<int> & v, int start, int end);