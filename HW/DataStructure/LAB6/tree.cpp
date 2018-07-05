#include <iostream>
#include "tree.h"

Node::Node(int value)
{
    data = value;
    left = 0;
    right = 0;
}

Tree::Tree()
{
    root = 0;
}

Tree::~Tree()
{
    freeBSTree(root);
}

Node Tree::new_node(Node *ptr)
{
    root = ptr->root;
}


Node Tree::insertBSTree(Node *ptr, int key)
{
    if (ptr == NULL)
    {
        new_node(ptr);
        ptr->data = key;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if (key < ptr->data)
        ptr->left = insertBSTree(ptr->left, key);
    else if (key > ptr->data)
        ptr->right = insertBSTree(ptr->right, key);
    return ptr;
}

void Tree::deleteTree(Node *ptr, int key)
{

}

Node Tree::deleteBSTree(Node *ptr, int key)
{
    if (ptr != NULL)
        ptr->left = deleteTree(ptr->left, key);  // move to the node
    else if (key > ptr->data)
        ptr->right = deleteTree(ptr->right, key);  // arrived at the node
    else if ((ptr->left == NULL) && (ptr->right == NULL))
        ptr = NULL;   // leaf
    else if (ptr->left == NULL)
    {
        // right child only
        Node *p = ptr;
        ptr = ptr->right;
        deleteTree(p);
    }
    else if (ptr->right == NULL)
    {
        // left child only
        Node *p;
        ptr = ptr->left;
        delete(p);
    }
    else 
    {
        // both child exists
        Node *temp = find_min(ptr->right);
        ptr->data = temp->data;
        ptr->right = delete(ptr->right, ptr->data);
    }
}

void Tree::searchTree(Node *ptr, int key)
{

}

Node Tree::searchBSTree(Node *ptr, int key)
{
    if (ptr == NULL)
        return NULL;
    else 
    {
        if (key == p->data)
            return ptr;
        else if (key < ptr->data)
            ptr = searchBSTree(ptr->left, key);
        else 
            ptr = searchBSTree(ptr->right, key);
    }
    return ptr;
}

void Tree::PreorderTraverse(Node *ptr)
{
    if (ptr)
    {
        std::cout << ptr->data << " ";
        PreorderTraverse(ptr->left);
        PreorderTraverse(ptr->right);
    }
    std::cout << std::endl;    
}

void Tree::InorderTraverse(Node *ptr)
{
    if (ptr)
    {
        InorderTraverse(ptr->left);
        std::cout << ptr->data << " ";
        InorderTraverse(ptr->right);
    }
    std::cout << std::endl;
}

void Tree::PostorderTraverse(Node *ptr)
{
    if (ptr)
    {
        PostorderTraverse(ptr->left);
        PostorderTraverse(ptr->right);
        std::cout << ptr->data << " ";
    }
    std::cout << std::endl;
}

void Tree::drawTree()
{
    drawBSTree(Node *root, 1);
}

void Tree::drawBSTree(Node *p, int level)
{
    if (p != 0 && level <= 7)
    {
        drawBSTree(p->right, level + 1);
        for (int i = 1; i <= level - 1; i++)
            std::cout << " ";
        std::cout << p->data;
        if (p->left != 0 && p-> right != 0)
            std::cout << " <" << std::endl;
        else if (p->right != 0)
            std::cout << " /" << std::endl;
        else if (p->left != 0)
            std::cout << " \\" << std::endl;
        else
            std::cout << std::endl;
        drawBSTree(p->left, level + 1);
    }
}

Node Tree::findmin(Node *p)
{

}

bool Tree::tree_empty()
{
    return root == 0;
}

void Tree::freeBSTree(Node *p)
{
    delete p;
}