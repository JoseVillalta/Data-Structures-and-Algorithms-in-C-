#pragma once
#define DEFAULT_SIZE 256
#include "BSTANode.h"
#include "LinkedListNode.h"

template<typename T>
class BSTA
{
public:
    BSTA(int size = DEFAULT_SIZE);
    void Insert(T val);
    bool Search(T val);
    void Delete(T val);
    ~BSTA();
private:
    int m_capacity;
    int m_root;
    void InsertAux(int index, T val);
    bool SearchAux(int index, T val);
    BSTANode<T> * m_nodeArray;

    class MemoryPool {
    public:
        MemoryPool(int size = DEFAULT_SIZE);
        int GetFreeNodeIndex();
        void ReleaseNode(int index);
    private:
        ListNode<int> * m_freeNode;
    };

    MemoryPool * m_memPool;
};

