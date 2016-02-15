#include <iostream>
#include "LinkedLinearSearchTest.h"
#include "LinkedLinearSearch.h"
#include "LinkedListNode.h"


void LinkedLinearSearchTest::DoTests()
{
    auto headPtr = new ListNode<int>(0);
    auto node = headPtr;
    for (int i = 1; i < 100; i++)
    {
        auto link = new ListNode<int>(i * 2);
        node->next = link;
        node = link;
    }

    auto locPtr = new ListNode<int>();
    auto llsearcher = new LinkedLinearSearch();
    bool found = llsearcher->Search(headPtr, *locPtr, 40);
    _ASSERT(found == true);
    _ASSERT(locPtr->data == 40);

    found = llsearcher->Search(headPtr, *locPtr, 41);
    _ASSERT(found == false);
    cout << "Linked Linear Search Completed Succesfully" << endl;

}