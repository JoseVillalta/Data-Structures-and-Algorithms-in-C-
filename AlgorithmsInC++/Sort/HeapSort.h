#pragma once
#include <vector>

using namespace std;

class HeapSort
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
    template <typename T>
    void PercolateDown(vector<T> & v, int start, int end);
    template <typename T>
    void Heapify(vector<T> &v,int start, int end);
};
