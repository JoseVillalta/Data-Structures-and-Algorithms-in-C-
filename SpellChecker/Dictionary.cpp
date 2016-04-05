#include "Dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

Dictionary::Dictionary()
{
    m_store = new Trie();
}

Dictionary::~Dictionary()
{
    delete m_store;
}

void Dictionary::Init(string file)
{
    ifstream fileHandle;
    fileHandle.open(file);
    string word;
    if (fileHandle.is_open())
    {
        while (getline(fileHandle, word))
        {
            m_store->InsertWord(word);
        }
    }
    else
    {
        cout << "Error could not open file" << endl;
    }
}

bool Dictionary::Search(string word)
{
    return m_store->FindWord(word);
}
