#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
    Queue::front = -1;
    Queue::rear = -1;
}

void Queue::EnQueue(int val) {
    if (Queue::IsFull()) {
        cout << "Queue Full" << endl;
    } else {
        queue[++rear] = val;
    }
}

int Queue::DeQueue() {
    if (Queue::IsEmpty()) {
        cout << "Queue Empty" << endl;
    } else {
        return queue[++front];
    }
}

bool Queue::IsFull() {
    if (rear == queueSize - 1) {
        return true;
    } else {
        return false;
    }
}

bool Queue::IsEmpty() {
    if (front == rear) {
        return true;
    } else {
        return false;
    }
}

void Queue::DisplayQueue() {
    int i;

    if (IsEmpty()) {
        cout << "Queue is Empty" << endl;
    } else {
        i = front + 1;
        while (i <= rear) {
            cout << queue[i] << endl;
            i++;
        }
    }
}