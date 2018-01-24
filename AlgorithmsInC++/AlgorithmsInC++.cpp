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
#include "TreeSortTest.h"
#include "InsertionSortTest.h"
#include "SortPerformanceTest.h"
#include "HeapSortTest.h"
#include "QuickSortTest.h"
#include "MergeSortTest.h"
#include "CountingSortTest.h"
#include "RadixSortTest.h"
#include "BFSTest.h"
#include "DFSTest.h"
#include "TopologicalSortTest.h"
#include "MSTTest.h"
#include "KrugalsMSTTest.h"
#include "DijkstrasSPTest.h"
#include "AllSubsetsTests.h"
#include "Two-Coloring-GraphTest.h"
#include "AllPermutationsTest.h"
#include "MultiSetTests.h"
#include "AllPathsTests.h"
#include "VertexCoverTests.h"
#include "NetworkFlowTests.h"

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
    auto tst = new TreeSortTest();
    auto insertionSortTest = new InsertionSortTest();
    auto sortPerformance = new SortPerformanceTest();
    auto heapSortTest = new HeapSortTest();
    auto quickSortTest = new QuickSortTest();
    auto mergeSortTest = new MergeSortTest();
    auto countingSortTest = new CountingSortTest();
    auto radixSortTest = new RadixSortTest();
    auto breadFirstSearchTest = new BFSTests();
    auto depthFirstSearchTest = new DFSTest();
    auto topoSortTest = new TopoSortTest();
    auto primTest = new PrimTest();
    auto krugalTest = new KrugalsMSTTest();
    auto shortestPathTest = new DijkstrasSPTests();
    auto allSubsets = new AllSubSetsTests();
    auto twoColoring = new TwoColoringGraphTest();
    auto allPerms = new AllPermutationsTest();
    auto multiSet = new MultiSetsTest();
    auto allPaths = new AllPathsTests();
	auto vertexCover = new VertexCoverTests();
	auto netflow = new NetworkFlowTests();

    lst->DoTests();
    bst->DoTests();
 //   spt->DoTests();
    llst->DoTests();
    ist->DoTests();
    sst->DoTests();
    mst->DoTests(); 
    bbt->DoTests();
    sht->DoTests();
    tst->DoTests();

    insertionSortTest->DoTests();
   // sortPerformance->DoTests();
    heapSortTest->DoTests();
    quickSortTest->DoTests();
    mergeSortTest->DoTests();
    countingSortTest->DoTests();
    radixSortTest->DoTests();
    breadFirstSearchTest->DoTests();
    depthFirstSearchTest->DoTests();
    topoSortTest->DoTests();
    primTest->DoTests();
    krugalTest->DoTests();
    shortestPathTest->DoTests();
    allSubsets->DoTests();
    twoColoring->DoTests();
    allPerms->DoTests();
    multiSet->DoTests();
    allPaths->DoTests();
	vertexCover->DoTests();
	netflow->DoTests();
    return 0;
}

