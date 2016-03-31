#pragma once
#include <string>
#include "TrieNode.h"

using namespace std;

class Trie
{
public:
    Trie(void);
    ~Trie(void);
    void InsertWord(string word);
    bool FindWord(string word);
    void TraverseTrie();
    void DisplayAllMatches(string word);
    void DeleteWord(string word);
private:
    void InsertWordAux(string word, TrieNode * node);
    bool FindWordAux(string word, TrieNode * node);
    TrieNode * m_root;
};