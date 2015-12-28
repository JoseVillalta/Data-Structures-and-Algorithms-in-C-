#include "BinarySearchTreeTests.h"
#include <iostream>

using namespace std;

void BSTTests::DoTests()
{
    SearchTests();
    LevelTest();
    RecLevelTest();
    HeightTest();
    InOrderTraverseTest();
    LeafCountTest();
    InOrderTest();
    LelvelByLevelTest();
}

void BSTTests::SearchTests()
{
    cout << "***********************" << endl;
    cout << "Binary Tree Search Test" << endl;
    cout << "***********************" << endl;

    BST * tree = new BST();
    tree->Insert(5);
    tree->Insert(6);
    tree->Insert(4);
    auto node = tree->Search(5);
    _ASSERT(node->data == 5);
    auto node2 = tree->Search(6);
    _ASSERT(node2 != nullptr);
    _ASSERT(node2->data == 6);
    cout << "Test pass" << endl;
    cout << endl;
}

void BSTTests::LevelTest()
{
    cout << "***********" << endl;
    cout << "Level Test " << endl;
    cout << "***********" << endl;

    auto tree = new BST();
    tree->Insert(5);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(2);
    tree->Insert(10);

    auto level = tree->Level(10);
    _ASSERT(level == 3);

    cout << "Level Test Pass" << endl;
    cout << endl;
}

void BSTTests::RecLevelTest()
{
    cout << "*********************" << endl;
    cout << "Recursive Level Test" << endl;
    cout << "*********************" << endl;

    auto tree = new BST();
    tree->Insert(5);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(2);
    tree->Insert(10);

    auto level = tree->RecLevel(10);
    _ASSERT(level == 3);

    level = tree->RecLevel(18);
    _ASSERT(level < 0);

    cout << "Recursive level tests pass" << endl;
    cout << endl;
}

void BSTTests::HeightTest()
{
    cout << "*********************" << endl;
    cout << "  Tree Height  Test  " << endl;
    cout << "*********************" << endl;

    auto tree = new BST();
    tree->Insert(5);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(2);
    tree->Insert(10);

    auto height = tree->Height();
    _ASSERT(height == 3);
    cout << "Tree Height Test Passed" << endl;
    cout << endl;
}

void BSTTests::InOrderTraverseTest()
{
    cout << "*****************************" << endl;
    cout << "     Tree Traversal Test     " << endl;
    cout << "*****************************" << endl;

    auto tree = new BST();
    tree->Insert(50);
    tree->Insert(15);
    tree->Insert(62);
    tree->Insert(5);
    tree->Insert(20);
    tree->Insert(58);
    tree->Insert(91);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(37);
    tree->Insert(24);
    tree->Insert(60);

    cout << "In Order " << endl;
    tree->TraverseInOrder();
    cout << "*******************" << endl;
    cout << "Pre Order" << endl;
    tree->TraversePreOrder();
    cout << "********************" << endl;
    cout << "Post Order" << endl;
    tree->TraversePostOrder();
    cout << "********************" << endl;
    cout << "Trace in Order" << endl;
    tree->Trace();
    cout << "***********************" << endl;
    cout << "Display Pre Order" << endl;
    tree->Display();
    cout << "***********************" << endl;
}

void BSTTests::LeafCountTest()
{
    cout << "********************************" << endl;
    cout << "          Leaf Count Test       " << endl;
    cout << "********************************" << endl;

    auto tree = new BST();
    tree->Insert(50);
    tree->Insert(15);
    tree->Insert(62);
    tree->Insert(5);
    tree->Insert(20);
    tree->Insert(58);
    tree->Insert(91);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(37);
    tree->Insert(24);
    tree->Insert(60);

    auto leafCount = tree->LeafCount();
    _ASSERT(leafCount == 5);

    cout << "********************************" << endl;
    cout << "        LEAF COUNT TEST PASS    " << endl;
    cout << "********************************" << endl;



}

void BSTTests::InOrderTest()
{
    cout << "*************************************" << endl;
    cout << "Non Recursive in Order Traversal Test" << endl;
    cout << "*************************************" << endl;

    auto tree = new BST();
    tree->Insert(50);
    tree->Insert(15);
    tree->Insert(62);
    tree->Insert(5);
    tree->Insert(20);
    tree->Insert(58);
    tree->Insert(91);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(37);
    tree->Insert(24);
    tree->Insert(60);

    tree->InOrder();
    cout << endl;

    cout << endl;
    cout << "**********" << endl;

    auto tree2 = new BST();
    tree2->Insert(10);
    tree2->Insert(9);
    tree2->Insert(8);
    tree2->Insert(7);
    tree2->Insert(11);
    tree2->Insert(12);
    tree2->Insert(13);
    tree2->InOrder();
    cout << endl;

    cout << "****************" << endl;
    cout << "   End of Test  " << endl;
    cout << "****************" << endl;
}

void BSTTests::LelvelByLevelTest()
{
    cout << "*************************************" << endl;
    cout << "    Level by Level Traversal Test    " << endl;
    cout << "*************************************" << endl;

    auto tree = new BST();
    tree->Insert(50);
    tree->Insert(15);
    tree->Insert(62);
    tree->Insert(5);
    tree->Insert(20);
    tree->Insert(58);
    tree->Insert(91);
    tree->Insert(3);
    tree->Insert(8);
    tree->Insert(37);
    tree->Insert(24);
    tree->Insert(60);

    tree->LevelByLevel();
    cout << endl;

    cout << endl;
    cout << "**********" << endl;

    auto tree2 = new BST();
    tree2->Insert(10);
    tree2->Insert(9);
    tree2->Insert(8);
    tree2->Insert(7);
    tree2->Insert(11);
    tree2->Insert(12);
    tree2->Insert(13);
    tree2->LevelByLevel();
    cout << endl;

    cout << "****************" << endl;
    cout << "   End of Test  " << endl;
    cout << "****************" << endl;

}