#pragma once
#include <vector>

using namespace std;

class InsertionSorter
{
public:
    template<typename T>
    void Sort(vector<T> & v, int start, int end);
};