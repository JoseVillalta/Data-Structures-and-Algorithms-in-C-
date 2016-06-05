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
#include "BubbleSortTest.h"
#include "ShellSortTest.h"

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
    auto bbt = new BubbleSortTest();
    auto sht = new ShellSortTest();
    lst->DoTests();
    bst->DoTests();
   // spt->DoTests();
    llst->DoTests();
    ist->DoTests();
    sst->DoTests();
    mst->DoTests(); 
    bbt->DoTests();
    sht->DoTests();
    return 0;
}

