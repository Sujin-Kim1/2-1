#include "SLL.h"
#include <iostream>

using namespace std;

List::List() {
    head = 0;
}

void List::Insert_back(int val) {
    Node *temp = new Node(val);
    Node *p;

    if (head == 0) {
        head = temp;
    } else {
        p = head;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = temp;
    }
}

void List::Delete(int val) {
    Node *p, *q;

    if (head->data == val) {
        p = head;
        head = head->next;
        delete p;
    } else {
        p = head;
        while (p != 0 && p->data != val) {
            q = p;
            p = p->next;
        }
    }
    if (p != 0) {
        q->next = p->next;
        delete p;
    } else {
        cout << val << " is not in the list" << endl;
    }
}

bool List::IsEmpty() {
    return head == 0;
}

void List::TraverseList() {
    Node *p;

    if (!IsEmpty()) {
        p = head;
        while (p) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    } else {
        cout << "List is empty!" << endl;
    }
}

void List::SearchList(int val) {
    Node *p;

    if (head != 0) {
        p = head;
        while (p != 0 && p->data != val) {
            p = p->next;
        }
        if (p) {
            cout << p->data << " is found" << endl;
        } else {
            cout << val << " in not in the list" << endl;
        }
    } else {
        cout << "List is empty" << endl;
    }
}

List::~List() {
    Node *p;

    while (head != 0) {
        p = head;
        head = head->next;
        delete p;
    }
}