#pragma once
#include "BSTFactory.h"
#include "BinarySearchTree.h"
class CharBSTTests
{
public:
    void DoTests();
private:
    void Init();
    void TestLevels();
    BSTFactory * m_ptrBSTFactory;
};

