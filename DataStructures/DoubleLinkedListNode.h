#pragma once
#include "LinkedListNode.h"

template <typename T>
class DListNode 
{
public:
    T data;
    DListNode * prev;
    DListNode * next;
    DListNode(T val = 0)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};