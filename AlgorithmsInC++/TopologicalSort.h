#include "DepthFirstSearch.h"

class TopoLogicalSort : public DFS
{
public:
    void TopoSort(Graph * g);
private:
    int EdgeClassification(int x, int y);
    virtual void ProcessEdge(int x, int y);
    virtual void ProcessVertexLate(int v);
};
