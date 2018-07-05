#include <iostream>
#include <list>
#include <vector>
#include <cstring>

template<typedef T &>
class MyVector {
public:
    MyVector()
            : val(nullptr), reserve_size(32), data_size(0) {
        val = new T[reserve_size];
    }

    ~MyVector() {
        if (val != nullptr) {
            delete[] val;
            val = nullptr;
            reserve_size = 0;
            data_size = 0;
        }
    }

    void push_back(const T &i) {
        if (data_size + 1 > reserve_size) {
            int *p = new T[reserve_size * 2];
            memcpy(p, val, sizeof(int) * data_size);

            delete[] val; // 주소 적은 종이 쪽지인 val 은 아직 살아있음
            val = p;

            reserve_size *= 2;
        }

        val[data_size] = i;
        ++data_size;
    }

    T operator[](unsigned int idx) const {
        return val[idx];
    }

    T &operator[](unsigned int idx) {
        return val[idx];
    }

    unsigned int size() const {
        return data_size;
    }

private:
//    int val[128];  크기가 정해지면 벡터처럼 사용 불가능
    T *val;
    unsigned int reserve_size;  // 메모리를 담은 size
    unsigned int data_size;  // 의미있는 데이터의 size
};

void print(const std::list<int> &a);

class Person {
public:
    Person() : id(-1) {}

    Person(const int _id) : id(_id) {}

    int get_id() const { return id; }

private:
    unsigned int id;
};

std::ostream &operator<<(std::ostream &os, const Person p) {
    os << p.get_id();
    return os;
}

int main() {
    std::list<int> l;
    std::list<int>::iterator it;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    l.insert(l.begin(), 5);

    print(l);

    std::vector<double> arr;

    arr.push_back(3.5);
    arr.push_back(-3.5);
    arr.push_back(2.5);
    arr.push_back(1.5);
    arr.push_back(-7.5);

    // typedef unsigned int128 size_t;

    for (std::size_t i = 0; i < arr.size(); ++i) // stl 에서 size 를 나타내는 모든 변수를 size_t 로 나타내도록 하는 게 정석
        std::cout << arr[i] << std::endl;

    MyVector<int> array;

    for (unsigned int i = 0; i < 9; i++) {
        array.push_back(3);
        array.push_back(-3);
        array.push_back(2);
        array.push_back(1);
        array.push_back(-7);
    }

    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << array[i] << std::endl;

    MyVector<Person> arr1;

    for (unsigned int i = 0; i < 9; ++i) {
        arr1.push_back(Person(3));
    }
    return 0;
}

void print(const std::list<int> &a) {
    std::list<int>::const_iterator it;
    // 가리키는 애이기 때문에 void print(const std::list<int> &a)로 하면 에러남
    // ex) *it = 100;
    // -> const_iterator 사용

    for (it = a.begin(); it != a.end(); it++) {
        std::cout << *it << std::endl;
    }

}