#include "Two-Coloring-GraphTest.h"

void TwoColoringGraphTest::DoTests()
{
    TestTwoColoring();
    TestBiparteGraph();
}

void TwoColoringGraphTest::TestTwoColoring()
{
    cout <<endl<< "Two Coloring Graph Test" << endl;
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

void TwoColoringGraphTest::TestBiparteGraph()
{
    cout << endl << "Second Test of Coloring Graph" << endl;
    auto graph = new TwoColoring();
    graph->InitGraph(false);
    graph->m_g->nvertices = 7;

    graph->InsertEdge(1, 2, false);
    graph->InsertEdge(1, 4, false);

    graph->InsertEdge(2, 4, false);
    graph->InsertEdge(2, 3, false);

    graph->InsertEdge(3, 5, false);
    graph->InsertEdge(3, 6, false);

    graph->InsertEdge(4, 5, false);
    graph->InsertEdge(4, 7, false);

    graph->InsertEdge(5, 6, false);
    graph->InsertEdge(5, 7, false);

    graph->TwoColor();
    cout << endl << "End of two color test" << endl;
}
