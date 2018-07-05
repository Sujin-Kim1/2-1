#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;
    dq.push_back(99);
    dq.push_back(1);
    dq.push_front(35);
    dq.push_front(67);

    std::deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++) {
        std::cout << *it << std::endl;
    }
}
