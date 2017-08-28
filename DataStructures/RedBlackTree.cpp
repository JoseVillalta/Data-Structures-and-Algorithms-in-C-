#include "RedBlackTree.h"
#include <utility>
#include <iostream>
#include <queue>
using namespace std;


void RedBlackTree::InOrderHelper(RBTreeNode<int>* root)
{
    if (root == nullptr)
        return;
    InOrderHelper(root->left);
    cout << root->data << " ";
    InOrderHelper(root->right);
}


void RedBlackTree::InOrder()
{
    InOrderHelper(root);
}
void RedBlackTree::LevelOrderHelper(RBTreeNode<int>* root)
{
    if (root == nullptr)
        return;
    queue<RBTreeNode<int>*> q;
    q.push(root);

    while (!q.empty())
    {
        auto temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void RedBlackTree::LevelOrder()
{
    LevelOrderHelper(root);
}


RBTreeNode<int> * RedBlackTree::BSTInsert(RBTreeNode<int>* root, RBTreeNode<int>* pt)
{
    if (root == nullptr) return pt;

    if (pt->data < root->data)
    {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

void RedBlackTree::RotateLeft(RBTreeNode<int>*& root, RBTreeNode<int>*& pt)
{
    auto pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;    
}

void RedBlackTree::RotateRight(RBTreeNode<int>*& root, RBTreeNode<int>*& pt)
{
    auto pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;

}


// This function fixes violations caused by BST Insertion
void RedBlackTree::FixViolations(RBTreeNode<int>* &root, RBTreeNode<int>* &pt)
{
    RBTreeNode<int> * parent_pt = nullptr;
    RBTreeNode<int> * grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /* Case A:
         * Parent of pt is left child of grandparent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
            auto *uncle_pt = grand_parent_pt->right;

            /* Case 1:
             * The uncle of pt is also red
             * Only Recoloring is required */
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case 2:
                 * pt is right child of its parent
                 * Left-Rotation required */
                if (pt == parent_pt->right)
                {
                    RotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case 3
                 * pt is left child of its parent
                 * Right-Rotation required */
                RotateRight(root, grand_parent_pt);
                auto temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }
        /* Case B:
         * Parent of PT is right child of grandparent of pt */
        else
        {
            auto uncle_pt = grand_parent_pt->left;
            /* Case 1:
             * The uncle of pt is also red
             * Only recoloring is required */
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case 2: 
                 * pt is left child of its parents
                 * Rigth-Rotation required */
                if (pt == parent_pt->left)
                {
                    RotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                /* Case 3:
                 * pt is right child of its parents
                 * Left-Rotation required */
                RotateLeft(root, grand_parent_pt);
                auto temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }

        }
    }
    
    root->color = BLACK;
}


void RedBlackTree::Insert(int val)
{
    auto pt = new RBTreeNode<int>(val);
    root = BSTInsert(root, pt);
    FixViolations(root, pt);

}
void RedBlackTree::Delete()
{
    
}
