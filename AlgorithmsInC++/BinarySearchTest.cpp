#include<vector>
#include<iostream>

#include "BinarySearchTest.h"
#include "BinarySearch.h"

using namespace std;

void BinarySearchTest::DoTest()
{
    Init();
    SearchInts();
    SearchWBadInputs();
}

void BinarySearchTest::Init()
{
    m_binarySearcher = new BinarySearch();
}

void BinarySearchTest::SearchInts()
{
    vector<int> v = { 2, 4, 6, 8, 10, 12, 14, 16 };
    int loc = 0;
    bool found = m_binarySearcher->Search(v, loc, 8, 0, 7);
    _ASSERT(found == true);
    _ASSERT(loc == 3);
    
    int loc2 = 0;
    found = m_binarySearcher->Search(v, loc2, 11, 0, 7);
    _ASSERT(found == false);
    _ASSERT(loc2 == 0);

    cout << "Binary Search Test Successful" << endl;
}

void BinarySearchTest::SearchWBadInputs()
{
    vector<int> v;
    int loc = 0;
    bool found = m_binarySearcher->Search(v, loc, 8, 0, 7);
    _ASSERT(found == false);
    cout << "Search with bad inputs test was successful" << endl;

}