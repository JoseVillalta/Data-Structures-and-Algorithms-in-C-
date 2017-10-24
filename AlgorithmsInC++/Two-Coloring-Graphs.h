#pragma once
#include "BreadthFirstSearch.h"
#define COLOR_UNCOLORED -1
#define COLOR_WHITE 0
#define COLOR_BLACK 1

using namespace std;

class TwoColoring : public BFS
{
public:
    bool bipartate;
    int color[MAXV + 1];
    void TwoColor();
    int complement(int color);
    virtual void ProcessEdge(int x, int y);
    
};