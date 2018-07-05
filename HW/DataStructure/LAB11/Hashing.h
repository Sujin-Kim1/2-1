#ifndef LAB11_HASHING_H
#define LAB11_HASHING_H
#define MAX_SIZE 7

typedef struct {
    int key = 0;
    bool empty = true;
} hashtable;



class Hashing {
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
    int index;
};


#endif //LAB11_HASHING_H
