#pragma once
template<typename T>
class BSTANode
{
public:
    int m_left;
    int m_right;
    T m_data;
    BSTANode(int left = -1, int right = -1, T data = 0)
    {
        m_left = left;
        m_right = right;
        m_data = data;
    }

};