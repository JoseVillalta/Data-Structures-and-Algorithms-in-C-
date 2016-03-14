#pragma once
template<typename T>
class BSTANode
{
public:
    unsigned int m_left;
    unsigned int m_right;
    T m_data;
    bool m_isFree;
    BSTANode(int left = 0, int right = 0, T data = 0, bool isFree = true)
    {
        m_left = left;
        m_right = right;
        m_data = data;
        m_isFree = isFree;
    }

};