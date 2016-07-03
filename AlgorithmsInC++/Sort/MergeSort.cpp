#include "MergeSort.h"

template <typename T>
void MergeSort::Sort(vector<T> &v, int start, int end)
{
    if (start < end)
    {
        int p = ((start + end) / 2);
        Sort(v, start, p);
        Sort(v, p+1, end);
    }
}

template <typename T>
void MergeSort::Merge(vector<T> &v, int start, int end)
{
    if (start < end)
    {
        int mid = (end - start) / 2;

        vector<T> v1;
        vector<T> v2;

        for (int i = 0; i < mid; i++)
        {
            v1.push_back(v.at(i));
        }

        for (int j = mid; j < end; j++)
        {
            v2.push_back(v.at(j));
        }

        int indexV1 = 0;
        int indexV2 = 0;
        int indexV = start;

        while (indexV <= end)
        {
            if (v1[indexV1] <= v2[indexV2])
            {
                v[indexV] = v1[indexV1];
                indexV1++;
               
            }
            else
            {
                v[indexV] = v1[indexV2];
                indexV2++;
            }
            indexV++;
        }     
    }
}

template void MergeSort::Sort(vector<int> &v, int start, int end);
template void MergeSort::Merge(vector<int> &v, int start, int end);