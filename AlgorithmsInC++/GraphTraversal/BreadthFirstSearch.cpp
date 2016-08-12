#include "BreadthFirstSearch.h"
#include <queue>

void BFS::InitGraph(bool directed)
{
    m_g = new Graph();
    m_g->directed = directed;
    m_g->nedges = 0;
    m_g->nvertices = 0;

    for (int i = 1; i < MAXV; i++) m_g->degree[i] = 0;
    for (int i = 1; i < MAXV; i++) m_g->edges[i] = nullptr;
}

void BFS::InsertEdge(int x, int y, bool directed)
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

void BFS::PrintGraph()
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

void BFS::ProcessVertex(int vertex)
{
    cout << ", " << vertex;
}

void BFS::ProcessEdge(int x, int y)
{

}

void BFS::BreadthFirstSearch(int start)
{
    auto q = new queue<int>();
    q->push(start);
    discovered[start] = true;
    int y;

    while (!q->empty())
    {
        int p = q->front();
        q->pop();
        auto edge = m_g->edges[p];
        while (edge != nullptr)
        {
            y = edge->y;
            ProcessVertex(y);
            if (processed[y] == false || m_g->directed)
            {
                ProcessEdge(p, y);
            }
            if (discovered[y] == false)
            {
                q->push(y);
                discovered[y] = true;
                parent[y] = p;
            }
            edge = edge->next;
        }

    }
}

