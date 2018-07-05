#include <iostream>
#include <vector>
#include <list>
#inclide <pair>
#include <map>

std::pair<int, double> p; // 두 개의 자료형을 묶어서 하나의 쌍으로 만들고 싶을 때 사용

std::map<unsigned int, std::string> dict;

std::pair<unsigned int, std::string> dict;

using namespace std;

int main()
{
    std::vector<int> arr;
    std::vector<int>::iterator it;

    arr.reserve(3000); // 메모리를 미리 잡아두는 것
    // 만약에 내가 3000개의 원소를 넣고 싶은데,
    // 매번 push_back 을 하면 메모리를 만들었다가 지웠다가를
    // 반복하기 때문에 속도가 느려짐. 그래서 미리 공간을 만듦.

//    std::vector<int> arr(10);
//    int arr[10];  위 아래

    // arr[0] - arr[7]
    // size.size == 0
    arr.push_back(-1);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(-1);
    arr.push_back(1);
        arr.push_back(5);
    arr.push_back(-1);
    arr.push_back(1);
    arr.push_back(5);

    arr[0];
    arr[1];
    arr[2];
    arr[4]; // error

    it = arr.begin();
    ++it;

    arr.erase(it);

    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    it = arr.begin() + 5;
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::list<int> l;
    std::list<int>::iterator lit;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    lit = l.begin();
    ++lit;
    l.insert(lit, -1);
    for (lit = l.begin(); lit != l.end(); ++lit)
        std::cout << *lit << " ";
    std::cout << std::endl;

}