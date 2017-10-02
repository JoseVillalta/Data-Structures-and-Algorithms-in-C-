#include "stdafx.h"
#include <iostream>
#include "DijkstrasSPTest.h"

using namespace std;
void DijkstrasSPTests::DoTests()
{
    testDSPT();
}

void DijkstrasSPTests::testDSPT()
{
    cout << "Starting Dijkstra's shortest path test" << endl;
    auto sp = new DijkstrasAlgorithm();
    sp->m_g->nvertices = 7;

    sp->insert_edge(1, 2, 5, false);
    sp->insert_edge(1, 3, 12, false);
    sp->insert_edge(1, 5, 7, false);
    sp->insert_edge(2, 5, 9, false);
    sp->insert_edge(2, 4, 7, false);
    sp->insert_edge(3, 6, 7, false);
    sp->insert_edge(3, 5, 4, false);
    sp->insert_edge(4, 6, 2, false);
    sp->insert_edge(4, 7, 5, false);
    sp->insert_edge(5, 6, 3, false);
    sp->insert_edge(6, 7, 2, false);

    sp->shortest_path(1);
    sp->print_path(1, 7);

    cout << "End of Dijkstra's Test" << endl;
}

