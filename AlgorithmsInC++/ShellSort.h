#pragma once
#include "swap.h"
#include <vector>

using namespace std;

class ShellSorter
{
public:
    template <typename T>
    void Sort(vector<T> &v, int start, int end);
};