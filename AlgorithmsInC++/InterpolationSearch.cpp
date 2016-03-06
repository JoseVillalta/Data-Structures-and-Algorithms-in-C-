#include "InterpolationSearch.h"

template<typename T>
bool InterpolationSearch::Search(vector<T>&v, int&loc, T item)
{
    auto v_size = v.size();
    if (v_size <= 0) return false;
    bool found = false;
    unsigned int loc_index = 0;
    unsigned int first_index = 0;
    unsigned int last_index = v_size - 1;
    T first_val;
    T last_val;
    int k;
    while (last_index > first_index)
    {
        first_val = v[first_index];
        last_val = v[last_index];
        k = last_index - first_index;
        loc_index = first_index + k*((item - first_val) / (last_val - first_val));

        if (v[loc_index] == item)
        {
            found = true;
            loc = loc_index;
            break;
        }
        else if (v[loc_index] > item)
        {
            last_index = loc_index - 1;
        }
        else
        {
            first_index = loc_index + 1;
        }

    }

    return found;
}

template bool InterpolationSearch::Search(vector<int>&v, int&loc, int item);