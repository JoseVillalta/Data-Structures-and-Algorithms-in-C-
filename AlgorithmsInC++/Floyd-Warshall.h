#pragma once
#include "Graph.h"
#define MAX_INT 9999

typedef struct
{
    int weight[MAXV + 1][MAXV + 1];
    int nvertices;
}adjecency_matrix;

class FloydWarshallShortestPath
{
    adjecency_matrix * g;
    void Init();
    void InsertEdget(int x, int y, int weight);
    void ComputeShortestPath();
};