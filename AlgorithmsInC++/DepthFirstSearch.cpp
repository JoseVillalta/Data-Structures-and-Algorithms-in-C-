#include "DepthFirstSearch.h"
#include <queue>

void DFS::InitGraph(bool directed)
{
    m_g = new Graph();
    m_g->directed = directed;
    m_g->nedges = 0;
    m_g->nvertices = 0;

    for (int i = 1; i < MAXV; i++) m_g->degree[i] = 0;
    for (int i = 1; i < MAXV; i++) m_g->edges[i] = nullptr;
}

void DFS::InsertEdge(int x, int y, bool directed)
{
    auto edgeNode = new edgenode();
    edgeNode->weight = 0;
    edgeNode->y = y;
    edgeNode->next = m_g->edges[x];
    m_g->edges[x] = edgeNode;
    m_g->degree[x]++;

    if (!directed)
    {
        InsertEdge(y, x, true);
    }
    else
    {
        m_g->nedges++;
    }
}

void DFS::InitSearch()
{
    for (int i = 1; i <= m_g->nvertices; i++)
    {
        discovered[i] = false;
        processed[i] = false;
        parent[i] = -1;
        m_time = 0;
    }
}

void DFS::PrintGraph()
{
    edgenode * p;
    cout << "Printing Graph" << endl;

    for (int i = 1; i <= m_g->nvertices; i++)
    {
        cout << i << ": ";
        p = m_g->edges[i];
        while (p != nullptr)
        {
            cout << " " << p->y;
            p = p->next;
        }
        cout << endl;
    }
}

void DFS::ProcessVertex(int vertex)
{
    cout << "Processing Vertex:  " << vertex << endl;
}

void DFS::ProcessEdge(int x, int y)
{

}

void DFS::ProcessVertexLate(int v)
{
    
}

void DFS::DepthFirstSearch(int v)
{
    ProcessVertex(v);
    discovered[v] = true;
    m_time++;
    entry_time[v] = m_time;
    auto node = m_g->edges[v];
    while (node != nullptr)
    {
        int y = node->y;
        if (!discovered[y])
        {
            ProcessEdge(v, y);
            discovered[y] = true;
            parent[y] = v;
            DepthFirstSearch(y);
        }
        if (!processed[y] || m_g->directed)
        {
            ProcessEdge(v, y);
        }
        node = node->next;
    }
    ProcessVertexLate(v);
    m_time++;
    exit_time[v] = m_time;
    processed[v] = true;
}



