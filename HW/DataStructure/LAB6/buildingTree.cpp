#include <iostream>
#include "buildingTree.h"

using namespace std;
static char prec[5][2] = {'*', 2, '/', 2, '+', 1, '-', 1};

Node::Node(char value, int priority)
    : data(value), prio(priority), left(0), right(0)
{
}

Tree::Tree()
    : root(0)
{
}

Tree::~Tree()
{
    delete root;
}

Node* Tree::getRoot() const
{
    return root;
}

void Tree::buildTree(char* input)
{
    int i = 0;
    while (input[i] != '\0')
    {
        char data = input[i];
        Node *new_node = new Node(data, 4);
        for (int j = 0; j < 4; j++)
        {
            if (new_node->data == prec[j][0])
                new_node->prio = prec[j][1];
        }
        if (new_node->prio == 4)
            Operand(new_node);
        else
            Operator(new_node);
        i++;
    }
}

void Tree::Operand(Node *p)  // 숫자 - right
{
    if (root == NULL)
    {
        root = p;
        return;
    }
    Node *ptr = root;
    while (ptr->right != NULL)
        ptr = ptr->right;
    ptr->right = p;
}

void Tree::Operator(Node *p)  // left
{
    if (root->prio >= p->prio)
    {
        p->left = root;
        root = p;
    }
    else
    {
        p->left = root->right;
        root->right = p;
    }
}

void Tree::PreorderTraverse(Node *ptr)
{
    if (ptr)
    {
        std::cout << ptr->data;
        PreorderTraverse(ptr->left);
        PreorderTraverse(ptr->right);
    }
}

void Tree::InorderTraverse(Node *ptr)
{
    if (ptr)
    {
        InorderTraverse(ptr->left);
        std::cout << ptr->data;
        InorderTraverse(ptr->right);
    }
}

void Tree::PostorderTraverse(Node *ptr)
{
    if (ptr)
    {
        PostorderTraverse(ptr->left);
        PostorderTraverse(ptr->right);
        std::cout << ptr->data;
    }
}

int Tree::evalTree(Node *p)
{
    int value;

    if (p != NULL)
    {
        if (p->data - '0' >= 0 && p->data - '0' <= 9)
            value = p->data - '0';
        else
        {
            int left_v = evalTree(p->left);
            int right_v = evalTree(p->right);
            switch (p->data)
            {
            case '+':
                value = left_v + right_v;
                break;
            case '-':
                value = left_v - right_v;
                break;
            case '*':
                value = left_v * right_v;
                break;
            case '/':
                value = left_v / right_v;
                break;
            }
        }
    }
    else
        return value;
}