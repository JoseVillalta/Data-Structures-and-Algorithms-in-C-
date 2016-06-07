#include "ShellSort.h"
#include <cmath>
#include <iostream>

template <typename T>
void ShellSorter::Sort(vector<T> & v, int start, int end)
{
    auto gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };

    for (auto gap : gaps)
    {
        for (int i = start; i <= end && gap <= end; i += gap)
        {
            for (int j = i; j <= end && gap <= end;  j += gap )
            {
                if (v[i] > v[j])
                {
                    swap(v, i, j);
                }
            }
        }
    }
}

template void ShellSorter::Sort(vector<int> & v, int start, int end);