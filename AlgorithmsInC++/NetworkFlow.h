#pragma once
#define MAXV 1000 //Maximum number of edges

typedef struct
{
    int v;
    int capacity;
    int flow;
    int residual;
    flowEdgeNode * next;

}flowEdgeNode;

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
    void add_residual_edges();
    void initialize_search();
    void bfs();
    bool valid_edge();
    void find_edge();
    void augment_path();

};