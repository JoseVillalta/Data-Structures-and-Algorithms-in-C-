#pragma once
#include<vector>


using namespace std;

class MergeSort
{
public:
    template <typename T>
    void Sort(vector<T> &v, int start, int end);
    template<typename T>
    void Merge(vector<T> &v, int start, int mid, int end);
};