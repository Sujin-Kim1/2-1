//
// Created by Harry Bang on 2018-06-18.
//

#include "hashing.h"
#include <iostream>

bool hashing::staticFindKey(int k) {
    int index = hashingFunction(k);
    return htable[index].key == k;
}

bool hashing::LinearFindKey(int k) {
    bool found = false;
    int index = hashingFunction(k);
    int copyIndex = index;
    bool loop= false;

    while (!htable[index].empty && !found && !loop) {
        if (htable[index].key == k)
            found = true;
        else {
            index = (index + 1) % MAX_SIZE;
            if (index == copyIndex)
                loop = true;
        }
    }
    return found;
}

void hashing::insertKey(int k) {
    bool check = LinearFindKey(k);
    if (check)
        return;
    int index = hashingFunction(k);
    while (!htable[index].empty) {
        index = (index + 1) % MAX_SIZE;
    }
    htable[index].key = k;
    htable[index].empty = false;
}

void hashing::deleteKey(int k) {
    bool check = LinearFindKey(k);
    if (!check)
        return;
    int index = hashingFunction(k);
    while (htable[index].key != k) {
        index = (index + 1) % MAX_SIZE;
    }
    htable[index].empty = true;
    htable[index].key = 0;
}

void hashing::printTable() const {
    for (int i = 0; i < MAX_SIZE; i++) {
        std::cout << htable[i].key << " ";
    }
    std::cout << std::endl;
}

int hashing::hashingFunction(int k) {
    return k % MAX_SIZE;
}

void hashing::isFind(int k) {
    bool check = LinearFindKey(k);
    if (check)
        std::cout << "Found " << k << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}
