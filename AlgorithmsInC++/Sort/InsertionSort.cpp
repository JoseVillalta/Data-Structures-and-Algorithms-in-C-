#include "InsertionSort.h"
#include "swap.h"

template <typename T>
void InsertionSorter::Sort(vector<T> & v, int start, int end)
{
    int left = start;
    int right = start+1;

    while (right <= end)
    {
        for (int i = right; i > left; i--)
        {
            if (v[i - 1] > v[i])
            {
                swap(v, i - 1, i);
            }
        }

        right++;
    }
}

template void InsertionSorter::Sort(vector<int> & v, int start, int end);