//
// Created by Harry Bang on 2018-06-18.
//

#ifndef STUDY_HASHING_H
#define STUDY_HASHING_H
#define MAX_SIZE 7

typedef struct {
    int key = 0;
    bool empty = true;
} hashtable;



class hashing {
public:
    bool staticFindKey(int k);

    bool LinearFindKey(int k);

    void insertKey(int k);

    void deleteKey(int k);

    void printTable() const;

    int hashingFunction(int k);

    void isFind(int k);

private:
    hashtable htable[MAX_SIZE];
};



#endif //STUDY_HASHING_H
