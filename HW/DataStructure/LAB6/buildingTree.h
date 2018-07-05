#pragma once

struct node
{
    char data;          // one character input per node
    int prio;           // priority number from precedence table
    struct node *left;  // left link
    struct node *right; // right link
};

class Node
{
  private:
    char data;
    int prio;
    Node *left;
    Node *right;
    Node(char, int);
    friend class Tree;
};

class Tree
{
  private:
    Node *root;
  public:
    Tree();
    ~Tree();
    Node* getRoot() const;
    void buildTree(char *);
    void Operand(Node *);
    void Operator(Node *);
    int evalTree(Node *);
    void PreorderTraverse(Node *);
    void PostorderTraverse(Node *);
    void InorderTraverse(Node *);
};