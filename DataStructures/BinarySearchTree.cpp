#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

BST::BST()
{
    m_root = nullptr;
}
TreeNode * BST::Search(int key)
{
    TreeNode * node = m_root;
    if (m_root == nullptr) return node;
    if (m_root->data == key) return node;

   return SearchNode(node, key);


}

void BST::Insert(int key)
{
    if (m_root == nullptr)
    {
        m_root = new TreeNode();
        m_root->data = key;
    }
    else
    {
        InsertNode(m_root, key);
    }

}

void BST::InsertNode(TreeNode * root, int val)
{

    if (root->data > val)
    {
        if (root->left == nullptr)
        {
            root->left = new TreeNode(val);
        }
        else
        {
            InsertNode(root->left, val);
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new TreeNode(val);
        }
        else
        {
            InsertNode(root->right, val);
        }     
    }
}

TreeNode * BST::SearchNode(TreeNode * root, int key)
{
    if (root == nullptr) return root;
    if (root->data == key) return root;

    else if (root->data > key)
    {
       return SearchNode(root->left, key);
    }
    else
    {
       return SearchNode(root->right, key);
    }
}

int BST::Level(int key)
{
    int level = 1;
    TreeNode * nodePtr = m_root;
    bool found = false;

    while (!found && nodePtr != nullptr)
    {
        if (key == nodePtr->data)
        {
            found = true;
        }
        else if (key < nodePtr->data)
        {
            level++;
            nodePtr = nodePtr->left;
        }
        else
        {
            level++;
            nodePtr = nodePtr->right;
        }
    }

    if (found) return level;
    return -1;
}

int BST::RecLevel(int key)
{
    if (m_root == nullptr) return -1;
    auto level = RecLevelNode(m_root, key);
    if (level < 0)
    {
        cout << "Item not found" << endl;
    }
    return level;
}

int BST::RecLevelNode(TreeNode * nodePtr, int key)
{
    if (nodePtr == nullptr) return -100000;
    if (nodePtr->data == key) return 1;

    if (nodePtr->data > key)
    {
        return 1 + RecLevelNode(nodePtr->left, key);
    }
    else
    {
        return 1 + RecLevelNode(nodePtr->right, key);
    }
}

int BST::Height()
{
    if (m_root == nullptr) return 0;

    return HeightNode(m_root);
}

int BST::HeightNode(TreeNode * nodePtr)
{
    if (nodePtr == nullptr) return 0;

    return max(1 + HeightNode(nodePtr->left), 1 + HeightNode(nodePtr->right));
}

void BST::TraverseInOrder()
{
    InOrderTrav(m_root);
}

void BST::InOrderTrav(TreeNode * node)
{
    if (node == nullptr) return;
    
    InOrderTrav(node->left);

    cout << node->data << " " << endl;

    InOrderTrav(node->right);
}

void BST::TraversePreOrder()
{
    PreOrderTrav(m_root);
}

void BST::PreOrderTrav(TreeNode* node)
{
    if (node == nullptr) return;

    cout << node->data << " " << endl;

    PreOrderTrav(node->left);
    PreOrderTrav(node->right);
}

void BST::TraversePostOrder()
{
    PostOrderTrav(m_root);
}

void BST::PostOrderTrav(TreeNode * node)
{
    if (node == nullptr) return;

    PostOrderTrav(node->left);
    PostOrderTrav(node->right);
    
    cout << node->data << " " << endl;
}

void BST::Trace()
{
    TraceInderOrder(m_root);
}

void BST::TraceInderOrder(TreeNode * node)
{
    if (node != nullptr)
    {
        cout << 'L';
        TraceInderOrder(node->left);
        cout << "/" << node->data << endl;
        cout << "R";
        TraceInderOrder(node->right);
    }
    cout << "U";
}