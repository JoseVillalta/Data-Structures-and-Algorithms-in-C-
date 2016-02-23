#include "LinearSearch.h"
#include <iostream>
using namespace std;


template<typename T> 
bool LinearSearch::Search(vector<T>& v, T item, int& loc)
{
    bool found = false;
    int it = 0;
    for (auto i : v)
    {
        if (i == item)
        {
            found = true;
            break;
        }
        it++;
    }
    if (found) loc = it;

    return found;
}

template<typename T>
bool LinearSearch::SelfOrganizingListSearch(vector<T> & v, T item, int& loc)
{
    bool found = false;
    unsigned int index = 0;
    while (index < v.size())
    {
        int val = v[index];
        if (val == item)
        {
            if (index > 0)
            {
                Shift(index, v);
            }
            found = true;
            loc = index;
            break;
        }
        else
        {
            index++; 
        }
    }
    return found;
}

template<typename T>
void LinearSearch::Shift(int index, vector<T> &v)
{
    Reverse(0, index - 1, v);
    Reverse(0, index, v);
}

template<typename T>
void LinearSearch::Reverse(int start, int end, vector<T> & v)
{
    while (start < end)
    {
        T temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }
}
template bool LinearSearch::Search(vector<int>& v, int item, int& loc);
template bool LinearSearch::SelfOrganizingListSearch(vector<int>& v, int item, int & loc);
template void LinearSearch::Shift(int index, vector<int>& v);
template void LinearSearch::Reverse(int start, int end, vector<int>&v);
