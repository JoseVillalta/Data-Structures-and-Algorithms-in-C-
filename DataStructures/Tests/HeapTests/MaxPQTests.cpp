#include "MaxPQTests.h"

void PQTest::DoTests()
{
    TestHeapOps();
    TestDelete();   
}

void PQTest::TestHeapOps()
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

void PQTest::TestDelete()
{
    auto pq = new MaxPriorityQueue<string>();
    _ASSERT(pq != nullptr);

    pq->Insert("Alice", 5);
    pq->Insert("Bob", 10);
    pq->Insert("Charlie", 15);
    pq->Insert("Dan", 2);
    pq->Insert("Effie", 7);

    pq->Delete("Bob", 10);
    pq->ExtractMax();
    auto max = pq->Maximun();
    _ASSERT(max == "Effie");

    cout << "Max PQ Test Delete Passed" << endl;
}
