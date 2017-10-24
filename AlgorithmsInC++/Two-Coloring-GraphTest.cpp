#include "Two-Coloring-GraphTest.h"

void TwoColoringGraphTest::DoTests()
{
    TestTwoColoring();
}

void TwoColoringGraphTest::TestTwoColoring()
{
    cout << "Two Coloring Graph Test" << endl;
    auto graph = new TwoColoring();
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
    graph->TwoColor();
    cout << "End of Two Coloring Graph Test" << endl;
}

