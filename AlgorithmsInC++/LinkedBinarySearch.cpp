#include "LinkedBinarySearch.h"

template<typename T>
bool LinkedBinarySearch::Search(ListNode<T> * first, ListNode<T> * last, T item, ListNode<T> & loc)
{
    if (first == nullptr || last == nullptr) return false;
    if (first->data > last->data) return false;

    auto mid = first;
    auto runner = first;

    while (runner != last && runner != nullptr)
    {
        mid = mid->next;
        runner = runner->next;
        if (runner != last)
        {
            runner = runner->next;
        }
    }

    if (mid->data == item)
    {
        loc = *mid;
        return true;
    }
    else if (mid->data > item)
    {
        return Search(first, mid, item, loc);
    }
    else
    {
        return Search(mid->next, last, item, loc);
    }
}

template bool LinkedBinarySearch::Search(ListNode<int> * first, ListNode<int>* last, int item, ListNode<int> & loc);