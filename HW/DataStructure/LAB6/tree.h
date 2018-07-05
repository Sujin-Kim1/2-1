#pragma once

struct node
{
    char data;
    int prio;
    struct node *left;
    struct node *right;
}

class Node
{
  private:
    char data;
    Node *left;
    Node *right;
    Node(int value);
    friend class Tree;
};

class Tree
{
  private:
    Node *root;

  public:
    Tree();
    ~Tree();
    void new_node(Node *);
    Node *insertBSTree(Node *, int);
    void deleteTree(Node *, int);
    Node *deleteBSTree(Node *, int);
    void searchTree(Node *, int);
    Node *searchBSTree(Node *, int);
    // void traverseTree();
    void PreorderTraverse(Node *);
    void InorderTraverse(Node *);
    void PostorderTraverse(Node *);
    void drawTree();
    void drawBSTree(Node *, int);
    Node *findmin(Node *p);
    bool tree_empty();
    void freeBSTree(Node *);
};
