#pragma once
#include<iostream>
#include "Graph.h"
#include "EdgeNode.h"

using namespace std;
class BFS
{
public:
    Graph * m_g;
    bool discovered[MAXV + 1];
    bool processed[MAXV + 1];
    int parent[MAXV + 1];
    int entry_time[MAXV + 1];
    int exit_time[MAXV + 1];
    int m_time;

    void InitGraph(bool directed);
    void InitSearch();
    void InsertEdge(int x, int y, bool directed);
    void BreadthFirstSearch(int start);
    void PrintGraph();
    void ProcessVertex(int x);
    virtual void ProcessEdge(int x, int y);
    void FindPath(int start, int end);
};