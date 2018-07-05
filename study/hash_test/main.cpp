//
// Created by Harry Bang on 2018-06-18.
//

#include "hashing.h"
#include <iostream>

int main() {
    hashing h;
    char ch;
    int key;

    do {
        std::cout << "Enter command (i, f, d, q): ";
        std::cin >> ch;
        if (ch != 'q') {
            std::cout << "Enter Key: ";
            std::cin >> key;
            switch (ch) {
                case 'i':
                    h.insertKey(key);
                    break;
                case 'f':
                    h.isFind(key);
                    break;
                case 'd':
                    h.deleteKey(key);
                    break;
                default:
                    std::cout << "Bad Command" << std::endl;
                    break;
            }
        }
        h.printTable();
    }
    while (ch != 'q');

    return 0;
}
