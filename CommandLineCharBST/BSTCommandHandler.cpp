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

        if (input == "QUIT")
        {
            run = false;
        }
      
       

    }
}

void BSTCommandHandler::InsertChar(char c)
{

}
bool BSTCommandHandler::SearchChar(char c)
{
    return false;
}
void BSTCommandHandler::InOrderTraversal()
{

}
void BSTCommandHandler::PreOrderTraversal()
{

}
void BSTCommandHandler::PostOrderTraversal()
{

}
