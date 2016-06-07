#include <iostream>
#include "LinkedLinearSearchTest.h"
#include "LinkedLinearSearch.h"
#include "LinkedListNode.h"
#include "LinkedBinarySearch.h"

void LinkedLinearSearchTest::DoTests()
{
   
    SearchTest();
    IterativeSearchTest();
    BinarySearchTest();
    SelfOrganizedListSearchTest();
    MoveOneAheadListSearchTest();

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
    Init();
    auto locPtr = new ListNode<int>();
    bool found = m_lLinearSearcher->Search(m_headPtr, *locPtr, 40);
    _ASSERT(found == true);
    _ASSERT(locPtr->data == 40);

    found = m_lLinearSearcher->Search(m_headPtr, *locPtr, 41);
    _ASSERT(found == false);
    cout << "Linked Linear Search Completed Succesfully" << endl;
    CleanUp();
}

void LinkedLinearSearchTest::IterativeSearchTest()
{
    Init();
    auto locPtr = new ListNode<int>();
    bool found = m_lLinearSearcher->SearchIt(m_headPtr, *locPtr, 40);
    _ASSERT(found == true);
    _ASSERT(locPtr->data == 40);
    CleanUp();
    cout << "Iterative version of Linked Linear Search completed succesfully" << endl;

}

void LinkedLinearSearchTest::BinarySearchTest()
{
    Init();
    auto blSearcher = new LinkedBinarySearch();
    auto first = m_headPtr;
    auto last = m_headPtr;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    auto loc = new ListNode<int>();
    
    auto found = blSearcher->Search(first, last, 40, *loc);
    _ASSERT(found == true);
    _ASSERT(loc->data == 40);

    found = blSearcher->Search(first, last, 41, *loc);
    _ASSERT(found == false);
    cout << "Linked Binary Search Completed Succesfully" << endl;
    CleanUp();
}

void LinkedLinearSearchTest::SelfOrganizedListSearchTest()
{
    Init();

    ListNode<int> loc;
    bool found = m_lLinearSearcher->SelfOrganizedSearch(m_headPtr, loc, 40);
    _ASSERT(found == true);
    _ASSERT(loc.data == 40);

    ListNode<int> loc2;
    bool found2 = m_lLinearSearcher->SelfOrganizedSearch(m_headPtr, loc2, 41);
    _ASSERT(found2 == false);
    _ASSERT(loc2.data != 41);

    cout << "Self Organized Linked Search Completed with success" << endl;

    CleanUp();
}

void LinkedLinearSearchTest::MoveOneAheadListSearchTest()
{
    Init();

    ListNode<int> loc;
    bool found = m_lLinearSearcher->MoveAheadOneLinkedSearch(m_headPtr, loc, 40);
    _ASSERT(found == true);
    _ASSERT(loc.data == 40);

    ListNode<int> loc2;
    bool found2 = m_lLinearSearcher->MoveAheadOneLinkedSearch(m_headPtr, loc2, 41);
    _ASSERT(found2 == false);
    _ASSERT(loc2.data != 41);

    cout << "Move Ahead one Linked Search Completed with success" << endl;

    CleanUp();

}