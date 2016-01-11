#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
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

void BST::Display()
{
    cout << "node->data\t";
    cout << "left->data\t";
    cout << "right->data\t";
    cout << endl;
    cout << "==========\t";
    cout << "==========\t";
    cout << "==========\t";
    cout << endl;



    DisplayPreOrder(m_root);
}

void BST::DisplayPreOrder(TreeNode * node)
{
    if (node != nullptr)
    {
        cout << node->data;
        if (node->left != nullptr)
        {
            cout << "\t\t" << node->left->data;
        }
        else
        {
            cout << "\t\t-";
        }

        if (node->right != nullptr)
        {
            cout << "\t\t" << node->right->data;
        }
        else
        {
            cout << "\t\t-";
        }
        cout << endl;

        DisplayPreOrder(node->left);
        DisplayPreOrder(node->right);
    }
}

int BST::LeafCount()
{
    return LeafCountNode(m_root);
}

int BST::LeafCountNode(TreeNode * node)
{
    if (node == nullptr) return 0;
    if ((node->left == nullptr) && (node->right == nullptr)) return 1;

    return LeafCountNode(node->left) + LeafCountNode(node->right);
}

void BST::InOrder()
{
    auto node = m_root;
    stack<TreeNode*> stack;
    if (node == nullptr) return;

    bool done = false;
    while (!done)
    {
        while (node->left != nullptr)
        {
            stack.push(node);
            node = node->left;          
        }
      
        cout << node->data << " ";

        if (!stack.empty())
        {
            while (node->right == nullptr)
            {
                node = stack.top();
                stack.pop();
                cout << node->data << " ";
            }
            if (node->right != nullptr)
            {
                node = node->right;
            }
        }
        else
        {
            done = true;
        }

    }
}

void BST::LevelByLevel()
{
    auto node = m_root;
    if (node == nullptr) return;
    queue<TreeNode *> queue;
    bool done = false;

    while (!done)
    {
        if (node->left != nullptr)
        {
            queue.push(node->left);
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
        }
        cout << node->data << " ";
        if (!queue.empty())
        {
            node = queue.front();
            queue.pop();
        }
        else
        {
            done = true;
        }
    }
}

bool BST::Delete(int item)
{
    auto node = m_root;
    if (node == nullptr) return false;

    bool found = false;
    auto parent = m_root;
    while (!found && node != nullptr)
    {
        if (node->data > item)
        {
            parent = node;
            node = node->left;
        }
        else if (node->data < item)
        {
            parent = node;
            node = node->right;
        }
        else
        {
            found = true;
        }
    }
    if (!found) return false;

    if (node->left == nullptr && node->right == nullptr)
    {
        if (parent->left != nullptr && parent->left->data == node->data)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete node;
        return true;
    }
    else if (node->left != nullptr && node->right == nullptr)
    {
        node->data = node->left->data;
        delete node->left;
        node->left = nullptr;
        return true;
    }
    else if (node->right != nullptr && node->left == nullptr)
    {
        node->data = node->right->data;
        delete node->right;
        node->right = nullptr;
        return true;
    }

    else if (node->left != nullptr && node->right != nullptr)
    {
        auto suc = node->right;
        auto par = node;
        while (suc->left != nullptr)
        {
            par = suc;
            suc = suc->left;
        }
        
        node->data = suc->data;
        par->right = suc->right;
        delete suc;
        suc = nullptr;
        return true;
        
       
    }

    return false;

}

int BST::NodeCount()
{
    return NodeCountAux(m_root);
}

int BST::NodeCountAux(TreeNode * node)
{
    if (node == nullptr) return 0;

    return 1 + NodeCountAux(node->left) + NodeCountAux(node->right);
}

bool BST::DeleteRec(int val)
{
    TreeNode * parent = nullptr;
    return DeleteRecAux(val, m_root,parent);
}

bool BST::DeleteRecAux(int val, TreeNode * node, TreeNode * par)
{
    if (node->data > val)
    {
        par = node;
        return DeleteRecAux(val, node->left, par);
    }
    else if (node->data < val)
    {
        par = node;
        return DeleteRecAux(val, node->right, par);
    }
    else
    {
        if (node->data != val) return false;
    }

    auto ptr = node;

    if (node->left == nullptr && node->right == nullptr)
    {
        if (par->left != nullptr && par->left->data == val)
        {
            par->left = nullptr;
        }
        else
        {
            par->right = nullptr;
        }
    }

    else if (node->left == nullptr)
    { 
        ptr = node->right;
        if (par->right != nullptr && par->right->data == node->data)
        {
            par->right = ptr;
        }
        else
        {
            par->left = ptr;
        }
        delete node;
        node = ptr;
        return true;
    }

    else if (node->right == nullptr)
    {
        ptr = node->left;
        if (par->right != nullptr && par->right->data == node->data)
        {
            par->right = ptr;
        }
        else
        {
            par->left = ptr;
        }
        delete node;
        node = ptr;
        return true;
    }
    else
    {
        auto suc = node->right;
        auto par = node;
        while (suc->left != nullptr)
        {
            par = suc;
            suc = suc->left;
        }
        node->data = suc->data;
        return DeleteRecAux(suc->data, suc, par);
    }

}