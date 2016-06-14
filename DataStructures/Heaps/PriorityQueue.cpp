#include "PriorityQueue.h"

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
    int parent = size / 2;

   // int parentPriority = m_vPtr->at(parent).m_priority;

    


}

template <typename T>
T MaxPriorityQueue<T>::Maximun()
{
    auto node = m_vPtr->at(0);
    return node.m_item;    
}

template MaxPriorityQueue<int>::MaxPriorityQueue();
template MaxPriorityQueue<string>::MaxPriorityQueue();
template void MaxPriorityQueue<string>::Insert(string item, int priority);
template string MaxPriorityQueue<string>::Maximun();