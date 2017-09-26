#include "stdafx.h"
#include "MSTTest.h"

void PrimTest::DoTests()
{
    PrimAlgoTest();
}

void PrimTest::PrimAlgoTest()
{
    auto pa = new PrimsAlgorithm();
    pa->m_g->nvertices = 7;
    pa->InsertEdge(1, 2, 5, false);
    pa->InsertEdge(2, 3, 12, false);
    pa->InsertEdge(1, 4, 9, false);
    pa->InsertEdge(1, 5, 7, false);
    pa->InsertEdge(2, 4, 7, false);
    pa->InsertEdge(4, 5, 4, false);
    pa->InsertEdge(4, 6, 3, false);
    pa->InsertEdge(5, 6, 2, false);
    pa->InsertEdge(5, 7, 5, false);

    pa->prim(1);

}

