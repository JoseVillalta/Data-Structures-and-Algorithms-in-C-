#pragma once
#include <vector>
#include "SortableRecord.h"

using namespace std;

class SelectionSorter
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
    template <typename T>
    void DoubleEndedSort(vector<T> & v, int start, int end);
    template <typename T>
    void RecursiveSort(vector<T> & v, int start, int end);
};