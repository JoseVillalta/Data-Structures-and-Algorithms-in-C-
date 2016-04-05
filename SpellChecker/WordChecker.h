#pragma once
#include "Dictionary.h"
#include<vector>
#include<string>
using namespace std;
class WordChecker
{
public:
    WordChecker();
    vector<string> * ScanFile();//op
    ~WordChecker();
};

