#include "LinkedListTests.h"

void LinkedListTests::DoTests()
{
    cout << "**************************" << endl;
    cout << " Linked List Test " << endl;
    TestReverseList();

}

void LinkedListTests::TestReverseList()
{
    auto head = new ListNode<int>(1);
    auto curr = head;
    for (int i = 2; i <= 10; i++)
    {
        curr->next = new ListNode<int>(i);
        curr = curr->next;
    }
    curr = head;
    int j = 1;
    while (curr != nullptr)
    {
        
        _ASSERT(curr->data == j);
        cout << curr->data << " , ";
        curr = curr->next;
        j++;
    }

    cout << endl << "Reversing List" << endl;
    curr = ReverseList(head);

    int n = 10;
    while (curr != nullptr)
    {
        _ASSERT(curr->data == n);
        cout << curr->data << " , ";
        curr = curr->next;
        n--;
    }
    cout << endl;

}
ListNode<int> * LinkedListTests::ReverseList(ListNode<int> * head)
{
    if (head == nullptr) return head;
    auto temp = head->next;
    head->next = NULL;

    while (temp != nullptr)
    {
        auto temp2 = temp->next;
        temp->next = head;
        head = temp;
        temp = temp2;
    }

    return head;
}
