#pragma once
#include <iostream>
#include "Graph.h"

using namespace std;

class AllPathsTests
{
public:
    void DoTests();
    void AllPathTest();
private:
    void InsertEdge(Graph *g, int x, int y, bool directed);
};