// AlgorithmsInC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinearSearchTests.h"
#include "BinarySearchTest.h"
#include "SearchPerformanceTest.h"
#include "LinkedLinearSearchTest.h"
#include "InterpolationSearchTest.h"
#include "SelectionSortTest.h"
#include "MinMaxSortTest.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

    auto lst = new LinearSearchTest();
    auto bst = new BinarySearchTest();
    auto spt = new SearchPerformanceTest();
    auto llst = new LinkedLinearSearchTest();
    auto ist = new InterpolationSearchTest();
    auto sst = new SelectionSortTest();
    auto mst = new MinMaxSortTest();
    lst->DoTests();
    bst->DoTests();
    spt->DoTests();
    llst->DoTests();
    ist->DoTests();
    sst->DoTests();
    //mst->DoTests(); Min Max is not done. 
    return 0;
}

