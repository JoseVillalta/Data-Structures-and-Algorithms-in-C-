#pragma once
#include "LinkedListNode.h"
class LinkedBinarySearch
{
public:
    template<typename T>
    bool Search(ListNode<T> * first, ListNode<T> * last, T item, ListNode<T> & loc);
};

