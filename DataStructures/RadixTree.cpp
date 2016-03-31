#include "RadixTree.h"

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