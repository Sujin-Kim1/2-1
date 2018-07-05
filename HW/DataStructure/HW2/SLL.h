#pragma once
#include <string>

/*****************************************************************************************************
 * class : Node
 * description : Node class consists of two fields
 *                 - data and pointer to next node
 * **************************************************************************************************/

class Node
{
  private:
    char name, grade;
    int ID;
    std::string major;

    Node *next;
    Node(char, int, std::string, char);
    friend class List;
};

/*****************************************************************************************************
 * class : List
 * description : ordered sequence of nodes
 * variables : 
 *          ~Link() : A function that returns each node of the linked list to the system 
 *          void insertNode(char, int, string, char) : A function to insert a node into a linked list
 *          void deleteNode(char) : A function to delete a node in a linked list
 *          bool isEmpty() : A function that check for empty link lists
 *          void traverse() : Output contents of nodes of linked list
 *          void search(char) : A function to find data with specific grades in a linked list
 *          void search(string) : A function to find data with a specific major in a linked list 
 *          void addList(List&) : add list to previous list
 * **************************************************************************************************/

class List
{
  private:
    Node *head;

  public:
    List();
    ~List();
    void insertNode(char, int, std::string, char);
    void deleteNode(char);
    bool isEmpty();
    void traverse();
    void search(char);
    void search(std::string);
    void addList(List&);
};