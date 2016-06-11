#include "SortPerformanceTest.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "TreeSort.h"
#include "MinMaxSort.h"
#include "HeapSort.h"
#include "Windows.h"
#include "TimeElapsed.h"


void SortPerformanceTest::DoTests()
{
    auto bubbleSort = new BubbleSorter();
    auto selectionSort = new SelectionSorter();
    auto insertionSort = new InsertionSorter();
    auto shellSort = new ShellSorter();
    auto treeSort = new TreeSort();
    auto minMaxSort = new MinMaxSort();
    auto heapSort = new HeapSort();

    vector<int> * v = new vector<int>();

    GetRandomVector(*v, 1000);

    cout << "***********************************" << endl;
    cout << "***START OF SORT PERFORMACE TEST***" << endl;
    cout << "***********************************" << endl;

    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    bubbleSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Bubble Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Selection Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    selectionSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Selection Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Insertion Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    insertionSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Insertion Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Shell Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    shellSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Shell Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Tree Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    treeSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Tree Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Min Max Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    minMaxSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Min Max Sort: " << ElapsedMicroseconds.QuadPart << endl;

    v->clear();

    //Heap Sort
    GetRandomVector(*v, 1000);

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);
    heapSort->Sort(*v, 0, 999);
    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds = GetTimeElapsed(StartingTime, EndingTime, Frequency);

    cout << " Elapsed Microseconds Heap Sort: " << ElapsedMicroseconds.QuadPart << endl;


    cout << "*********************************" << endl;
    cout << "END OF SORTING PERFORMANCE TEST" << endl;
    cout << "********************************" << endl;
}

void SortPerformanceTest::GetRandomVector(vector<int> & v, unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        int n = rand() % size;
        v.push_back(n);
    }
}