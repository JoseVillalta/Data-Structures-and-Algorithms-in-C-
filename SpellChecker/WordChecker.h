#pragma once
#include "Dictionary.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;
class WordChecker
{
public:
    WordChecker(Dictionary * dic);
    vector<string> * ScanFile(string file);
    ~WordChecker();
private:
    Dictionary * m_dictionary;
};

