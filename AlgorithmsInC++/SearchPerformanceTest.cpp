#include <vector>
#include <iostream>
#include "SearchPerformanceTest.h"
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "LinkedLinearSearch.h"
#include "InterpolationSearch.h"
#include "Windows.h"

using namespace std;

void SearchPerformanceTest::DoTests()
{
    CompareBinaryWithLinearSearch();
    CompareLinearWithSelfOrganizingList();
    CompareLinkedSearchWithSelfOrganizingListSearch();
}
void SearchPerformanceTest::CompareBinaryWithLinearSearch()
{
    auto linearSearcher = new LinearSearch();
    auto binarySearcher = new BinarySearch();
    auto interpolationSearcher = new InterpolationSearch();

    //create vector with 1M values
    vector<int> vector;
    for (int i = 0; i < 1000000; i++)
    {
        vector.push_back(i * 2);
    }

    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;
    int loc = 0;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    auto found = linearSearcher->Search(vector, 488800, loc);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Linear Search: " << ElapsedMicroseconds.QuadPart << endl;

    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = linearSearcher->Search(vector, 488801, loc);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Linear Search: " << ElapsedMicroseconds.QuadPart << endl;

    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = binarySearcher->Search(vector, loc, 488800, 0, 1000000);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Binary Search: " << ElapsedMicroseconds.QuadPart << endl;

    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = binarySearcher->Search(vector, loc, 488801, 0, 1000000);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Binary Search: " << ElapsedMicroseconds.QuadPart << endl;


    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = interpolationSearcher->Search(vector, loc, 488800);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Interpolation Search: " << ElapsedMicroseconds.QuadPart << endl;
    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = interpolationSearcher->Search(vector, loc, 488801);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: " << loc << " Elapsed Microseconds Interpolation Search: " << ElapsedMicroseconds.QuadPart << endl;
}

void SearchPerformanceTest::CompareLinearWithSelfOrganizingList()
{
    vector<int> v;
    vector<int> v2;

    for (int i = 0; i < 100; i++)
    {
        int n = rand() % 100;
        v.push_back(n);
        v2.push_back(n);
    }

    vector<int> v3;
    for (int i = 0; i < 10000; i++)
    {
        int n = rand() % 100;
        v3.push_back(n);
    }

    auto searcher = new LinearSearch();
    int loc = 0;
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;
    

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    for (auto i : v3)
    {
        searcher->Search(v, i, loc);
    }
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
    cout << "Linear Search Took: " << ElapsedMicroseconds.QuadPart << " microseconds" << endl;

    QueryPerformanceCounter(&StartingTime);
    for (auto i : v3)
    {
        searcher->SelfOrganizingListSearch(v2, i, loc);
    }
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
    cout << "Self Organized Search Took: " << ElapsedMicroseconds.QuadPart << " microseconds" << endl;

}

void SearchPerformanceTest::CompareLinkedSearchWithSelfOrganizingListSearch()
{
    //init two identical linked list
    auto node1 = new ListNode<int>();
    auto node2 = new ListNode<int>();

    auto listHead1 = node1;
    auto listHead2 = node2;

    for (int i = 0; i < 100; i++)
    {
        int n = rand() % 100;
        auto n1 = new ListNode<int>(n);
        auto n2 = new ListNode<int>(n);

        node1->next = n1;
        node2->next = n2;
        node1 = n1;
        node2 = n2;       
    }

    //search vector
    vector<int> v3;
    for (int i = 0; i < 10000; i++)
    {
        int n = rand() % 100;
        v3.push_back(n);
    }
    auto linkedSearch = new LinkedLinearSearch();

    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;
    ListNode<int> loc;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    for (auto i : v3)
    {
        linkedSearch->Search(listHead1, loc, i);
    }
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
    cout << "Linked List Linear Search Took: " << ElapsedMicroseconds.QuadPart << " microseconds" << endl;

    QueryPerformanceCounter(&StartingTime);
    for (auto i : v3)
    {
        linkedSearch->SelfOrganizedSearch(listHead2, loc, i);
    }
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);
    cout << "Self Organized Search Took: " << ElapsedMicroseconds.QuadPart << " microseconds" << endl;



}

LARGE_INTEGER SearchPerformanceTest::GetTimeElapsed(LARGE_INTEGER startTime, LARGE_INTEGER endTime, LARGE_INTEGER freq)
{
    LARGE_INTEGER elapsedTime;
    elapsedTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
    elapsedTime.QuadPart *= 1000000;
    elapsedTime.QuadPart /= freq.QuadPart;
    return elapsedTime;

}
