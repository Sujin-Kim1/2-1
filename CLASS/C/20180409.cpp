#include <iostream>
/*************************** scope *********************************/
int g; // lifetime = 프로그램과 실행과 동시에 태어나고 끝날때 사라짐
void f()
{
    static float k = 0;
    /* 
    f를 부르지 않아도 lifetime: global variables
    scope: local
    k가 프로그램이 시작하자마자 태어나야하므로 f가 불리든 안불리든 0으로 세팅됨.
    단, static float k; 
    k = 0; 이라고 하면 k는 f가 불려야 0으로 세팅됨.
    */
}

int main()
{
    int i; //local 변수
}

/*************************** const *********************************/
class CAR {
  public:
    int getSpeed() const;
    static float getK();
    /*
    (X) static float getK() const;
    static은 const 사용 X
    static 함수는 멤버 변수를 변경할 수 없음 (각각의 instance마다 k를 접근할 수 있어서)
    정적으로 static 변수를 위해서 존재함
    static은 C함수, C 변수. class의 함수-변수가 아님.
    scope이 class에 묶여있을 뿐임.
    */

  private:
    int speed;
    static float k;    
    /* 
       멤버 변수이면서 static인 변수
       프로그램 생성과 동시에 태어남
       class의 instance의 개수와 아무 상관 없이 k는 무조건 하나 존재
       (Car c1, c2; 했을 때 c1, c2마다 k가 생성되는게 아님.무조건 하나)
       따라서 Car::k = 5.1f;와 같이 설정
       Car 족들이 공통적으로 k를 갖고 있다는 것을 알려주는 역할. 변수 선언한 것은 아님
    */

};
float Car::k = 0; // class 바깥쪽에 적는 것이 선언과 동시에 초기화 -> C의 statick float k = 0;과 같은 역할
// float Car::k; 선언만 하는 것. 반드시 있어야 함.

int main()
{
    Car c1, c2;
    //(X) Car c1.getK();
    //(X) this->k;
    Car::getK();
}

// 컴파일러가 다를 수는 있지만 같은 클래스의 인스턴스는 static변수의 값을 바꿀 수 있음
class Car1 {
  public:
    static int get_numofcars() {return numofcars;}
    static void set_numofcars(int n) {numofcars = n;}
    
    int set_i_numofcars(int n) {numofcars = n;}
  private:
    static int numofcars;
};
int Car::numofcars = 0;

int main()
{
    Car1::set_numofcars(100);
    std::cout << Car1::get_numofcars() << std::endl;

    Car1 c1;
    c1.set_i_numofcars(300);
    std::cout << Car1::get_numofcars() << std::endl;    
}

/* ********************상속************************* */
// 동일한 소스 코드가 다시 작성되지 않도록 하기 위해 사용
class Car2 {
  public:
    int getSpeed() { return speed; }
  private:
    int speed;
}

class SportsCar : public Car2 {  // 부모의 세팅을 건드리지 않겠다는 public. 
// Car2의 speed가 private였으면 SportsCar에서도 private
    bool turbo;
    if (turbo)
    {
        getSpeed(); 
    }
}

///////////////////////////////////////////////////////////
class Shape 
{
  private:
    int pos_x, pos_y;
  public:
    Shape() :
        pos_x(0), pos_y(0)
    {
        // pos_x = 0;
        // pos_y = 0;
    }
    Shape(int _pos_x, int _pos_y) : pos_x(_pos_x), pos_y(_pos_y)
};

class Rectangle : public Shape
{
    int ul_x, ul_y;  // upper-left(x, y)
    int br_x, br_y;  // bottom-right(x,y)
  public:
    Rectangle() : 
        ul_x(-1), ul_y(-1), 
        br_x(1), br_y(1),
        Shape()
        // pos_x(1), pos_y(1)을 하면 에러 -> 생성자가 부모의 생성자 호출하는 걸로 해결

    {
        // ul_x = -1;  ul_y = -1;
        // br_x = 1;   br_y = 1;
        // (X) Shape(); -> 생성자는 호출이 안되는 함수이기 때문에 위와 같이 생성자를 설정할 수 없음
        // (X) r1.Shape();  -> 내가 살고 있는데 갑자기 다시 태어나라고 하는 꼴임
    }
    Rectangle(int _pos_x, int _pos_y, int _ul_x, int _ul_y) :
        Shape(_pos_x, _pos_y),
        
};

int main()
{
    Rectangle r1;
    Rectangle r2(3,3, -2, -2, 2, 2)
}