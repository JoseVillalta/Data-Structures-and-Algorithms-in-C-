#include <vector>
#include <iostream>
#include "SearchPerformanceTest.h"
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "Windows.h"

using namespace std;

void SearchPerformanceTest::DoTests()
{
    auto linearSearcher = new LinearSearch();
    auto binarySearcher = new BinarySearch();

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

    cout << "Index is: "<<loc<<" Elapsed Microseconds Linear Search: " << ElapsedMicroseconds.QuadPart << endl;

    loc = 0;
    QueryPerformanceCounter(&StartingTime);
    found = binarySearcher->Search(vector, loc, 488800, 0, 1000000);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << "Index is: "<<loc<<" Elapsed Microseconds Binary Search: " << ElapsedMicroseconds.QuadPart << endl;   
}

LARGE_INTEGER SearchPerformanceTest::GetTimeElapsed(LARGE_INTEGER startTime, LARGE_INTEGER endTime, LARGE_INTEGER freq)
{
    LARGE_INTEGER elapsedTime;
    elapsedTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
    elapsedTime.QuadPart *= 1000000;
    elapsedTime.QuadPart /= freq.QuadPart;
    return elapsedTime;

}
