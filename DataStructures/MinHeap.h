#pragma once
#include "stdafx.h"
#include <vector>
using namespace std;
#define MAX_CAPACITY 1000

class MinHeap
{
public:
    MinHeap();
    void Insert(int val);
    int ExtractMin();
    bool IsFull();
private:
    vector<int> * arr;
    int curIndex;
    void BubbleUp(int index);
    void BubbleDown(int index);
    int GetParent(int index);
    int GetChildren(int index);
};