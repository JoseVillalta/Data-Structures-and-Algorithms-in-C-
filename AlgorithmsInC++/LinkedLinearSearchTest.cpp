#include <iostream>
#include "LinkedLinearSearchTest.h"
#include "LinkedLinearSearch.h"
#include "LinkedListNode.h"


void LinkedLinearSearchTest::DoTests()
{
    Init();
    SearchTest();
    IterativeSearchTest();
    CleanUp();

}
void LinkedLinearSearchTest::Init()
{
    m_lLinearSearcher = new LinkedLinearSearch();
    m_headPtr = new ListNode<int>(0);
    auto node = m_headPtr;
    for (int i = 1; i < 100; i++)
    {
        auto link = new ListNode<int>(i * 2);
        node->next = link;
        node = link;
    }
}

void LinkedLinearSearchTest::CleanUp()
{
    auto temp = m_headPtr;
    while (m_headPtr != nullptr)
    {
        auto temp = m_headPtr->next;
        delete m_headPtr;
        m_headPtr = temp;
    }
}

void LinkedLinearSearchTest::SearchTest()
{
    auto locPtr = new ListNode<int>();
    bool found = m_lLinearSearcher->Search(m_headPtr, *locPtr, 40);
    _ASSERT(found == true);
    _ASSERT(locPtr->data == 40);

    found = m_lLinearSearcher->Search(m_headPtr, *locPtr, 41);
    _ASSERT(found == false);
    cout << "Linked Linear Search Completed Succesfully" << endl;
}

void LinkedLinearSearchTest::IterativeSearchTest()
{
    auto locPtr = new ListNode<int>();
    bool found = m_lLinearSearcher->SearchIt(m_headPtr, *locPtr, 40);
    _ASSERT(found == true);
    _ASSERT(locPtr->data == 40);
    cout << "Iterative version of Linked Linear Search completed succesfully" << endl;

}