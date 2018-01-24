#include "NetworkFlow.h"
#include "algorithm"
#include <queue>

using namespace std;

NetworkFlow::NetworkFlow()
{
	g = new NetGraph();
}

void NetworkFlow::netflow(int source, int sink)
{
	int volume;
	add_residual_edges();
	initialize_search();
	bfs(source);

	volume = path_volume(source, sink);

	while (volume > 0)
	{
		augment_path(source, sink, volume);
		initialize_search();
		bfs(source);
		volume = path_volume(source, sink);
	}
}

void NetworkFlow::add_residual_edges()
{

}

void NetworkFlow::augment_path(int start, int end,int volume)
{
	flowEdgeNode * e;
	if (start == end) return;
	e = find_edge(parents[end], end);
	e->flow += volume;
	e->residual -= volume;
	e = find_edge(end, parents[end]);
	e->residual += volume;
	augment_path(start, parents[end], volume);
}


flowEdgeNode * NetworkFlow::find_edge(int x, int y)
{
	flowEdgeNode * p;

	p = g->edges[x];
	while (p != nullptr)
	{
		if (p->v == y) return p;
		p = p->next;
	}

	return nullptr;
}

void NetworkFlow::initialize_search()
{
	for (int i = 0; i < MAXV; i++)
	{
		discovered[i] = false;
		processed[i] = false;
		parents[i] = -1;
	}
}

bool NetworkFlow::valid_edge(flowEdgeNode * e)
{
	if (e->residual > 0) return true;
	else return false;
}

void NetworkFlow::bfs(int source)
{
	queue<int> q;
	q.push(source);
	discovered[source] = true;

	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		auto edge = g->edges[p];
		while (edge != nullptr)
		{
			int y = edge->v;
			if (discovered[y] == false && edge->residual > 0)
			{
				parents[y] = p;
				discovered[y] = true;
				q.push(y);
			}
			edge = edge->next;
		}
	}
}

int NetworkFlow::path_volume(int start, int end)
{
	flowEdgeNode * e;
	if (parents[end] == -1) return 0;
	e = find_edge(parents[end], end);
	if (start == parents[end])
		return e->residual;
	else
		return min(path_volume(start, parents[end]), e->residual);
}

void NetworkFlow::insert_edge(int x, int y, int cap)
{
	auto e = new flowEdgeNode();
	e->v = y;
	e->capacity = cap;
	e->residual = cap;
	e->flow = 0;
	e->next = g->edges[x];
	g->edges[x] = e;

	// Reverse Edge as well
	auto e2 = new flowEdgeNode();
	e2->v = x;
	e2->capacity = cap;
	e2->residual = 0;
	e2->flow = 0;
	e2->next = g->edges[y];
	g->edges[y] = e2;

}