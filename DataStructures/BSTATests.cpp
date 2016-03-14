#include "BSTATests.h"
#include "BSTA.h"
#include <iostream>
using namespace std;

void BSTATests::DoTests()
{
    TestInsert();
}

void BSTATests::TestInsert()
{
    auto bsta = new BSTA<int>();
    bsta->Insert(10);
    bsta->Insert(5);
    bsta->Insert(15);

    _ASSERT(bsta->Search(10) == true);
    _ASSERT(bsta->Search(4) == false);
    _ASSERT(bsta->Search(15) == true);
    _ASSERT(bsta->Search(5) == true);


    cout << "BSTA test finished succesfully" << endl;
}