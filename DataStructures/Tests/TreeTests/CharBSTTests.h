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
    void TestHeight();
    void TestNodeCountAndDisplayPreOrder();
    void TestInOrder();
    void TestLevelByLevel();
    BSTFactory * m_ptrBSTFactory;
};

