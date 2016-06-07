#pragma once
#include <vector>
using namespace std;
class InterpolationSearch
{
public:
    template<typename T>
    bool Search(vector<T>&v, int&loc, T item);
};

