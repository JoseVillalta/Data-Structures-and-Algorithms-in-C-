#include "DepthFirstSearch.h"
#include <stack>

using namespace std;

class TopoLogicalSort : public DFS
{
public:
    void TopoSort();
private:
    stack<int> m_stack;
    int EdgeClassification(int x, int y);
    virtual void ProcessEdge(int x, int y);
    virtual void ProcessVertexLate(int v);
};
