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
}

void CharBSTTests::TestLevels()
{
    cout << "*******CHAR BST TEST*******" << endl;
    auto tree1 = m_ptrBSTFactory->GenerateBST(10);
    tree1->Display();
    
    tree1->InOrder();
    cout << endl;
    tree1->TraverseInOrder();
    auto * v = tree1->ToVectorInOrder();
    auto size = v->size();

    cout << endl;
    for (int i = 0; i < size; i++)
    {      
        cout << tree1->Level(v->at(i)) << " ";
        cout << tree1->RecLevel(v->at(i)) << endl;
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
