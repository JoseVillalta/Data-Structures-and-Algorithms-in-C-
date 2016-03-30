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
    TrieNode * m_root;
};