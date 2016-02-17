#pragma once
#include "LinkedListNode.h"
#include "LinkedLinearSearch.h"

using namespace std;
class LinkedLinearSearchTest
{
public:
    void DoTests();
    void Init();
    void CleanUp();
    void SearchTest();
    void IterativeSearchTest();
    void BinarySearchTest();
private:
    ListNode<int> * m_headPtr;
    LinkedLinearSearch * m_lLinearSearcher;
    
};

