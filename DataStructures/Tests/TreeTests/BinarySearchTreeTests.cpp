#include "BinarySearchTreeTests.h"
#include <iostream>

using namespace std;

void BSTTests::DoTests()
{
    Init();
    SearchTests();
    LevelTest();
    RecLevelTest();
    HeightTest();
    InOrderTraverseTest();
    LeafCountTest();
    InOrderTest();
    LelvelByLevelTest();
    NodeCountTest();
    DeleteTest();
    RecDeleteTest();
    SearchFloatTest();
    InOrderTraversalStrings();
}

void BSTTests::Init()
{
    m_tree = new BST<int>();
    m_tree->Insert(50);
    m_tree->Insert(15);
    m_tree->Insert(62);
    m_tree->Insert(5);
    m_tree->Insert(20);
    m_tree->Insert(58);
    m_tree->Insert(91);
    m_tree->Insert(3);
    m_tree->Insert(8);
    m_tree->Insert(37);
    m_tree->Insert(24);
    m_tree->Insert(60);
}

void BSTTests::CleanUp()
{
    delete m_tree;
}

void BSTTests::SearchTests()
{
    cout << "***********************" << endl;
    cout << "Binary Tree Search Test" << endl;
    cout << "***********************" << endl;

    BST<int> * tree = new BST<int>();
    tree->Insert(5);
    tree->Insert(6);
    tree->Insert(4);
    auto node = tree->Search(5);
    _ASSERT(node->data == 5);
    auto node2 = tree->Search(6);
    _ASSERT(node2 != nullptr);
    _ASSERT(node2->data == 6);
    auto node3 = tree->Search(17);
    _ASSERT(node3 == nullptr);
    cout << "Test pass" << endl;
    cout << endl;
}

void BSTTests::SearchFloatTest()
{
    cout << "***********************" << endl;
    cout << "Binary Tree Search Floats" << endl;
    cout << "***********************" << endl;

    BST<double> * tree = new BST<double>();
    tree->Insert(5.5);
    tree->Insert(6.6);
    tree->Insert(4.4);
    auto node = tree->Search(5.5);
    _ASSERT(node->data == 5.5);
    auto node2 = tree->Search(6.6);
    _ASSERT(node2 != nullptr);
    _ASSERT(node2->data == 6.6);
    cout << "Test pass" << endl;
    cout << endl;

}

void BSTTests::LevelTest()
{
    cout << "***********" << endl;
    cout << "Level Test " << endl;
    cout << "***********" << endl;

    auto tree = new BST<int>();
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

    auto tree = new BST<int>();
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

    auto tree = new BST<int>();
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

    auto tree = new BST<int>();
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

void BSTTests::InOrderTraversalStrings()
{
    cout << "************************************" << endl;
    cout << "     Tree Traversal Test  Strings   " << endl;
    cout << "************************************" << endl;

    auto tree = new BST<char>();
    tree->Insert('G');
    tree->Insert('F');
    tree->Insert('J');
    tree->Insert('A');
    tree->Insert('H');
    tree->Insert('O');
    tree->Insert('E');
    tree->Insert('M');
    tree->Insert('P');
    tree->Insert('C');
    tree->Insert('B');
    tree->Insert('L');

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

    auto tree = new BST<int>();
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
    Init();
    cout << "*************************************" << endl;
    cout << "Non Recursive in Order Traversal Test" << endl;
    cout << "*************************************" << endl;

    

    m_tree->InOrder();
    cout << endl;

    cout << endl;
    cout << "**********" << endl;

    auto tree2 = new BST<int>();
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
    CleanUp();
}

void BSTTests::LelvelByLevelTest()
{
    Init();
    cout << "*************************************" << endl;
    cout << "    Level by Level Traversal Test    " << endl;
    cout << "*************************************" << endl;

   

    m_tree->LevelByLevel();
    cout << endl;

    cout << endl;
    cout << "**********" << endl;

    auto tree2 = new BST<int>();
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
    CleanUp();
}

void BSTTests::DeleteTest()
{
    Init();
    cout << "*************************************" << endl;
    cout << "    Delete Test                      " << endl;
    cout << "*************************************" << endl;


    int nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 12);
    m_tree->Delete(58);
    nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 11);

    m_tree->Delete(62);
    nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 10);
    m_tree->Display();

    m_tree->Delete(50);
    nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 9);
    m_tree->Display();

    auto tree2 = new BST<int>();
    tree2->Insert(50);
    tree2->Insert(40);
    tree2->Insert(60);
    tree2->Insert(55);
    nodeCount = tree2->NodeCount();
    _ASSERT(nodeCount == 4);
    tree2->Display();

    tree2->Delete(60);
    nodeCount = tree2->NodeCount();
    _ASSERT(nodeCount == 3);
    tree2->Display();



}

void BSTTests::NodeCountTest()
{
    Init();
    cout << "*************************************" << endl;
    cout << "    Node Count Test                  " << endl;
    cout << "*************************************" << endl;

    

    int nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 12);

    cout << "Node Count is: " << nodeCount << endl;

    cout << "****************" << endl;
    cout << "   End of Test  " << endl;
    cout << "****************" << endl;
    CleanUp();
}


void BSTTests::RecDeleteTest()
{
    Init();
    cout << "*************************************" << endl;
    cout << "    Recursive Delete Test            " << endl;
    cout << "*************************************" << endl;

    m_tree->DeleteRec(50);
    int nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 11);
    

    m_tree->Delete(91);
    nodeCount = m_tree->NodeCount();
    _ASSERT(nodeCount == 10);
    m_tree->Display();
}