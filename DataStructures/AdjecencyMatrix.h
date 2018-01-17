#pragma once
#define MAXV 1000 //Maximum number of edges


typedef struct
{
	int** matrix[MAXV];             //outdegree of each vertex
	int nvertices;                  //number of vertices in graph
	int nedges;                     //number of edges in graph
	bool directed;                  //is the graph directed
}MatrixGraph;