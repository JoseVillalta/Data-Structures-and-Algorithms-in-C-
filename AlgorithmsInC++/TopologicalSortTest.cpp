#include "TopologicalSortTest.h"

void TopoSortTest::DoTests()
{
    cout << "Topo Test" << endl;
    TestGraphWCycle();
    TestGraphWithOneValidSort();
   
}

void TopoSortTest::TestGraphWCycle()
{
    auto topoSort = new TopoLogicalSort();

    topoSort->InitGraph(true);
    topoSort->m_g->nvertices = 10;
    topoSort->InitSearch();
    topoSort->InsertEdge(1, 2, true);
    topoSort->InsertEdge(1, 4, true);

    topoSort->InsertEdge(2, 3, true);
    topoSort->InsertEdge(2, 4, true);
    topoSort->InsertEdge(2, 5, true);

    topoSort->InsertEdge(3, 6, true);

    topoSort->InsertEdge(4, 7, true);
    topoSort->InsertEdge(4, 5, true);

    topoSort->InsertEdge(5, 3, true);
    topoSort->InsertEdge(5, 6, true);
    topoSort->InsertEdge(5, 7, true);

    topoSort->InsertEdge(6, 8, true);

    topoSort->InsertEdge(7, 9, true);
    topoSort->InsertEdge(7, 6, true);

    topoSort->InsertEdge(8, 7, true);

    topoSort->InsertEdge(9, 10, true);
    topoSort->TopoSort();
}

void TopoSortTest::TestGraphWithOneValidSort()
{
    cout << "Second Topological Sort Test" << endl;
    auto graph = new TopoLogicalSort();
    graph->InitGraph(true);
    graph->m_g->nvertices = 7;

    graph->InitSearch();

    graph->InsertEdge(1, 3, true);
    graph->InsertEdge(1, 2, true);

    graph->InsertEdge(2, 4, true);
    graph->InsertEdge(2, 3, true);

    graph->InsertEdge(3, 5, true);
    graph->InsertEdge(3, 6, true);

    graph->InsertEdge(5, 4, true);
    graph->InsertEdge(6, 5, true);

    graph->InsertEdge(7, 1, true);
    cout << "Expected Values:" << endl;
    cout << "7 1 2 3 6 5 4" << endl;
    graph->TopoSort();
    cout << endl;

}

