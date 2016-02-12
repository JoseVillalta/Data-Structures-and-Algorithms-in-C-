#pragma once
#include "BinarySearch.h"

class BinarySearchTest
{
public:
    void DoTest(void);
private:
    void Init(void);
    void SearchInts(void);
    void SearchWBadInputs(void);
    BinarySearch * m_binarySearcher;

};

