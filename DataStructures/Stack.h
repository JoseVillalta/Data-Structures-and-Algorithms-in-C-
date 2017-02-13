#include "DoubleLinkedListNode.h"

template<typename T>

class Stack
{
public:
    Stack();
    void Push(T val);
    T Pop();
private:
    DListNode<T> * m_top;
};