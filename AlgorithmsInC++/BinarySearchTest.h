#pragma once
#include "BinarySearch.h"

class BinarySearchTest
{
public:
    void DoTests(void);
private:
    void Init(void);
    void SearchInts(void);
    void SearchWBadInputs(void);
    BinarySearch * m_binarySearcher;

};

