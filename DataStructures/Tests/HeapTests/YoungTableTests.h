#pragma once
#include "YoungTable.h"

using namespace std;

class YoungTableTests
{
public:
    void DoTests();
private:
    void TestCreation();
    void TestInsert();
    void TestExtractMin();
};