#include "ShellSort.h"
#include <cmath>
#include <iostream>

template <typename T>
void ShellSorter::Sort(vector<T> & v, int start, int end)
{
    int lenght = end - start;
    auto gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };

    for (auto gap : gaps)
    {
        for (int i = 0; i <= end-gap && gap < end; i += gap)
        {
            for (int j = i; j <= end-gap && gap <= end;  j += gap )
            {
                if ((j+gap) <= end)
                {
                    if (v[j] > v[j + gap])
                    {
                        swap(v, j, j + gap);
                    }

                }
                
            }
           
        }
    }
}

template void ShellSorter::Sort(vector<int> & v, int start, int end);