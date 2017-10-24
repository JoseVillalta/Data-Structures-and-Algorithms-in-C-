#include "Two-Coloring-Graphs.h"

using namespace std;

void TwoColoring::ProcessEdge(int x, int y)
{
    if (color[x] == color[y])
    {
        bipartate = false;
        cout << "Not a bipartate graph" << endl;
    }
    color[y] = complement(color[x]);
}

void TwoColoring::TwoColor()
{
    int i;
    for (i = 1; i < m_g->nvertices; i++)
    {
        color[i] = COLOR_UNCOLORED;
    }

    bipartate = true;

    for (i = 1; i < m_g->nvertices; i++)
    {
        if (discovered[i] == false)
        {
            color[i] = COLOR_WHITE;
            BreadthFirstSearch(i);
        }
    }
    
}

int TwoColoring::complement(int color)
{
    if (color == COLOR_BLACK) return COLOR_WHITE;
    if (color == COLOR_WHITE) return COLOR_BLACK;

    return COLOR_UNCOLORED;
}

