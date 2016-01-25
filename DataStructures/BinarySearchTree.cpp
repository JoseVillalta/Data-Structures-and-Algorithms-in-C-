#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
BST<T>::BST()
{
    m_root = nullptr;
}
template<typename T>
TreeNode<T> * BST<T>::Search(T key)
{
    TreeNode<T> * node = m_root;
    if (m_root == nullptr) return node;
    if (m_root->data == key) return node;

   return SearchNode(node, key);


}

template<typename T>
void BST<T>::Insert(T key)
{
    if (m_root == nullptr)
    {
        m_root = new TreeNode<T>();
        m_root->data = key;
    }
    else
    {
        InsertNode(m_root, key);
    }

}

template<typename T>
void BST<T>::InsertNode(TreeNode<T> * root, T val)
{

    if (root->data > val)
    {
        if (root->left == nullptr)
        {
            root->left = new TreeNode<T>(val);
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
            root->right = new TreeNode<T>(val);
        }
        else
        {
            InsertNode(root->right, val);
        }     
    }
}

template<typename T>
TreeNode<T> * BST<T>::SearchNode(TreeNode<T> * root, T key)
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

template<typename T>
int BST<T>::Level(T key)
{
    int level = 1;
    TreeNode<T> * nodePtr = m_root;
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

template<typename T>
int BST<T>::RecLevel(T key)
{
    if (m_root == nullptr) return -1;
    auto level = RecLevelNode(m_root, key);
    if (level < 0)
    {
        cout << "Item not found" << endl;
    }
    return level;
}

template<typename T>
int BST<T>::RecLevelNode(TreeNode<T> * nodePtr, T key)
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

template<typename T>
int BST<T>::Height()
{
    if (m_root == nullptr) return 0;

    return HeightNode(m_root);
}
template<typename T>
int BST<T>::HeightNode(TreeNode<T> * nodePtr)
{
    if (nodePtr == nullptr) return 0;

    return max(1 + HeightNode(nodePtr->left), 1 + HeightNode(nodePtr->right));
}
template<typename T>
void BST<T>::TraverseInOrder()
{
    InOrderTrav(m_root);
}
template<typename T>
void BST<T>::InOrderTrav(TreeNode<T> * node)
{
    if (node == nullptr) return;
    
    InOrderTrav(node->left);

    cout << node->data << " " << endl;

    InOrderTrav(node->right);
}
template<typename T>
void BST<T>::TraversePreOrder()
{
    PreOrderTrav(m_root);
}
template<typename T>
void BST<T>::PreOrderTrav(TreeNode<T>* node)
{
    if (node == nullptr) return;

    cout << node->data << " " << endl;

    PreOrderTrav(node->left);
    PreOrderTrav(node->right);
}
template<typename T>
void BST<T>::TraversePostOrder()
{
    PostOrderTrav(m_root);
}
template<typename T>
void BST<T>::PostOrderTrav(TreeNode<T> * node)
{
    if (node == nullptr) return;

    PostOrderTrav(node->left);
    PostOrderTrav(node->right);
    
    cout << node->data << " " << endl;
}
template<typename T>
void BST<T>::Trace()
{
    TraceInderOrder(m_root);
}
template<typename T>
void BST<T>::TraceInderOrder(TreeNode<T> * node)
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
template<typename T>
void BST<T>::Display()
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
template<typename T>
void BST<T>::DisplayPreOrder(TreeNode<T> * node)
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
template<typename T>
int BST<T>::LeafCount()
{
    return LeafCountNode(m_root);
}
template<typename T>
int BST<T>::LeafCountNode(TreeNode<T> * node)
{
    if (node == nullptr) return 0;
    if ((node->left == nullptr) && (node->right == nullptr)) return 1;

    return LeafCountNode(node->left) + LeafCountNode(node->right);
}
template<typename T>
void BST<T>::InOrder()
{
    auto node = m_root;
    stack<TreeNode<T>*> stack;
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
template<typename T>
void BST<T>::LevelByLevel()
{
    auto node = m_root;
    if (node == nullptr) return;
    queue<TreeNode<T> *> queue;
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
template<typename T>
void BST<T>::Delete(T item)
{    
    DeleteAux(item, m_root);
}
template<typename T>
void BST<T>::DeleteAux(T item, TreeNode<T> * node)
{
    bool found = false;
    TreeNode<T> * parent = nullptr;
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
    if (!found) return;

    //No children
    if (node->left == nullptr && node->right == nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->left->data == node->data)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else
        {
            if (m_root->data == node->data)
            {
                m_root = nullptr;
            }
        }
        delete node;
    }
    //one child on left 
    else if (node->left != nullptr && node->right == nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->left->data == node->data)
            {
                parent->left = node->left;
            }
            else
            {
                parent->right = node->left;
            }
        }
        else
        {
            if (m_root->data == node->data)
            {
                m_root = node->left;
            }
        }
        delete node;
    }
    //one child on right
    else if (node->right != nullptr && node->left == nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->right->data == node->data)
            {
                parent->right = node->right;
            }
            else
            {
                parent->left = node->right;
            }
        }
        else
        {
            if (m_root->data == node->data)
            {
                m_root = node->right;
            }
        }
        delete node;
    }
    else
    {
        TreeNode<T> * suc = node->right;
        while (suc->left != nullptr)
        {
            suc = suc->left;
        }

        auto temp = suc->data;
        DeleteAux(temp, node);
        node->data = temp;
    

    }
}
template<typename T>
int BST<T>::NodeCount()
{
    return NodeCountAux(m_root);
}
template<typename T>
int BST<T>::NodeCountAux(TreeNode<T> * node)
{
    if (node == nullptr) return 0;

    return 1 + NodeCountAux(node->left) + NodeCountAux(node->right);
}
template<typename T>
bool BST<T>::DeleteRec(T val)
{
    TreeNode<T> * parent = nullptr;
    return DeleteRecAux(val, m_root,parent);
}

template<typename T>
bool BST<T>::DeleteRecAux(T val, TreeNode<T> * node, TreeNode<T> * par)
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
        return true;
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

template BST<int>::BST();
template TreeNode<int>* BST<int>::Search(int Item);
template void BST<int>::Insert(int Item);
template int BST<int>::Level(int Item);
template int BST<int>::RecLevel(int Item);
template void BST<int>::Delete(int Item);
template bool BST<int>::DeleteRec(int Item);
template void BST<int>::TraverseInOrder(void);
template void BST<int>::TraversePreOrder(void);
template void BST<int>::TraversePostOrder(void);
template void BST<int>::InOrder(void);
template void BST<int>::LevelByLevel(void);
template void BST<int>::Trace(void);
template void BST<int>::Display(void);
template int BST<int>::Height(void);
template int BST<int>::LeafCount(void);
template int BST<int>::NodeCount(void);