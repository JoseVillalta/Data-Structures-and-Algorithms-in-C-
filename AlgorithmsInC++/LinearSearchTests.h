#ifndef __LINEAR_SEARCH_TEST_H__
#define __LINEAR_SEARCH_TEST_H__
#include "LinearSearch.h"
class LinearSearchTest
{
public:
    void DoTests(void);
private:
    void SearchIntVectorTest(void);
    void SelfOrganizedListTest(void);
    void MoveAheadOneSearchTest(void);
    void Init(void);

    LinearSearch * LinearSearcher;
};



#endif