#include "NetworkFlowTests.h"
#include <iostream>

using namespace std;

void NetworkFlowTests::DoTests()
{
	cout << "Starting NetFlow Test" << endl;
	auto graph = new NetworkFlow();
	
	graph->insert_edge(1, 2, 5);
	graph->insert_edge(1, 5, 12);
	graph->insert_edge(2, 3, 7);
	graph->insert_edge(2, 4, 9);
	graph->insert_edge(3, 7, 5);
	graph->insert_edge(4, 5, 4);
	graph->insert_edge(4, 6, 3);
	graph->insert_edge(5, 6, 7);
	graph->insert_edge(6, 7, 2);

	graph->netflow(1, 7);

	auto e = graph->g->edges[7];

	while (e != nullptr)
	{
		cout << " Edge 7 to " << e->v << endl;
		cout << "Flow " << e->flow << " capacity " << e->capacity << " residual " << e->residual << endl;
		e = e->next;
	}

}