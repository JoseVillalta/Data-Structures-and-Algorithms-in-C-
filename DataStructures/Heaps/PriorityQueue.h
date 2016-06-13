#pragma once
#include <vector>

using namespace std;

template <typename T>
class MaxPriorityQueue
{
public:
    MaxPriorityQueue();
    MaxPriorityQueue(vector<T> & v);
    void Insert(T item);
    void Delete(T item);
    void Find(T item);
    void ChangePriority(T item);
    T Maximun();
    T ExtractMax();
    void Join(MaxPriorityQueue* pq);
private:
    vector<T> * m_vPtr;
};