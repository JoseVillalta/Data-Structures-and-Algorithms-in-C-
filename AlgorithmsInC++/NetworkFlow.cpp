#include "NetworkFlow.h"
#include "algorithm"

using namespace std;

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

}

bool NetworkFlow::valid_edge(flowEdgeNode * e)
{
	if (e->residual > 0) return true;
	else return false;
}

void NetworkFlow::bfs(int source)
{

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