#pragma once
#include "YoungTableau.h"

using namespace std;

class YoungTableauTests
{
public:
    void DoTests();
private:
    void TestCreation();
    void TestInsert();
    void TestExtractMin();
    void TestSort();
};