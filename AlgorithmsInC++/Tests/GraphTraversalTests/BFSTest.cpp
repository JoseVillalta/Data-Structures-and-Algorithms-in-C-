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
}