#include "QueueTests.h"
#include <iostream>

using namespace std;

void QueueTests::DoTests()
{
    cout << "Queue Tests start" << endl;
    PushPopTests();
    PushPopStringsTest();
}

void QueueTests::PushPopTests()
{
    Queue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    auto val = q.Pop();
    _ASSERT(val == 1);
    q.Push(4);
    val = q.Pop();
    _ASSERT(val == 2);
    val = q.Pop();
    _ASSERT(val == 3);
    val = q.Pop();
    _ASSERT(val == 4);
    try
    {
        q.Pop();
    }
    catch (int e)
    {
        cout << "Execption thrown when empty queue is dequed, as expected" << endl;
    }

    cout << "Queue Test successful" << endl;
}

void QueueTests::PushPopStringsTest()
{
    Queue<string> q;
    q.Push("Please");
    q.Push("get");
    q.Push("in");
    q.Push("the");
    q.Push("Queue");
    auto val = q.Pop();
    _ASSERT(val == "Please");
    val = q.Pop();
    _ASSERT(val == "get");
    val = q.Pop();
    _ASSERT(val == "in");
    val = q.Pop();
    _ASSERT(val == "the");
    val = q.Pop();
    _ASSERT(val == "Queue");

    try
    {
        q.Pop();
    }
    catch (int e)
    {
        _ASSERT(e == -1);
        cout << "Exception Thrown, as expected" << endl;
    }

    cout << "Queue of string test passed" << endl;
}