#include "stdafx.h"
#include "BSTCommandHandler.h"
#include <string>


BSTCommandHandler::BSTCommandHandler()
{
    m_tree = new BST<char>();
}


BSTCommandHandler::~BSTCommandHandler()
{
    delete m_tree;
}

void BSTCommandHandler::Run()
{
    bool run = true;
    string input;

    while (run)
    {
        cout << "Enter Command: " << endl;
        cin >> input;

        if (input == "TI")
        {
            InOrderTraversal();
        }
        else if (input == "TP")
        {
            PreOrderTraversal();
        }
        else if (input == "TR")
        {
            PostOrderTraversal();
        }
        else if (input == "I")
        {
            char c;
            cin >> c;
            InsertChar(c);
        }
        else if (input == "S")
        {
            char c;
            cin >> c;
            if (SearchChar(c))
            {
                cout << c << " was found in BST." << endl;
            }
            else
            {
                cout << c << " was not found in BST" << endl;
            }
        }

        else if (input == "QUIT")
        {
            run = false;
        }
        else
        {
            cout << input<<": command not found" << endl;
        }
    }
}

void BSTCommandHandler::InsertChar(char c)
{
    m_tree->Insert(c);
}
bool BSTCommandHandler::SearchChar(char c)
{
    auto node = m_tree->Search(c);
    if (node == nullptr) return false;
    else return true;
}
void BSTCommandHandler::InOrderTraversal()
{
    m_tree->InOrder();
}
void BSTCommandHandler::PreOrderTraversal()
{
    m_tree->TraversePreOrder();
}
void BSTCommandHandler::PostOrderTraversal()
{
    m_tree->TraversePostOrder();
}
