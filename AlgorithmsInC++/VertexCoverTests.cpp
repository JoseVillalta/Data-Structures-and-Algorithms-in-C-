#include "VertexCoverTests.h"

void VertexCoverTests::DoTests()
{
	cout << "Start of Vertex Cover Test" << endl;
	auto graph = new VertexCover();
	graph->InitGraph(false);
	graph->m_g->nvertices = 7;
	graph->InitSearch();
	graph->InsertEdge(1, 3, false);
	graph->InsertEdge(1, 2, false);
	graph->InsertEdge(2, 4, false);
	graph->InsertEdge(4, 5, false);
	graph->InsertEdge(5, 6, false);
	graph->InsertEdge(6, 7, false);

	graph->GetCover();
	cout << "End of Vertex Cover Test" << endl;
}