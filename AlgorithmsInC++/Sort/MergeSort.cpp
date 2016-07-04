#include "MergeSort.h"

template <typename T>
void MergeSort::Sort(vector<T> &v, int start, int end)
{
    if (start < end)
    {
        int p = ((start + end) / 2);
        Sort(v, start, p);
        Sort(v, p+1, end);
        Merge(v, start, p, end);

    }
}

template <typename T>
void MergeSort::Merge(vector<T> &v, int start, int mid, int end)
{
    if (start < end)
    {

        vector<T> v1;
        vector<T> v2;

        int v1Len = (mid - start) + 1;
        int v2Len = end - mid;

        for (int i = 0; i < v1Len; i++)
        {
            v1.push_back(v.at(start + i));
        }


        for (int j = 0; j < v2Len; j++)
        {
            v2.push_back(v.at(mid + 1 + j));
        }


        int indexV1 = 0;
        int indexV2 = 0;
        int indexV = start;

        while (indexV1 < v1Len && indexV2 < v2Len)
        {
            if (v1[indexV1] <= v2[indexV2])
            {
                v[indexV] = v1[indexV1];
                indexV1++;
               
            }
            else
            {
                v[indexV] = v2[indexV2];
                indexV2++;
            }
            indexV++;
        }

        while (indexV1 < v1Len)
        {
            v[indexV] = v1[indexV1];
            indexV1++;
            indexV++;
        }

        while (indexV2 < v2Len)
        {
            v[indexV] = v2[indexV2];
            indexV2++;
            indexV++;
        }
    }
}

template void MergeSort::Sort(vector<int> &v, int start, int end);
template void MergeSort::Merge(vector<int> &v, int start, int mid, int end);