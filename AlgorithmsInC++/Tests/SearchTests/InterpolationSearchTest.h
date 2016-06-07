#pragma once
#include <vector>
#include "InterpolationSearch.h"
using namespace std;

class InterpolationSearchTest
{
public:
    void DoTests();
private:
    void TestInterpolationSearch();
    void Init();
    void Cleanup();
    vector<int> * m_vPtr;
    InterpolationSearch * m_searcher;
};

