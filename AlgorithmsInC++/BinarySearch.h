#pragma once
#include <vector>
using namespace std;

class BinarySearch
{
public:
    template<typename T>
    bool Search(vector<T>& vector, int& loc, T item, int start, int end);
};

