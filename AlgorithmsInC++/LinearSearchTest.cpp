#include "LinearSearchTests.h"
#include "LinearSearch.h"
#include <iostream>
#include <vector>

using namespace std;
void LinearSearchTest::DoTests()
{
    Init();
    SearchIntVectorTest();
}

void LinearSearchTest::Init()
{
    LinearSearcher = new LinearSearch();
}
void LinearSearchTest::SearchIntVectorTest()
{
    int loc = 0;
    vector<int> v = { 2, 4, 6, 8, 10, 12 };
    bool found = LinearSearcher->Search(v, 8, loc);
    _ASSERT(found == true);
    _ASSERT(loc == 3);
    loc = 0;
    found = LinearSearcher->Search(v, 11, loc);
    _ASSERT(found == false);
    _ASSERT(loc == 0);
    cout << "Linear Search Successful" << endl;

}