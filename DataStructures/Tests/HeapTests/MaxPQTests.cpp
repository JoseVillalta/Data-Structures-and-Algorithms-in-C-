#include "MaxPQTests.h"

void PQTest::DoTests()
{
    auto pq = new MaxPriorityQueue<string>();
    _ASSERT(pq != nullptr);

    pq->Insert("Alice", 5);
    pq->Insert("Bob", 10);
    pq->Insert("Charlie", 15);
    pq->Insert("Dan", 2);
    pq->Insert("Effie", 7);

    auto max = pq->Maximun();
    _ASSERT(max == "Charlie");

    max = pq->ExtractMax();
    _ASSERT(max == "Charlie");

    max = pq->Maximun();
    _ASSERT(max == "Bob");

    cout << "Max PQ Test Passed" << endl;
}