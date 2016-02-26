#include <iostream> //_ASSERT
#include "LinkedLinearSearch.h"

template <typename T>
bool LinkedLinearSearch::Search(ListNode<T> *head, ListNode<T> &loc, T item)
{
    if (head == nullptr) return false;

    auto temp = head;
    if (temp->data == item)
    {
        loc = *temp;
        return true;
    }
    else
    {
        Search(temp->next, loc, item);
    }

}
template <typename T>
bool LinkedLinearSearch::SearchIt(ListNode<T> * head, ListNode<T> &loc, T item)
{
    if (head == nullptr) return false;

    auto temp = head;
    bool found = false;
    while (temp != nullptr)
    {
        if (temp->data == item)
        {
            found = true;
            loc = *temp;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    return found;
}
template<typename T>
ListNode<T>* LinkedLinearSearch::SelfOrganizedListSearch(ListNode<T>* head, T item)
{
    ListNode<T> * loc = nullptr;
    auto cur = head;
    auto prev = head;
    bool found = SelfOrganizedSearch(head, item, loc, cur, prev);
    if (found)
    {
        _ASSERT(loc->data == item);
    }

    return loc;
}

template<typename T>
bool LinkedLinearSearch::SelfOrganizedSearch(ListNode<T>* head, T item, ListNode<T>& loc, ListNode<T>* cur, ListNode<T>* prev)
{
    if (head == nullptr) return false;

    if (cur->data == item)
    {
        loc = *cur;
        //Move node to the top of the list right after the head node
        ShiftList(head, cur, prev);
        return true;
    }
    else
    {
        return SelfOrganizedSearch(head, item, loc, cur->next, cur);
    }
}

template<typename T>
void LinkedLinearSearch::ShiftList(ListNode<T>* head, ListNode<T>* cur, ListNode<T>* prev)
{
    _ASSERT(head != nullptr);
    _ASSERT(cur != nullptr);
    _ASSERT(prev != nullptr);

    //Move node to the top of the list right after the head node
    prev->next = cur->next;
    cur->next = head->next;
    head->next = cur;
}

template bool LinkedLinearSearch::Search(ListNode<int>* head, ListNode<int>& node, int item);
template bool LinkedLinearSearch::SearchIt(ListNode<int>* head, ListNode<int>& node, int item);