#pragma once
#include "LinkedListNode.h"

using namespace std;

class LinkedLinearSearch
{
public:
    template<typename T>
    bool Search(ListNode<T>* head, ListNode<T> & loc, T item);
    template<typename T>
    bool SearchIt(ListNode<T>*head, ListNode<T> & loc, T item);
};

