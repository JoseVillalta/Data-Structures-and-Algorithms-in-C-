#include "VertexCover.h"
#include <queue>

using namespace std;

void VertexCover::GetCover()
{
	for (int i = 1; i <= m_g->nvertices; i++)
	{
		auto node = m_g->edges[i];
		if (discovered[i] == false)
		{
			while (node != nullptr)
			{
				int y = node->y;
				if (!discovered[y])
				{
					discovered[i] = true;
					discovered[y] = true;
					break;
				}
				node = node->next;
			}
		}
	}
	cout << "Vertex Cover is" << endl;
	for (int i = 1; i <= m_g->nvertices; i++)
	{
		if (discovered[i])
		{
			cout << i << ", ";
		}
	}

}