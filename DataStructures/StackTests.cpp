#pragma
#include "StackTests.h"
#include <iostream>

using namespace std;

void StackTests::DoTests()
{
    cout << "Stack Tests" << endl;
    PushPopTest();
    PushPopStringsTest();
}

void StackTests::PushPopTest()
{
    Stack<int> stack;
    stack.Push(13);
    stack.Push(5);
    stack.Push(2);

    auto val = stack.Pop();
    _ASSERT(val == 2);
    val = stack.Pop();
    _ASSERT(val == 5);
    stack.Push(15);
    val = stack.Pop();
    _ASSERT(val == 15);
    val = stack.Pop();
    _ASSERT(val == 13);

    try
    {
        stack.Pop();// Should throw stack is empty
    }
    catch (int e)
    {
        cout << "Exception thrown, as expected" << endl;
    }
    
    cout << "Stack test successfull" << endl;
}

void StackTests::PushPopStringsTest()
{
    Stack<string> stack;
    stack.Push("My");
    stack.Push("Little");
    stack.Push("Stack");
    stack.Push("is");
    stack.Push("so");
    stack.Push("Awesome");

    auto val = stack.Pop();
    _ASSERT(val == "Awesome");
    val = stack.Pop();
    _ASSERT(val == "so");
    val = stack.Pop();
    _ASSERT(val == "is");
    val = stack.Pop();
    _ASSERT(val == "Stack");
    val = stack.Pop();
    _ASSERT(val == "Little");
    stack.Push("YO!");
    val = stack.Pop();
    _ASSERT(val == "YO!");
    val = stack.Pop();
    _ASSERT(val == "My");

    try
    {
        stack.Pop();//stack is empty
    }
    catch (int e)
    {
        cout << "Execption thrown, as expected" << endl;
    }
    cout << "Stacks with string completed successfully" << endl;
}