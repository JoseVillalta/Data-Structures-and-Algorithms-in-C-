#include "PriorityQueue.h"
#include "swap.h"

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue()
{
    m_vPtr = new vector<PQNode<T>>();
}

template <typename T>
void MaxPriorityQueue<T>::Insert(T item, int priority)
{
    PQNode<T> node;
    node.m_item = item;
    node.m_priority = priority;
    m_vPtr->push_back(node);

    int size = m_vPtr->size();
    int loc = size - 1;
    int parent = (size/2) -1 ;

    while (parent >= 0)
    {
        int parentPriority = m_vPtr->at(parent).m_priority;

        if (priority > parentPriority)
        {
            swap(*m_vPtr, parent, loc);
        }
        parent = (parent / 2) - 1;
    }
}

template <typename T>
T MaxPriorityQueue<T>::Maximun()
{
    auto node = m_vPtr->at(0);
    return node.m_item;    
}

template <typename T>
void MaxPriorityQueue<T>::Delete(T item, int priority)
{

}

template <typename T>
T MaxPriorityQueue<T>::ExtractMax()
{
    auto node = m_vPtr->at(0);

    int last = m_vPtr->size() - 1;
    swap(*m_vPtr, 0, last);
    m_vPtr->pop_back();
    last--;

    int pos = 0;
    int child = 1;
    while (child <= last)
    {
        if (child + 1 <= last)
        {
            if (m_vPtr->at(child).m_priority < m_vPtr->at(child+1).m_priority)
            {
                child++;
            }
        }
        if (m_vPtr->at(pos).m_priority < m_vPtr->at(child).m_priority)
        {
            swap(*m_vPtr, pos, child);
        }

        pos = child;
        child = child * 2 + 1;
    }
    
    return node.m_item;

}

template MaxPriorityQueue<int>::MaxPriorityQueue();
template MaxPriorityQueue<string>::MaxPriorityQueue();
template void MaxPriorityQueue<string>::Insert(string item, int priority);
template string MaxPriorityQueue<string>::Maximun();
template string MaxPriorityQueue<string>::ExtractMax();
template void MaxPriorityQueue<string>::Delete(string item, int priority);