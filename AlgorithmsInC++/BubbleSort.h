#pragma once
#include <vector>

using namespace std;

class BubbleSorter
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
    template <typename T>
    void RecursiveSort(vector<T> & v, int start, int end);
};