#include "BubbleSort.h"
#include "swap.h"

template <typename T>
void BubbleSorter::Sort(vector<T> & v, int start, int end)
{
    int left = start;
    int right = end;

    while (right > 0)
    {
        for (int i = 0; i < right; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v, i, i + 1);
            }
        }
        right--;
    }
}

template void BubbleSorter::Sort(vector<int> & v, int start, int end);