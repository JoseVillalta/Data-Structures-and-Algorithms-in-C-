#pragma once
template<typename T>
class LLANode
{
public:
    int next;
    T data;
    LLANode(T val = 0, int nextIndex = -1)
    {
        next = nextIndex;
        data = val;
    }
};