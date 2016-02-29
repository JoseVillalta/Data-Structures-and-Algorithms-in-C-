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
        return Search(temp->next, loc, item);
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
bool LinkedLinearSearch::SelfOrganizedSearch(ListNode<T>* head, ListNode<T>& loc, T item)
{
    if (head == nullptr) return false;
    bool found = false;
    auto nodePtr = head;
    auto prev = head;

    while (nodePtr != nullptr)
    {
        if (nodePtr->data == item)
        {
            found = true;
            loc = *nodePtr;
            ShiftList(head, nodePtr, prev);
            break;
        }
        else
        {
            prev = nodePtr;
            nodePtr = nodePtr->next;
        }
    }


    return found;
}

template<typename T>
void LinkedLinearSearch::ShiftList(ListNode<T>* head, ListNode<T>* cur, ListNode<T>* prev)
{
    if (cur == prev) return;
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
template bool LinkedLinearSearch::SelfOrganizedSearch(ListNode<int>* head, ListNode<int>& loc, int item);