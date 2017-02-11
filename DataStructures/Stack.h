#include "DoubleLinkedListNode.h"

template<typename T>

class Stack
{
public:
    Stack();
    void Push(T val);
    T Pop();
private:
    DListNode * m_root;
    DListNode * m_top;
};