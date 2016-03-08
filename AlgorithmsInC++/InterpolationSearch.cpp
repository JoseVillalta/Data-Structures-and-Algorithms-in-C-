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
    T first_val = v[first_index];
    T last_val = v[last_index];
    float k;
    while (last_index > first_index && first_val < item && last_val > item)
    {
        first_val = v[first_index];
        last_val = v[last_index];
        k = last_index - first_index;
        loc_index = first_index + (k*((float)item - (float)first_val)) / ((float)last_val - (float)first_val);
       
        if (v[loc_index] > item)
        {
            last_index = loc_index - 1;
        }
        else if (v[loc_index] < item)
        {
            first_index = loc_index + 1;
        }
        else
        {
            loc = loc_index;
            break;
        }

    }

    if (v[loc_index] == item)
    {
        found = true;
    }

    return found;
}

template bool InterpolationSearch::Search(vector<int>&v, int&loc, int item);