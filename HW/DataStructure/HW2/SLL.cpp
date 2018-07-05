#include <iostream>
#include "SLL.h"

/****************************************************************************************
 * function : constructor
 * description : setter 
 * variables : Student's name, ID, major, grade
 * **************************************************************************************/

Node::Node(char name, int ID, std::string major, char grade)
{
    this->name = name;
    this->ID = ID;
    this->major = major;
    this->grade = grade;
}

/***************************************************************************************
 * function : constructor
 * description : setting the head to 0
 * *************************************************************************************/

List::List()
{
    head = 0;
}

/***************************************************************************************
 * function : ~List()
 * description : destructor that returns each node of the linked list to the system
 * variables : p - a pointer that point out the head 
 * *************************************************************************************/

List::~List()
{
    Node *p;

    while (head != 0)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

/**************************************************************************************
 * function : insertNode
 * description : insert a node into a list in name order
 * variables : temp - a node which we insert into the list
 *             p, q - variables to indicate before and after nodes to be inserted
 * ************************************************************************************/

void List::insertNode(char name, int ID, std::string major, char grade)
{
    Node *temp = new Node(name, ID, major, grade);
    Node *p, *q;
    if (head == 0) // the first node is created
        head = temp;
    else if (temp->name < head->name) // the node is inserted before the node
    {
        temp->next = head;
        head = temp;
    }
    else // the node is inserted in the middle of the linked list
    {
        p = head;
        while ((p != 0) && (p->name < temp->name))
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
            q->next = temp;
        }
        else
        {
            q->next = temp;
        }
    }
}

/**************************************************************************************
 * function : deleteNode
 * description : delete a node in a list
 * variables : p, q - variables for finding and erasing name
 * ************************************************************************************/

void List::deleteNode(char name)
{
    Node *p, *q;

    if (head->name == name) // head 삭제
    {
        p = head;
        head = head->next;
        delete p;
    }
    else
    {
        p = head;
        while (p != 0 && p->name != name)
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            q->next = p->next;
            delete p;
        }
        else
        {
            std::cout << name << "is not in the list" << std::endl;
        }
    }
}

/**************************************************************************************
 * function : isEmpty
 * description : a function that check the list is empty
 * ************************************************************************************/

bool List::isEmpty()
{
    return head == 0;
}
/**************************************************************************************
 * function : traverse
 * description : print out the contents of the list
 * variables : p - variable to indicate the element of the list
 * ************************************************************************************/

void List::traverse()
{
    Node *p;

    if (!isEmpty())
    {
        p = head;
        while (p)
        {
            std::cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << std::endl;
            p = p->next;
        }
    }
    else
        std::cout << "List is empty!" << std::endl;
}
/**************************************************************************************
 * function : search
 * description : search and print the nodes that correspond to the grades entered
 * variables : p - a variable that determines if it matches the grade entered 
 * ************************************************************************************/

void List::search(char grade)
{
    Node *p;

    if (head != 0)
    {
        p = head;
        while (p != 0)
        {
            if (p->grade == grade)
            {
                std::cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << std::endl;
            }
            p = p->next;
        }
    }
    else
        std::cout << "List is empty" << std::endl;
}

/**************************************************************************************
 * function : search
 * description : search and print the nodes that correspond to the major entered
 * variables : p - a variable that determines if it matches the major entered  
 * ************************************************************************************/

void List::search(std::string major)
{
    Node *p;

    if (head != 0)
    {
        p = head;
        while (p != 0)
        {
            if (p->major == major)
            {
                std::cout << p->name << " " << p->ID << " " << p->major << " " << p->grade << std::endl;
            }
            p = p->next;
        }
    }
    else
        std::cout << "List is empty" << std::endl;
}

/**************************************************************************************
 * function : addList
 * description : add the list to the previous list
 * variables : p - a variable that indicates list's head entered
 * ************************************************************************************/

void List::addList(List &list)
{
    Node *p;
    p = list.head;
    while (p)
    {
        insertNode(p->name, p->ID, p->major, p->grade);
        p = p->next;
    }
}