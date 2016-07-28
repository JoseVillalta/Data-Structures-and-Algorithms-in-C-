#pragma once
#include "EdgeNode.h"
#define MAXV 1000 //Maximum number of edges


typedef struct
{
    edgenode * edges[MAXV + 1];     //adjacency info
    int degree[MAXV + 1];           //outdegree of each vertex
    int nvertices;                  //number of vertices in graph
    int nedges;                     //number of edges in graph
    bool directed;                  //is the graph directed
}Graph;