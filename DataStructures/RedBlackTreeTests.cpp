#include "RedBlackTreeTests.h"
#include <iostream>

using namespace std;
void RedBlackTreeTests::DoTests()
{
    cout << "Do Red Black Tree Test Tests" << endl;

    auto rbTree = new RedBlackTree();

    rbTree->Insert(7);
    rbTree->Insert(6);
    rbTree->Insert(5);
    rbTree->Insert(4);
    rbTree->Insert(3);
    rbTree->Insert(2);
    rbTree->Insert(1);

    cout << "Red Black Tree in order" << endl;
    rbTree->InOrder();
    cout << "Red Black Tree Levels " << endl;
    rbTree->LevelOrder();
}
