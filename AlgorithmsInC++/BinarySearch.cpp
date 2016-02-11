#include "BinarySearch.h"


template<typename T>
bool BinarySearch::Search(vector<T>& v, int& loc, T item, int start, int end)
{
    if (end < start) return false;
    int mid = (start + end) / 2;

    if (v[mid] == item)
    {
        loc = mid;
        return true;
    }
    else if (v[mid] > item)
    {
        return Search(v, loc, item, start, mid - 1);
    }
    else
    {
        return Search(v, loc, item, mid + 1, end);
    }


}

template bool BinarySearch::Search(vector<int>& v, int& loc, int item, int start, int end);