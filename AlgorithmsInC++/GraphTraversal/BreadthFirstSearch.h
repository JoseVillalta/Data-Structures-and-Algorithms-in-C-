#pragma once
#include<iostream>
#include "Graph.h"
#include "EdgeNode.h"

using namespace std;
class BFS
{
public:
    Graph * m_g;
    void InitGraph(bool directed);
    void InsertEdge(int x, int y, bool directed);
    void BreadthFirstSearch();
    void PrintGraph();
};