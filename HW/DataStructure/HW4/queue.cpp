#include <iostream>
#include <cstdlib>
#include "queue.h"

/* **********************************************************************
 * constructor : Queue()
 * description : front, rear 를 -1 로 초기화한다.
 * ************************************************************************ */

Queue::Queue()
        : front(-1), rear(-1) {
}

/* **********************************************************************
 * function : ENQUE(int item)
 * description : Qfull 일 때 메세지를 출력하고, Qfull 이 아닐 때 item 을 뒤에
 * 삽입한다.
 * ************************************************************************ */

void Queue::ENQUE(int item) {
    if (QFull()) {
        std::cout << "Queue Full" << std::endl;
        std::exit(1);
    } else
        queue[++rear] = item;
}

/* **********************************************************************
 * function : DEQUE()
 * description : QEmpty 일 때 메세지를 출력하고, QEmpty 가 아닐 때 맨 앞에 있는
 * 원소를 반환한다.
 * ************************************************************************ */

int Queue::DEQUE() {
    if (QEmpty()) {
        std::cout << "QUEUE EMPTY" << std::endl;
        std::exit(1);
    } else
        return queue[++front];
}

/* **********************************************************************
 * function : QEmpty() const
 * description : queue 가 비어있는지 확인한다.
 * ************************************************************************ */

bool Queue::QEmpty() const {
    return rear == front;
}

/* **********************************************************************
 * function : isFull() const
 * description : Queue 의 rear 가 MAX_QUEUE_SIZE - 1 과 같은지 확인한다.
 * ************************************************************************ */

bool Queue::QFull() const {
    return rear == MAX_QUEUE_SIZE - 1;
}