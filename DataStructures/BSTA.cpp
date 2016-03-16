#include "BSTA.h"

template<typename T>
BSTA<T>::BSTA(int size)
{
    m_nodeArray = new BSTANode<T>[size];
    m_memPool = new MemoryPool(size);
    m_capacity = size;
    m_root = -1;
    
}

template<typename T>
BSTA<T>::~BSTA()
{
    delete[] m_nodeArray;
}

template<typename T>
void BSTA<T>::Insert(T val)
{
    if (m_root == -1)
    {
       // m_nodeArray[m_freeNode->data].m_data = val;
       // m_root 
    }
}

template<typename T>
void BSTA<T>::InsertAux(int index, T val)
{
    
}
template<typename T>
bool BSTA<T>::Search(T val)
{
    if (m_nodeArray[0].m_data == val) return true;

    else if (m_nodeArray[0].m_data > val)
    {
        //search left
        return SearchAux(1, val);
    }
    else
    {
        //search right
        return SearchAux(2, val);
    }
}

template<typename T>
bool BSTA<T>::SearchAux(int index, T val)
{
    if (index > m_capacity) return false;

    if (index < 0) return false;

    if (m_nodeArray[index].m_data == val) return true;

    else if (m_nodeArray[index].m_data > val)
    {
        SearchAux(index * 2 + 1, val);
    }
    else
    {
        SearchAux(index * 2 + 2, val);
    }
}

template<typename T>
BSTA<T>::MemoryPool::MemoryPool(int size)
{
    m_freeNode = new ListNode<int>(0);
    for (int i = 1; i < size; i++)
    {
        m_freeNode->next = new ListNode<int>(i);
        m_freeNode = m_freeNode->next;
    }
}

template<typename T>
int BSTA<T>::MemoryPool::GetFreeNodeIndex()
{
    if (m_freeNode == nullptr)
    {
        //we could allocate more memory, 
        cout << "*****FATAL ERROR*********" << endl;
        cout << "Memory Pool out of memory" << endl;
        exit();
    }

    auto index = m_freeNode->data;
    m_freeNode = m_freeNode->next;
    
    return index;
}

template BSTA<int>::BSTA(int size);
template void BSTA<int>::Insert(int val);
template bool BSTA<int>::Search(int val);