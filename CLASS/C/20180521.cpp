#include <iostream>
#include <vector>
#include <cassert>

// r-value, l-value 중요!!!!!!!!!!!!!!!!!
    

class vec2
{
  public:
    vec2() : x(0.0f), y(0.0f) {}
    vec2(float _x, float _y) : x(_x), y(_y) {}

    float get_x() const { return x; }
    float set_x(float _x) { x = _x; }


    // c(0) = a(0) + b(0); 호출 시 실행되는 것.    
    // 근데 c(0)은 a.x + b.x를 한 걸 받는 코드가 아님!!
    // r-value operator  (= 은 오른쪽의 계산 결과를 왼쪽에 저장)(일종의 getter method)
    float operator() (unsigned int idx) const
    // vec2의 변수가 함수처럼 동작하도록 하는 예약어
    // 반드시 함수 내부에 있어야함
    {
        if (idx == 0) 
            return x;
        else if (idx == 1) 
            return y;

        assert(0);  // 프로그램 die
    }

    // c(0)을 구하기 위한 함수 
    // l-value operator (setter method)
    float& operator() (unsigned int idx)  
    // a.x + b.x가 계속 update되기 때문에 const(X)
    // 실체를 넘겨줘야 하니까 & 필요 
    {
        if (idx == 0) 
            return x;
        else if (idx == 1) 
            return y;

        assert(0);
    }

    float operator[] (unsigned int _x, unsigned int _y) const
    {
        if (idx == 0) 
            return _x;
        else if (idx == 1) 
            return _y;

        assert(0);
    }

    float& operator[] (unsigned int _x, unsigned int _y)  
    {
        if (idx == 0) 
            return _x;
        else if (idx == 1) 
            return _y;

        assert(0);
    }

    // k = -i; 
    vec2 operator- () const  
    {
        vec2 c;

        c(0) = -(*this)(0);
        c(1) = -(*this)(1);

        return c;
    }

  public:
    float x, y;
    /* 
    private로 설정하면 C함수인 operator+나 operator-에서 x, y를 접근할 수 없음 
    -> getter, setter메서드 구현
    -> c.set_x(a.get_x() + b.get_x()) 막 이렇게 더럽게 짜야 함
    */

};

float operator*(const vec2& b) // 내적
{
    return x * b(0) + y * b(1);
    // == return (*this)(0) * b(0) + (*this)(1) * b(1); 
    // 클래스 내부 함수니까 private 볼 수 있음
    // 일종의 this.
}

/* 
float operator+(const vec2& b)
{
    vec2 c;
    c(0) = x + b(0);  // == c(0) = (*this)(0) + b(0);
    c(1) = y + b(1);  // == c(1) = (*this)(1) + b(1);

    return c;
}
*/

vec2 operator+(const vec2 &a, const vec2 &b)
{
    mat2 A;  // 2 x 2 matrix A
    vec2 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;

    c(0) = a(0) + b(0);
    c(1) = a(1) + b(1);  // 함수 호출할 때 ()를 사용
    // 변수인데 함수처럼 동작 : function operating

    c[0] = a[0] + b[0];
    // 배열 연산자 정의 하면 가능
    // 배열은 c[0, 0]과 같이 index를 여러 개 받을 수 없기 때문에
    // 입력이 여러 개일 때는 () 사용

    A(0, 0) = 3;     A(0, 1) = 1;
    A(1, 0) = 2;     A(1, 1) = 4;
    return c;
}
// C함수.
// operating overloading 방법엔 C함수와 클래스 함수로 정의할 수 있음.

vec2 operator-(const vec2 &a, const vec2 &b)
{
    vec2 c;

    c.x = a.x - b.x;
    c.y = a.y - b.y;

    return c;
}

vec2 operator* (const float s, const vec2& a)
// 왼쪽꺼는 원래 자기 자신이 되어야 하는데 float는 자기자신이 아니니까 불가능
// 그래서 사용자에게 무조건 (vec2, float)로 들어오도록 하면 됨
{
    vec2 c;

    c(0) = s * a(0);
    c(1) = s * a(1);

    return c;
}

vec2 operator* (const vec2& a, const float s)
{
    return s * a;
}

vec2 operator- (const vec2 & a)
{
    vec2 c;

    c(0) = -a(0);
    c(1) = -a(1);

    return c;
}


// 함수, 배열 operator는 클래스 내부에서 구현하는 게 좋음

int main()
{
    vec2 i, j, k, c;

    i = vec2(3.0f, 5.0f);
    j = vec2(4.0f, 1.0f);
    k = i + j;
    c = i - j;
    k = 1.2f * i;
    k = i * 1.2f;
    k = -i;

    std::cout << k(0) << "   " << k(0) << std::endl;
    std::cout << c(0) << "   " << c(0) << std::endl;




    /* C */

    int i;
    float f = 3.14f;

    i = (int)f;
    i = int(f);
    
    return 0;
}