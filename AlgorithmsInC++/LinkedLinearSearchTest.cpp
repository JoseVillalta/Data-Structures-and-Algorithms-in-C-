#include "LinkedLinearSearchTest.h"
#include "LinkedListNode.h"


void LinkedLinearSearchTest::DoTest()
{
    auto headPtr = new ListNode<int>(0);
    auto node = headPtr;
    for (int i = 1; i < 100; i++)
    {
        auto link = new ListNode<int>(i * 2);
        node->next = link;
        node = link;
    }

}