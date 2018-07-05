#include <iostream>
#include "stack.h"
#include "queue.h"
#include "circularQueue.h"

int main(void)
{
    Stack s;
    Queue q;
    CircularQueue circularQ;

    s.PUSH('a');
    q.ENQUE('b');
    q.ENQUE('c');
    q.ENQUE('d');
    s.PUSH('e');
    s.PUSH('a');
    q.ENQUE('a');
    s.DisplayStack();
    q.DisplayQueue();
    s.POP();
    q.DEQUE();
    q.DEQUE();
    q.DEQUE();
    s.POP();
    s.POP();
    q.DEQUE();
    circularQ.enque('a');
    circularQ.enque('b');
    circularQ.enque('c');
    circularQ.DisplayCircularQueue();    
    circularQ.deque();
    circularQ.DisplayCircularQueue();    
    circularQ.enque('a');
    circularQ.DisplayCircularQueue();
    circularQ.deque();
    circularQ.deque();
    circularQ.deque();
}