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
    void Delete(T item);
    void Find(T item);
    void ChangePriority(T item);
    T Maximun();
    T ExtractMax();
    void Join(MaxPriorityQueue* pq);
private:
    vector<PQNode<T>> * m_vPtr;
};