#pragma once
#include <vector>

using namespace std;

class SelectionSorter
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
    template <typename T>
    void DoubleEndedSort(vector<T> & v, int start, int end);
};