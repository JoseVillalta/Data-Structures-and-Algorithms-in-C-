#pragma once
#include <vector>
using namespace std;

class BinarySearch
{
public:
    template<typename T>
    bool Search(vector<T>& vector, T& item, int start, int end);
};

