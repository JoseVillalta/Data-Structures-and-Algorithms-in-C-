#include "DoubleLinkedListNode.h"
#include <string>

template<typename T>

class Queue
{
public:
    Queue();
    void Push(T val);
    T Pop();
private:
    DListNode<T> * m_first;
    DListNode<T> * m_last;

};