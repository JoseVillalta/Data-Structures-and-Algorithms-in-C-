#pragma once
#include "Windows.h"
class SearchPerformanceTest
{
public:
    void DoTests(void);
    void CompareBinaryWithLinearSearch();
    void CompareLinearWithSelfOrganizingList();
    void CompareLinkedSearchWithSelfOrganizingListSearch();
};

