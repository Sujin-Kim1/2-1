#include "Hashing.h"
#include <iostream>

bool Hashing::staticFindKey(int k) {
    index = hashingFunction(k);
    return htable[index].key == k;
}

bool Hashing::LinearFindKey(int k) {
    index = hashingFunction(k);
    int copyIndex = index;
    bool found = false, loop = false;

    while (!htable[index].empty && !found && !loop) {
        if (htable[index].key == k)
            found = true;
        else {
            index = (index + 1) % MAX_SIZE;
            if (index == copyIndex)
                loop = false;
        }
    }
    return found;
}

void Hashing::insertKey(int k) {
    bool check = LinearFindKey(k);
    index = hashingFunction(k);
    int copyIndex = index;

    if (check)  // no duplicated key
        return;
    while (!htable[index].empty) {
        index = (index + 1) % MAX_SIZE;
        if (index == copyIndex) {
            std::cout << "Cannot insert key" << std::endl;
            return;
        }
    }
    htable[index].key = k;
    htable[index].empty = false;
}

void Hashing::deleteKey(int k) {
    bool check = LinearFindKey(k);

    if (!check)
        return;
    htable[index].empty = true; // marking
    htable[index].key = 0;
}

void Hashing::printTable() const {
    for (int i = 0; i < MAX_SIZE; i++) {
        std::cout << htable[i].key << " ";
    }
    std::cout << std::endl;
}

int Hashing::hashingFunction(int k) {
    return k % MAX_SIZE;
}

void Hashing::isFind(int k) {
    bool check = LinearFindKey(k);
    if (check)
        std::cout << "Found " << k << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}
