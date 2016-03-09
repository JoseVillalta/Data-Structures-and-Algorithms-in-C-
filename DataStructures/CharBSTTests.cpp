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
        cout << tree1->Level(v->at(i)) << endl;
    }
    cout << endl;

}
