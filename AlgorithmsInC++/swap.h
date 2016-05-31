#pragma once
#include <vector>

using namespace std;
template <typename T>
void swap(vector<T> & v, int a, int b)
{
    T temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}