#include "PriorityQueue.h"
#include "PQNode.h"
#include <iostream>

using namespace std;

class PQTest
{
public:
    void DoTests();
private:
    void TestDelete();
    void TestHeapOps();
    void TestSearch();
    void Init();
    void Cleanup();
    MaxPriorityQueue<string> * pq;
   
};