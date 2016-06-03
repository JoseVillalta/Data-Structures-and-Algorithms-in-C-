#pragma once
#include <vector>

using namespace std;

class BubbleSorter
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
};