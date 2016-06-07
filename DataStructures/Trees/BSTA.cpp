#include "BSTA.h"
#include <iostream>
using namespace std;

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
        int index = m_memPool->GetFreeNodeIndex();
        m_root = index;
        m_nodeArray[index].m_data = val;
    }
    else
    {
        InsertAux(m_root, val);
    }
}

template<typename T>
void BSTA<T>::InsertAux(int index, T val)
{
    auto curNode = m_nodeArray[index];
    if (curNode.m_data >= val)
    {
        if (curNode.m_left == -1)
        {
            int newIndex = m_memPool->GetFreeNodeIndex();
            m_nodeArray[index].m_left = newIndex;
            m_nodeArray[newIndex].m_data = val;
        }
        else
        {
            InsertAux(curNode.m_left, val);
        }
    }
    else
    {
        if (curNode.m_right == -1)
        {
            int newIndex = m_memPool->GetFreeNodeIndex();
            m_nodeArray[index].m_right = newIndex;
            m_nodeArray[newIndex].m_data = val;
        }
        else
        {
            InsertAux(curNode.m_right, val);
        }
    }
}
template<typename T>
bool BSTA<T>::Search(T val)
{
    if (m_root == -1) return false;
    if (m_nodeArray[m_root].m_data == val) return true;

    else if (m_nodeArray[m_root].m_data > val)
    {
        return SearchAux(m_nodeArray[m_root].m_left, val);
    }
    else
    {
        return SearchAux(m_nodeArray[m_root].m_right, val);
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
        SearchAux(m_nodeArray[index].m_left, val);
    }
    else
    {
        SearchAux(m_nodeArray[index].m_right, val);
    }
}

template<typename T>
BSTA<T>::MemoryPool::MemoryPool(int size)
{
    m_freeNodeIndex = 0;
    m_freeNodeArray = new LLANode<int>[size];
    m_freeNodeArray[0] = LLANode<int>(0);
    for (int i = 1; i < size; i++)
    {
        m_freeNodeArray[i] = LLANode<int>(i);
        m_freeNodeArray[i - 1].next = i;
    }
}

template<typename T>
int BSTA<T>::MemoryPool::GetFreeNodeIndex()
{
    if (m_freeNodeIndex == -1)
    {
        //TODO: allocate more memory if we run out of space 
        cout << "*****FATAL ERROR*********" << endl;
        cout << "Memory Pool out of memory" << endl;
        exit(0);
    }

    auto index = m_freeNodeArray[m_freeNodeIndex].data;
    m_freeNodeIndex = m_freeNodeArray[m_freeNodeIndex].next;
    
    return index;
}

template<typename T>
void BSTA<T>::MemoryPool::ReleaseNode(int index)
{
    if (index >= size)
    {
        cout << "Error invalid node index when releasing BST Node" << endl;
        return;
    }

    m_freeNodeArray[index].next = m_freeNodeIndex;
    m_freeNodeIndex = index;
}

template BSTA<int>::BSTA(int size);
template void BSTA<int>::Insert(int val);
template bool BSTA<int>::Search(int val);