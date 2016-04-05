#pragma once
#include<string>
#include<iostream>
#include "RadixTree.h"

using namespace std;
class Dictionary
{
public:
    Dictionary();
    void Init(string file); 
    bool Search(string word);
    ~Dictionary();
private:
    Trie *m_store;
};

