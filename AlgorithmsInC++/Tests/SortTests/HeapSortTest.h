#pragma once
#include "HeapSort.h"
#include <iostream>

using namespace std;

class HeapSortTest
{
public:
    void DoTests();
private:
    void TestPercolateDown();
    void TestHeapify();
    void TestSort();
};
