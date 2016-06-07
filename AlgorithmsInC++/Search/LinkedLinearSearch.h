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
    template<typename T>
    bool SelfOrganizedSearch(ListNode<T>* head, ListNode<T>& loc, T item);
    template<typename T>
    bool MoveAheadOneLinkedSearch(ListNode<T>* head, ListNode<T>& loc, T item);


private:
    template<typename T>
    void ShiftList(ListNode<T>* head, ListNode<T>* cur, ListNode<T>* prev);
    template<typename T>
    void ListSwap(ListNode<T>* prePrev, ListNode<T>* prev, ListNode<T>* cur);
};

