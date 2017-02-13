#include "Queue.h"

using namespace std;
template<typename T>
Queue<T>::Queue()
{
    m_first = m_last = nullptr;
}

template<typename T>
void Queue<T>::Push(T val)
{
    auto node = new DListNode<T>();
    node->data = val;

    if (m_last == nullptr)
    {
        m_last = m_first = node;
    }
    else
    {
        m_last->next = node;
        node->prev = m_last;
        m_last = node;
    }
}

template<typename T>
T Queue<T>::Pop()
{
    if (m_first == nullptr)
    {
        throw - 1;
    }
    T val = m_first->data;
    auto temp = m_first;
    m_first->next->prev = nullptr;
    m_first = m_first->next;
    delete temp;
    return val;
}

template Queue<int>::Queue();
template Queue<string>::Queue();
template int Queue<int>::Pop();
template string Queue<string>::Pop();
template void Queue<int>::Push(int val);
template void Queue<string>::Push(string val);