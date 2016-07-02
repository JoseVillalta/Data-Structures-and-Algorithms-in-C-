#pragma once
#include <vector>
#include "swap.h"

using namespace std;

class QuickSort
{
public:
    template <typename T>
    void Sort(vector<T> &v, int start, int end);
    template <typename T>
    int Partition(vector<T> &v, int start, int end);

};