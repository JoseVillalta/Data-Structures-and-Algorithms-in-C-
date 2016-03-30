#pragma once
#define MAX_SIZE 256 

class TrieNode
{
public: 
    TrieNode ** m_nodeArray;
    bool isWordFlag;
    void Init()
    {
        m_nodeArray = new TrieNode*[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++)
        {
            m_nodeArray[i] = nullptr;
        }
    }

};