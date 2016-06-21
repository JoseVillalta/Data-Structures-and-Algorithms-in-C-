#pragma once
#include "PQNode.h"
#include <vector>

using namespace std;

template <typename T>
class MaxPriorityQueue
{
public:
    MaxPriorityQueue();
    MaxPriorityQueue(vector<PQNode<T>> & v);
    void Insert(T item, int priority);
    void Delete(T item, int priority);
    int Find(T item, int priority);
    void ChangePriority(T item, int oldPriority, int newPriority);
    T Maximun();
    T ExtractMax();
    void Join(MaxPriorityQueue* pq);
private:
    vector<PQNode<T>> * m_vPtr;
    void Remove(int index);
};