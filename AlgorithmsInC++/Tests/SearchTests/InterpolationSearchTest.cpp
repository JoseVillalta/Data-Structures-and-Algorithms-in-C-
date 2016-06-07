#include "InterpolationSearchTest.h"
#include <iostream>
using namespace std;

void InterpolationSearchTest::DoTests()
{
    Init();
    TestInterpolationSearch();
    Cleanup();
}

void InterpolationSearchTest::Init()
{
    m_searcher = new InterpolationSearch();
    m_vPtr = new vector<int>();

    for (int i = 0; i < 100; i++)
    {
        m_vPtr->push_back(i * 2);
    }
}

void InterpolationSearchTest::Cleanup()
{
    delete m_searcher;
    delete m_vPtr;
}

void InterpolationSearchTest::TestInterpolationSearch()
{
    int loc = 0;
    bool found = m_searcher->Search(*m_vPtr, loc, 60);
    _ASSERT(found == true);
    _ASSERT(m_vPtr->at(loc) == 60);
    int loc2 = 0;
    bool noFound = m_searcher->Search(*m_vPtr, loc2, 61);
    _ASSERT(noFound == false);
    _ASSERT(loc2 == 0);
    cout << "Interpolation Test was successful" << endl;
}

