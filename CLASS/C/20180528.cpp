#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

class Person
{
  public:
    int id;
    std::string name;
};
/* 원하는 기준으로 sorting하고 싶을 때 */
// C : function pointer
// C++ : function object (functor)
class IDGreater
{
  public:
    // sorting
    bool operator()(const Person &p1, const Person &p2) const
    // functor 는 < 대신 함수 사용
    {
        return (p1.id > p2.id) ? true : false;
        // IDGreater class's member function
    }
};

class IDLess
{
  public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return (p1.id < p2.id) ? true : false;
    }
};

class NameGreater
{
  public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return (p1.name > p2.name) ? true : false;
    }
};

class NameLess
{
  public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return (p1.name < p2.name) ? true : false;
    }
};
/* class에 public만 있는거나, struct로 만들거나 똑같기 때문에
    struct NameLess
    {
        bool operator() ~
    } 
    이렇게 짜는 거랑 똑같음 */

class vec2f
{
  public:
    // r - values operator
    float operator()(unsigned int idx) const
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }
    // l-value operator
    float &operator()(unsigned int idx)
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }

  private:
    float x, y;
};

class vec2d
{
  public:
    // r - values operator
    double operator()(unsigned int idx) const
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }
    // l-value operator
    double &operator()(unsigned int idx)
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }

  private:
    double x, y;
};

std::ostream &operator<<(std::ostream &os, const vec2f &v)
{
    os << "[" << v(0) << ", " << v(1) << "]" << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const vec2d &v)
{
    os << "[" << v(0) << ", " << v(1) << "]" << std::endl;
    return os;
}
// => 반복이 심함

/* ************************************************************************ 
 * C macro
 * -> (확장) C++ template 
 * ************************************************************************ */

#define MAX(X, Y) ((X > Y) ? true : false)
// preprocessor 일종의 macro

template <typename T> 
// Type의 이름을 T로 정의 - int, float, vec2... 다 가능
// 실존 코드X
class vec2
{
  public:
    //r - values operator
    T operator()(unsigned int idx) const
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }
    // l-value operator
    T& operator()(unsigned int idx)
    {
        if (idx == 0)
            return x;
        else if (idx == 1)
            return y;
        assert(0);
    }

  private:
    T x, y;
};
// template 범위는 {}

// template <typename T>
// T vec2<T>::operator() (unsigned int idx) const
// {
//     if (idx == 0)
//         return x;
//     else if (idx == 1)
//         return y;
// }

// 실존 코드
vec2<float> a_, b_;
vec2<double> c_, d_;
vec2<int> e_, f_;

template <typename T>
std::ostream &operator<<(std::ostream &os, const vec2<T>& v)
{
    os << "[" << v(0) << ", " << v(1) << "]" << std::endl;
    return os;
}

typedef vec2<float> vec2F; // -> vec2<float>를 vec2F로 대체 할 수 있음

template <typedef T, unsigned int N>
class vec 
{
    public: 
    // r - value
    T operator() (unsigned int idx) const
    {
        assert (idx < N);
        return val[idx];
    }
    // l - value
    T &operator() (unsigned int idx) 
    {
        assert (idx < N);
        return val[idx];
    }
    
    private:
    T val[N];
};

template <typename T, unsigned int N>
std::ostream& operator << (std::ostream& os, const vec<T, N>& v)
{
    os << "[";
    for (unsigned int i = 0; i < N; i++)
        os << v(i) << " ";
        return os;
}

// 2차원 배열
typedef vec<float, 2> vecf;
typedef vec<double, 2> vecd;
typedef vec<int, 2> veci;
// 3차원 배열
typedef vec<float, 3> vecf;
typedef vec<double, 3> vecd;
typedef vec<int, 3> veci;
// 4차원 배열
typedef vec<float, 4> vecf;
typedef vec<double, 4> vecd;
typedef vec<int, 4> veci;

int main()
{
    Person stu[3];
    IDGreater idg;
    NameGreater nameg;
    // function object : 함수만 가지고 있는 객체
    // java의 compare함수

    stu[0].id = 20141757;
    stu[0].name = "Sunghwan Park";

    stu[1].id = 20171636;
    stu[1].name = "Hyunkee Sohn";

    stu[2].id = 20152852;
    stu[2].name = "Junghyun Lee";

    std::sort(stu, stu + 3, idg);
    // 처음부터 3번째 원소까지 idg의 sort 방법으로 sort
    /* if (_______ < _______) 가 수행됨.
       int와 같이 컴파일러에 이미 정의된 타입을 쓰면 에러X
       Person과 같이 내가 정의한 타입을 사용하면 operator overloading해야 함 */

    std::cout << stu[0].id << "     " << stu[0].name << std::endl;
    std::cout << stu[1].id << "     " << stu[1].name << std::endl;
    std::cout << stu[2].id << "     " << stu[2].name << std::endl;
    std::cout << std::endl;

    std::sort(stu, stu + 3, nameg);

    std::cout << stu[0].id << "     " << stu[0].name << std::endl;
    std::cout << stu[1].id << "     " << stu[1].name << std::endl;
    std::cout << stu[2].id << "     " << stu[2].name << std::endl;
    std::cout << std::endl;

    vec2f i, j;
    i(0) = 3.2f;
    i(1) = 1.5f;
    j(0) = 1.2f;
    j(1) = -1.3f;

    // getter
    std::cout << i;
    std::cout << "[" << j(0) << ", " << j(1) << "]" << std::endl;

    int p, q;
    p = 3;
    q = 5;

    bool r = MAX(p, q);
    // ((p > q) ? true : false)

    float a, b;
    a = 1.2f;
    b = -3.5f;

    r = MAX(a, b); // type과 상관 없이 코드 돌아감

    vec2<float> _a;
    vec2F _b;
    vec2<int> _c, _d;

    _a(0) = 3.2f;
    _a(1) = 1.5f;
    _b(0) = 1.2f;
    _b(1) = -1.3f;

    _c(0) = 1; 
    _c(1) = 3;

    // getter
    std::cout << _a;
    std::cout << _b;
    std::cout << _c;

    return 0;
}