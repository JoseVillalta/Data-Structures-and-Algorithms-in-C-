#include "DFSTest.h"

void DFSTest::DoTests()
{
    InitAndPrintTest();
}
void DFSTest::InitAndPrintTest()
{
    auto dfs = new DFS();
    dfs->InitGraph(false);
    dfs->InitSearch();
    dfs->InsertEdge(1, 6, false);
    dfs->InsertEdge(1, 2, false);
    dfs->InsertEdge(1, 2, false);
    dfs->InsertEdge(2, 5, false);
    dfs->InsertEdge(2, 3, false);
    dfs->InsertEdge(3, 4, false);
    dfs->InsertEdge(4, 5, false);
    dfs->m_g->nvertices = 6;
    dfs->DepthFirstSearch(1);

}