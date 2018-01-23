#pragma once
#define MAXV 1000 //Maximum number of edges

struct flowEdgeNode
{
    int v;
    int capacity;
    int flow;
    int residual;
    flowEdgeNode * next;

};

typedef struct
{
    flowEdgeNode * edges[MAXV + 1];     //adjacency info
    int degree[MAXV + 1];           //outdegree of each vertex
    int nvertices;                  //number of vertices in graph
    int nedges;                     //number of edges in graph
    bool directed;                  //is the graph directed
}NetGraph;

class NetworkFlow
{
public:
    NetGraph * g;
	int parents[MAXV];
    void add_residual_edges();
    void initialize_search();
    void bfs(int);
    bool valid_edge(flowEdgeNode * e);
    flowEdgeNode * find_edge(int,int);
    void augment_path(int,int,int);
	void netflow(int, int);
	int path_volume(int, int);

};