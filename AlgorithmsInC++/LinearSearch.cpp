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

template bool LinearSearch::Search(vector<int>& v, int item, int& loc);