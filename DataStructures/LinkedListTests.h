#pragma once

#include "LinkedListNode.h"
#include <iostream>

using namespace std;

class LinkedListTests
{
public:
    void DoTests();
private:
    ListNode<int> *  ReverseList(ListNode<int> * head);
    void TestReverseList();
};