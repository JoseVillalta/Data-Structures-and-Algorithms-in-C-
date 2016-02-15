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
}

template bool LinkedLinearSearch::Search(ListNode<int>* head, ListNode<int>& node, int item);
template bool LinkedLinearSearch::SearchIt(ListNode<int>* head, ListNode<int>& node, int item);