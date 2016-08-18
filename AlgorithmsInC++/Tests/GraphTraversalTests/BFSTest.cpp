#include "BFSTest.h"

void BFSTests::DoTests()
{
    InitAndPrintTest();
}

void BFSTests::InitAndPrintTest()
{
    auto bfs = new BFS();
    bfs->InitGraph(true);
    bfs->InsertEdge(1, 2, true);
    bfs->InsertEdge(1, 4, true);
    bfs->InsertEdge(2, 3, true);
    bfs->InsertEdge(3, 5, true);
    bfs->InsertEdge(4, 5, true);
    bfs->m_g->nvertices = 5;
    bfs->PrintGraph();
    bfs->InitSearch();
    bfs->BreadthFirstSearch(1);
    cout << "Find Path from 1 to 3" << endl;
    bfs->FindPath(1, 3);
    cout << endl;
}