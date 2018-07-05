#include <iostream>
#include <string>

class Car
{
  public:
    Car()
    {
        comp_name = "N/A";
    } 
    /*   
    이름이 클래스 이름과 똑같은 함수가 생성자. ()는 인자로 무엇을 받나를 관찰하는 것.
    인자가 아무것도 없을 때를 default constructor라고 한다.
    외부로부터 받은 게 없기 때문에 입력값, 리턴값 다 없음
    return 값이 없음!!!!!!! -> void도 아님
    생성자는 함수기 때문에 여러 개 만들 수 있음
    */
   Car(const std::string& company_name)  
   /* 
   string은 큰 용량을 차지할 수 있으니까 레퍼런스 타입으로 넘겨줌
   const 사용으로 내용이 변경되지 않도록 방지 
   */
       : comp_name(company_name),  // 이게 밑에꺼보다 더 정확한 표현. 선언과 동시에 초기화
         prod_number(-1) // parameter로 받아오지 않더라도 C에서 int i(3); 이 되기때문에 이것도 가능함.
   {
    //    comp_name = company_name;
    // 보통 여기에는 알고리즘
   }
    Car(const std::string& company_name, const int product_number)
        : comp_name(company_name), prod_number(product_number)
    {
        // comp_name = company_name;
        // prod_number = product_number;
    }
    void setColor(std::string c);
    {
        color = c; // setter
    }
    std::string getColor() const
    // const는 이 멤버 함수의 내용을 바꾸지 않겠다는 것을 보증함
    // 멤버 함수에만 const 사용 -> 내가 갖고 있는 멤버 변수를 변화시키지 않겠다는 뜻이기 때문에
    {
        // color = "Blue";  라고 하면 컴파일 에러.
        return color; // 특정한 클래스에 attribute를 추가하면 당연히 private니까 그걸 접근할 수 있는 getter, setter 사용
    }

    const int getNumber() const
    {
        return product_number;
    } // 리턴하는 값이 변화 불가능한 값이며, 멤버 변수를 변화시키지 않는 const function

  private:
    std::string comp_name;
    std::string color;
    std::string prod_number;
    double aaa[10000];
    // 무거운 class를 복사함. C는 value만 지원하지만 C++는 reference를 씀
    int product_number;
};

void MyPrint(const Car &c);

void MyPrint2(const Car *c);
    
int main()
{
    int a = 3; // 선언과 동시에 초기화 -> 이걸 확장한 게 생성자임.
    int b;
    b = 3;    // int a = 3;과 완전히 다른 것. int 타입의 b가 쓰레기 값을 가지고 태어났다가 나중에 3으로 초기화됨.
    int d(3); // int d = 3;을 확장한 것. 생성자

    Car c = "Hyundai"; // == Car p("Hyundai"); 선언과 동시에 초기화
    Car q = Car("BMW", 50);

    c = Car("Audi", 100);  // 무명씨의 5객체 c를 만들어서 assign한 것.

    Car* p; // p라는 포인터 변수를 만든다.
    p = new Car("Kia", 2000); // 동적 할당을 할 때도 생성자 호출함
    // new Car("Kia", 2000) 자체가 동적 할당. 실체는 있지만 그 위치를 알 수 없기 때문에 포인터를 사용해서 위치를 나타냄.
    // 동적 할당은 변수 이름이 없기 때문에 그 위치를 알려주는 포인터를 사용하는 것임.
    // 힙에 저장됨
    p = &c; // 스택에 저장됨.
    Car& aaa = *(new Car("Kia, 2000")) // 가능
    (*p).getColor(); // 가능
    p->getColor(); // 위에랑 똑같음

    delete p; // 이걸 해야 p가 사라짐. 생성자는 생성자가 선언된 { } 이 코드에선 Car class의 마지막 }가 나올 때 사라짐.

    typedef int* MYPOINTER;
    MYPOINTER *p = new MYPOINTER;  // 포인터는 가리키는 변수기 때문에 스택이나 힙에 둘 다 저장 가능
    // 스택에 저장하기 너무 큰 용량을 저장하기 위해서 포인터를 사용해서 힙에 저장함
    

    c.setColor("Red");
    // std::cout << c.getColor() << std::endl;

    MyPrint(c);
    // C/C++ value로 넘어감
    // C++에서는 큰 데이터가 있으면 복사가 아닌 실체를 넘김
    MyPrint2(&c); // c의 주소를 넘김

    int i = 3;
    int &j = i; // 레퍼런스는 이미 있는 실체의 별명이기 때문에 선언과 동시에 초기화를 해줘야함
    // int j; 는 컴파일 에러

    const float PI = 3.14f; // 변경되지 않는 값이기 떄문에 좋은 코드
    // const int MAX_NUM; 컴파일 에러. 선언과 동시에 초기화 해줘야함.

   
    return 0;
}

void MyPrint(const Car &c) // read only function
/* 
실체를 넘기지만 내용은 변경하지 않는다 -> const reference type 
c.getColor() 내용을 바꾸지 않지만 특정 함수를 부르네? 함수가 불렸을 때 내용을 바꿀 수도 있다.
예를들어, getColor()에서  color = "Blue"; 로 바꿀 수 있음
=> 함수를 불러도 절대로 내용을 바꾸지 않겠다는 것을 보증하면 컴파일 에러 안남 
   함수 뒤에 붙는 const로 해결
*/
{
    std::cout << c.getColor() << std::endl;
}

void MyPrint(const Car *c)
{
    std::cout << (*c).getColor() << std::endl; // 실체를 만들고 싶을 때
    std::cout << c->getColor() << std::endl;   // 포인터로 쓰고 싶을 때
    /* 
    const : 내용을 수정하지 않겠다
    char* strcpy(char* destination, const char* source) 
    로 되어 있는 것은 destination은 업데이트 해도 상관 없고,
    source는 업데이트를 하면 안된다는 뜻.
    const!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    */
    //    c->setColor("Blue"); 는 함수 뒤에 const가 없어서 바뀔 위험이 있으므로 컴파일 에러
}