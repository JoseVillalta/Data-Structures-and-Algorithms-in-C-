#include "AllPathsTests.h"
#include "ConstructAllPaths.h"

using namespace std;

void AllPathsTests::DoTests()
{
    AllPathTest();
}

void AllPathsTests::AllPathTest()
{
    cout << "All Paths in a graph test" << endl;

    auto g = new Graph();
    g->nvertices = 6;
	

    InsertEdge(g, 1, 2, false);
    InsertEdge(g, 1, 3, false);
    InsertEdge(g, 1, 4, false);
    InsertEdge(g, 1, 5, false);
    InsertEdge(g, 2, 6, false);
    InsertEdge(g, 3, 6, false);
    InsertEdge(g, 4, 6, false);
    InsertEdge(g, 5, 6, false);
    InsertEdge(g, 3, 4, false);


    auto ap = PathBuilder();
    int result = ap.GetAllPaths(g, 1, 3);
    cout << " Number of paths from 1 to 3 is: " << result << endl;
}

void AllPathsTests::InsertEdge(Graph* g, int x, int y, bool directed)
{
    auto node = new edgenode();
    node->y = y;
    node->next = g->edges[x];
    g->edges[x] = node;

    if (!directed)
    {
        InsertEdge(g, y, x, true);
    }
}


