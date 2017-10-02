#include "stdafx.h"
#include <iostream>
#include "KrugalsMSTTest.h"
#include "KruskalsAlgorithm.h"

using namespace std;

void KrugalsMSTTest::DoTests()
{
    TestMST();
}

void KrugalsMSTTest::TestMST()
{
    cout << "Begin Krugal's Algorithm to find minimum spanning tree" << endl;
    auto graph = new KruskalsAlgorithm();
    graph->m_g->nvertices = 7;
    graph->insert_edge(1, 2, 5, false);
    graph->insert_edge(1, 3, 12, false);
    graph->insert_edge(1, 5, 7, false);
    graph->insert_edge(2, 5, 9, false);
    graph->insert_edge(2, 4, 7, false);
    graph->insert_edge(3, 6, 7, false);
    graph->insert_edge(3, 5, 4, false);
    graph->insert_edge(4, 6, 2, false);
    graph->insert_edge(4, 7, 5, false);
    graph->insert_edge(5, 6, 3, false);
    graph->insert_edge(6, 7, 2, false);
    graph->findMST();
    cout << "End of Krugal's Algorithm test" << endl;
}

