#pragma once
#define DEFAULT_SIZE 256
#include "BSTANode.h"

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
    int nodeCount;
    void ReallocateMem();
    void InsertAux(int index, T val);
    bool SearchAux(int index, T val);
    BSTANode<T> * m_nodeArray;

};

