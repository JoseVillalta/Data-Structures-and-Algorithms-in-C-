#include "MaxPQTests.h"

void PQTest::DoTests()
{
    TestHeapOps();
    TestDelete();
    TestSearch();
}

void PQTest::TestHeapOps()
{
    Init();

    auto max = pq->Maximun();
    _ASSERT(max == "Charlie");

    max = pq->ExtractMax();
    _ASSERT(max == "Charlie");

    max = pq->Maximun();
    _ASSERT(max == "Bob");

    cout << "Max PQ Test Passed" << endl;

    Cleanup();
}

void PQTest::TestDelete()
{
    Init();

    pq->Delete("Bob", 10);
    pq->ExtractMax();
    auto max = pq->Maximun();
    _ASSERT(max == "Effie");

    cout << "Max PQ Test Delete Passed" << endl;

    Cleanup();
}

void PQTest::TestSearch()
{
   
    Init();
    int first = pq->Find("Charlie", 15);
    _ASSERT(first == 0);

    int second = pq->Find("Bob", 10);
    _ASSERT(second == 2);

    int last = pq->Find("Alice", 5);
    _ASSERT(last == 4);

    int dan = pq->Find("Dan", 2);
    _ASSERT(dan == 3);

    int non = pq->Find("DonTExists", 5);
    _ASSERT(non = -1);

    int non2 = pq->Find("Nope", 20);
    _ASSERT(non2 = -1);

    int non3 = pq->Find("Zilch", 1);
    _ASSERT(non3 == -1);
    Cleanup();
}

void PQTest::Init()
{
    pq = new MaxPriorityQueue<string>();
    _ASSERT(pq != nullptr);

    pq->Insert("Alice", 5);
    pq->Insert("Bob", 10);
    pq->Insert("Charlie", 15);
    pq->Insert("Dan", 2);
    pq->Insert("Effie", 7);
}

void PQTest::Cleanup()
{
    delete pq;
}