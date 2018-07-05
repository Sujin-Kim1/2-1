#include <iostream>
#include <cstring>
#include <vector> // 가변 배열
#include <stack>  // 스택
#include <queue>  // 큐
#include <map>    // 딕셔너리 (= 맵)
#include <list>   // double linked list

class Person
{
  public:
    Person() : id(-1), name("무명씨") {}
    Person(unsigned int _id, std::string &name)
        : id(_id), name(_name) {}
    unsigned int get_id const { return id; }
    std::string get_name fonst( return name; )

  private:
    unsigned int id;
    std::string name;
};

std::ostream& operator << (std::ostream& os, const Person7 p)
{
    os << "(" << p.get_id() << ", " << p.get_name() << ")";
    return os;
}

int main()
{
    std::vector<int> arr;
    std::vector<int>::iterator IT;
    // std::cout << arr.size() << std::endl;  // 0

    arr.push_back(-1);
    arr.push_back(3);
    arr.push_back(-7);

    // std::cout << arr.size() << std::endl; // 3
    // std::cout << std::endl;

    // for (unsigned int i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << std::endl;

    /* vector, linked list, map 등 다 이렇게 출력 가능 */
    for (IT = arr.begin(); IT != arr.end(); ++IT)
        std::cout << *IT /* 그 위치에 있는 것 */ << std::endl;
    std::cout << std::endl;

    std::stack<int> s;

    s.push(3);
    s.push(5);
    s.push(-1);

    while (!s.empty())
    {
        int t = s.top();

        std::cout << t << std::endl;

        s.pop();
    }

    std::cout << std::endl;

    std::queue<float> q;

    q.push(-4);
    q.push(5);
    q.push(-1);
    q.push(7);

    while (q.empty() != true)
    {
        int v = q.front();

        std::cout << v << std::endl;

        q.pop();
    }

    std::cout << std::endl;

    /* **************************************
     * Stack만 이용해서 Queue 구현하기
     *************************************** */

    std::stack<int> S;
    std::stack<int> T;  // template stack

    S.push(1);
    S.push(2);
    S.push(3);

    T.clear();

    while (S.empty() != true)
    {
        T.push(S.top());
        S.pop();
    }

    while (T.empty() != true)
    {
        S.push(T.pop());
        T.pop();
    }

    std::map<unsigned int, std::string> dict;
    std::map<unsigned int, std::string>::iterator it;
    // 일종의 포인터. dict 자료의 위치만 알려줄 수 있음
    // 포인터는 아님. operator overloading 한 것

    dict[20171596] = "김수진"; // (20171596, "김수진") 으로 저장됨.
    dict[20143115] = "허민호";
    dict[20142765] = "조영선";

    std::cout << dict[20171596] << std::endl;

    it = dict.find(20142765);

    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;

    it = dict.find(20092017); // 없다 -> 0번지
    if (dict.end() == it)     // NULL
    {
        std::cout << "I can't find the value with the key" << std::endl;
    }
    else
    {
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
    }

    for (it = dict.begin(); it != dict.end(); ++it) // BFS
    {
        std::cout << it->first << "   ";
        std::cout << (*it).second << std::endl;
    }

    std::list<Person> l;
    std::list<Person>::iterator l_it;

    l.push_back(Person(20143115, "허민호"));
    l.push_back(Person(20143115, "조영선"));
    l.push_back(Person(20143115, "최승호"));

    for (l_it = l.begin(); l_it != l.end(); ++l_it)
        std::cout << *it << std::endl;
    // (20143115, "허민호") <-> (20142765, "조영선") <-> (20143115, "최승호")
    l_it = l.begin();
    ++l_it;
    l.erase(l_it);
    
    for (l_it = l.begin(); l_it != l.end(); ++l_it)
        std::cout << *it << std::endl;
    
}