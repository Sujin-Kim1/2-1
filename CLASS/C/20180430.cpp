#include <iostream>
#include <cstring>
#include <string>

class Car1
{
    int speed;
    int gear;
    std::string color; // pointer 대신 C++에서 만들어진 문자열 쓸 것
};

class Car
{
  private:
    int &ref_car_number;
    /* 
        reference: 실체는 따로 있는데 실체에 새로운 이름을 붙이는 것
        int는 외부에 있음
        class가 reference를 가질 수 있을까?
    */
    std::string name;
    char *color;

  public:
    Car(int &k)
        : ref_car_number(k)
    {
        // ref_car_number = k;  - 값을 assign 한 것이기 때문에 불가능
        ref_car_number = 3;
        // main에 있는 i의 값이 3으로 바뀜
        // 포인터랑 역할이 똑같음
    }

    Car()
        :color(NULL)
    {
    }

    Car(const std::string &str)
        : name(str), color(NULL)
    {
    }

    // Car(const Car &other) // copy strunctor
    // // class 자체가 무거우니까 & 로 받음
    //     : name(other.name), color(other.color)
    //     /* 
    //     color : 위치만 알려주는 녀석. 주소 복사 != 내용 
    //     => shallow copy (얕은 복사) <-> deep copy (깊은 복사) : contents 진짜로 만듦
    //     */
    // {
    // }

    /* deep copy */
    Car(const Car& other) 
        : name(other.name), color(NULL)
    {
        if (color == NULL)
            return;
        unsigned int len = strlen(other.color);
        color = new char[len + 1];
        memcpy(color, other.color, len*sizeof(char));
        color[len] = '\0';
        // 다른 녀석이 가지고 있는 메모리를 내 매모리로 복사한다.
        // 메모리가 2개 생김
        
    }

    Car(const std::string& str, const char* c)
        :name(str), color(NULL)
    {
        unsigned int len = std::strlen(c);
        color = new char[len + 1];
        memcpy(color, c, len*sizeof(char));
        color[len] = '\0';   // color 값 복사
    }

    ~Car()  // 동적할당을 했으므로 소멸자를 만들어야 함
    {
        if (color != NULL)
            delete[] color;
        
        color = NULL;
    }

    Car& operator = (const Car& other)   
    // 그냥 함수. 생성자가 아니기 때문에 : name(other.name)와 같은 선언과 동시에 초기화 불가
    {
        name = other.name;

        if (other.color == NULL)
            return;
        
        unsigned int len = std::strlen(c);
        color = new char[len + 1];
        memcpy(color, c, len*sizeof(char));
        color[len] = '\0';

        return *this;  // 함수니까 return 값 존재
    }
};

main()
{
    int i;
    int &ref = i;

    Car b("BMW"), h("Hyundai"), a("Audi", "red");

    Car k = h; // Car k(h); 선언과 동시에 초기화 - 복사 생성자가 불림 
    // 여기서 = 는 k(h)를 대신 쓰기 위함. 밑의 k = h와는 완전 다름
    
    k = h;  // 대입 연산자가 불림. assign operator

    int p = 3;
    int j = i; // copy == Car j(i);
}