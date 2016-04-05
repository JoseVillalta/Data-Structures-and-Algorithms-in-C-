#include "RadixTree.h"
#include <iostream>

using namespace std;
Trie::Trie()
{
    m_root = new TrieNode();
    m_root->Init();
}

void Trie::InsertWord(string word)
{
    InsertWordAux(word, m_root);
}

void Trie::InsertWordAux(string word, TrieNode * node)
{
    if (word.empty()) return;

    char c = word.at(0);
    auto nextNode = node->m_nodeArray[(int)c];
    if (nextNode == nullptr)
    {
        nextNode = new TrieNode();
        nextNode->Init();
        node->m_nodeArray[(int)c] = nextNode;
    }
    if (word.size() == 1)
    {
        nextNode->isWordFlag = true;
        return;
    }
    else
    {
        string next_word = word.substr(1, word.size() - 1);
        InsertWordAux(next_word, nextNode);
    }

}

bool Trie::FindWord(string word)
{
    return FindWordAux(word,m_root);
}

bool Trie::FindWordAux(string word, TrieNode * node)
{
    if (word.empty()) return false;

    char c = word.at(0);
    auto nextNode = node->m_nodeArray[(int)c];
    if (nextNode == nullptr) return false;
    else
    {
        if (word.size() == 1) return true;
        else
        {
            string nextWord = word.substr(1, word.size() - 1);
            return FindWordAux(nextWord, nextNode);
        }        
    }
}

void Trie::DisplayAllMatches(string word)
{
    if (word.empty()) return;

    auto node = FindLastMatchingNode(word, m_root);
    DisplayAllMatchesAux(word, node);
}

void Trie::DisplayAllMatchesAux(string word, TrieNode * node)
{
    if (node->isWordFlag)
    {
        cout << word << endl;
    }

    for (int i = 0; i < 256; i++)
    {
        if (node->m_nodeArray[i] != nullptr)
        {
            char c = (char)i;
            word.push_back(c);
            DisplayAllMatchesAux(word, node->m_nodeArray[i]);
            word.pop_back();
        }
    }
}

TrieNode * Trie::FindLastMatchingNode(string word, TrieNode * node)
{
    if (word.empty()) return node;
    char c = word.at(0);
    if (node->m_nodeArray[(int)c] == nullptr) return node;
    else
    {
        auto next_word = word.substr(1, word.size() - 1);
        return FindLastMatchingNode(next_word, node->m_nodeArray[(int)c]);
    }
}