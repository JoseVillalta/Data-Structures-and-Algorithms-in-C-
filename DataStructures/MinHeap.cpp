#include "stdafx.h"
#include "MinHeap.h"
#include "swap.h"
#include <iostream>

MinHeap::MinHeap()
{
    arr = new vector<int>();
    curIndex = 0;
}


void MinHeap::Insert(int val)
{
    if (curIndex + 1 <= MAX_CAPACITY)
    {
        arr->push_back(val);
        BubbleUp(curIndex);
        curIndex++;
    }
    else
    {
        cout << "Heap Max Capacity Reached" << endl;
    }
}

int MinHeap::ExtractMin()
{
    if (!arr->empty())
    {
        int min = arr->front();
        arr->at(0) = arr->back();
        arr->pop_back();
        BubbleDown(0);
        curIndex--;
    }
    else
    {
        cout << "Heap is Empty dood" << endl;
    }
    return 0;
}

void MinHeap::BubbleUp(int index)
{
    int parent = GetParent(index);
    if (parent == -1) return;
    if (arr->at(index) < arr->at(parent))
    {
        swap(*arr, index, parent);
        BubbleUp(parent);
    }
}

void MinHeap::BubbleDown(int index)
{
    int childIndex = GetChildren(index);
    if (childIndex == -1) return;
    int minIndex = index;

    if (childIndex + 1 < curIndex)
    {
        if (arr->at(childIndex + 1) > arr->at(index))
        {
            minIndex = childIndex + 1;
            //swap(*arr, index,);
        }
    }
    if (arr->at(index) > arr->at(childIndex))
    {
        swap(*arr, index, childIndex);
        BubbleDown(childIndex);
    }
}

int MinHeap::GetChildren(int index)
{
    return 0;
}

int MinHeap::GetParent(int index)
{
    return 0;
}




