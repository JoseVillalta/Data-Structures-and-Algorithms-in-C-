#include "CharBSTTests.h"
#include <iostream>
#include <vector>

using namespace std;

void CharBSTTests::Init()
{
    m_ptrBSTFactory = new BSTFactory();
}

void CharBSTTests::DoTests()
{
    Init();
    TestLevels();
    TestHeight();
    TestNodeCountAndDisplayPreOrder();
    TestInOrder();
}

void CharBSTTests::TestLevels()
{
    cout << "*******TEST LEVELS *******" << endl;
    auto tree1 = m_ptrBSTFactory->GenerateBST(10);
    
    auto * v = tree1->ToVectorInOrder();
    auto size = v->size();

    cout << endl;
    for (int i = 0; i < size; i++)
    {    
        auto l1 = tree1->Level(v->at(i));
        auto l2 = tree1->RecLevel(v->at(i));
        cout <<l1 << " ";
        cout << l2 << endl;
        _ASSERT(l1 == l2);
    }
    cout << endl;
}

void CharBSTTests::TestHeight()
{
    auto tree1 = m_ptrBSTFactory->GenerateBST(10);
    auto tree2 = m_ptrBSTFactory->GenerateBST(100);
    auto tree3 = m_ptrBSTFactory->GenerateBST(1000);

    cout << "Height of Tree 1 is " << tree1->Height() << endl;
    cout << "Height of Tree 2 is " << tree2->Height() << endl;
    cout << "Height of Tree 3 is " << tree3->Height() << endl;
}

void CharBSTTests::TestNodeCountAndDisplayPreOrder()
{
    auto tree1 = m_ptrBSTFactory->GenerateBST(10);
    tree1->Display();
    cout << "Test Node Count and Display Pre Order" << endl;
    _ASSERT(tree1->NodeCount() == 10);
}

void CharBSTTests::TestInOrder()
{
    cout << "Test in Order Traversal" << endl;
    auto tree1 = m_ptrBSTFactory->GenerateBST(10);
    tree1->Display();
    tree1->InOrder();
    cout << endl;
    tree1->TraverseInOrder();

    auto tree2 = m_ptrBSTFactory->GenerateBST(20);
    tree2->Display();
    tree2->InOrder();
    cout << endl;
    tree2->TraverseInOrder();
}