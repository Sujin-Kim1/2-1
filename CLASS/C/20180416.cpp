#include <string>
#include <cstdio>
#include "my_head.h"  
#include "Car.h"

// //function declaration
// // function implementation
// int add(int a, int b)
// {
//     return a + b;
// }   // 같이 해도 무방

int add(int, int);
// int add(int, int); (X) 내용이 다르더라도 함수 이름과 매개 변수 구성까지 같으면 컴파일 에러   
// int i; int i; 한 거랑 똑같음.
int add(int);  // (O) 

class Bike {

};

class Bike {

};   // (X)

int main()
{
    int sum;

    sum = add(3, 5);

    return 0;
}

// function declaration + implementation
// class Car
// {
//   private:
//     int speed;
//     std::string color;

//   public:
//     void speendUp()
//     {
//         speed += 10;
//     }
// };

// function declaration
class Car
{
  private:
    int speed;
    std::string color;

  public:
    void speedUp();
};

// function implementation
void Car::speedUp()
{
    speed += 10; // 클래스 외부처럼 보이지만 헤더 내부에 적을 것을 바깥에만 한 것이기 때문에 내부 구현과 똑같이 하면 됨.
}

/*
main 함수에서만 잠깐만 쓰고 다른 곳에서 안쓰고 싶을 때 main함수 안에 클래스 구현해도 괜찮.
void ::speedUp()  - C함수. void speedUp()을 쓰면 컴파일러가 알아서 void ::speedUp()으로 바꿈.
컴파일러는 오직 문법체크만!
내가 의도하지 않아도 헤더 파일 이것 저것 include 하다보면 내용일 겹칠 수가 있음
 -> 헤더 파일 맨 처음에 #ifndef __CAR_H__     #define __CAR_H__    #endif  이런거 적혀있음.
 ifndef는 이전에 __CAR_H__를 정의한 적이 한 번도 없으면~을 뜻함.  (이중 include 방지용)
*/