#include "Stack.h"


template <typename T>
Stack<T>::Stack()
{
    m_root = m_top = nullptr;
}

template<typename T>
void Stack<T>::Push(T val)
{
    auto node = new DListNode<T>(val);

    if (m_top != nullptr)
    {
        m_top->next = node;
    }
    node->prev = m_top;
    m_top = node;
}

template<typename T>
T Stack<T>::Pop()
{
    T val = m_top->val;
    auto temp = m_top;
    m_top = m_top->prev;
    delete temp;
    return val;
}