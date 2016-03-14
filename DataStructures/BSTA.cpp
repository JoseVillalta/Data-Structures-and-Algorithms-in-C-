#include "BSTA.h"

template<typename T>
BSTA<T>::BSTA(int size)
{
    m_nodeArray = new BSTANode<T>[size];
    m_capacity = size;
}

template<typename T>
BSTA<T>::~BSTA()
{
    delete[] m_nodeArray;
}

template<typename T>
void BSTA<T>::Insert(T val)
{
    if (m_nodeArray[0].m_isFree == true)
    {
        m_nodeArray[0].m_isFree = false;
        m_nodeArray[0].m_data = val;
    }
    else
    {
        if (m_nodeArray[0].m_data > val)
        {
            //Insert left
            InsertAux(1, val);
        }
        else
        {
            //Insert right
            InsertAux(2, val);
        }
    }
}

template<typename T>
void BSTA<T>::InsertAux(int index, T val)
{
    if (index > m_capacity) return;

    if (m_nodeArray[index].m_isFree == true)
    {
        m_nodeArray[index].m_isFree = false;
        m_nodeArray[index].m_data = val;
    }
    else if (m_nodeArray[index].m_data > val)
    {
        //Insert Left
        InsertAux(index * 2 + 1, val);
    }
    else
    {
        //Insert Right
        InsertAux(index * 2 + 2, val);
    }
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

    if (m_nodeArray[index].m_isFree == true) return false;

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


template BSTA<int>::BSTA(int size);
template void BSTA<int>::Insert(int val);
template bool BSTA<int>::Search(int val);