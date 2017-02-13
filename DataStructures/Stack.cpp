#include "Stack.h"
#include <string>
using namespace std;

template <typename T>
Stack<T>::Stack()
{
    m_top = nullptr;
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

    if (m_top != nullptr)
    {
        T val = m_top->data;
        auto temp = m_top;
        m_top = m_top->prev;
        delete temp;
        return val;
    }
    else
    {
        throw - 1;
    }
    
}

template Stack<int>::Stack();
template Stack<string>::Stack();
template void Stack<int>::Push(int val);
template void Stack<string>::Push(string val);
template int Stack<int>::Pop();
template string Stack<string>::Pop();