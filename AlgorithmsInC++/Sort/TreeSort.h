#pragma once
#include "BinarySearchTree.h"
#include <vector>

using namespace std;

class TreeSort
{
public:
    template <typename T>
    void Sort(vector<T> & v, int start, int end);
};