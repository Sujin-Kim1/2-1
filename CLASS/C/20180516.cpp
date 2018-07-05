class Shape
{
  private:
    int x, y;

  public:
    virtual void draw() const = 0; // 순수 가상 클래스(추상 클래스)
    // virtual : 껍데기. 실체는 각자가 가지고 있음
    // 다형성
    // 껍데기야 -> 포인터 -> 만약에 Rectangle였으면 Rectangle에 있는 draw를 가리킴
    virtual ~Shape()
    {
    // 동적 할당을 했을 때 메모리를 지워야함. 
    // Super class 자격으로 지우면 하위 클래스에 있는 메모리를 지울 수 없어서 virtual 사용
    }
};

class Rectangle : public Shape
{
  private:
    int w, h;
    char* p; // 굳이 동적배열을 해서
  public:
    ~Rectangle()
    {
        delete p; 
    }
    virtual void draw() const
    {
        std::cout << "Rectangle::draw() is called" << std::endl;
    }
};

class Circle : public Shape
{
  private:
    int r;

  public:
    virtual void draw() const
    {
        std::cout << "Shape::draw() is called" << std::endl;
    }
}

class Square : public Rectangle
{
  public:
    virtual void draw() const
    {
        std::cout << "Squre::draw() is called" << std::endl;
    }
};

main()
{
    unsigned int num = 0;

    Shape *s[512];  // 포인터의 관리는 상위 구조에서

    s[0] = new Circle();
    s[1] = new Circle();
    s[2] = new Rectangle();
    s[3] = new Square();
    s[4] = new Shape();

    num = 5;
    for (unsigned int i = 0; i < num; ++i)
    {
        Shape *p = s[i];
        p->draw();  // 구현은 하위 구조에서
    }

    num = 5;
    for (unsigned int i = 0; i < num; ++i)
    {
        Shape *p = s[i];
        delete p;
    }

    // virtual function table
}

void my_redraw(int cs, int cy, int x, int y);
{
    // do something
}

/*  ############## C ############## */

int main()
{
    int *p;
    // 포인터 변수인데 그곳으로 가면 int 변수가 있음
    void (*func_redraw)(int, int, int, int);
    // func_redraw 포인터인데 그곳으로 가면 void(int, int, int, int)함수가 있음
    func_redraw = my_redraw;
    // 배열의 이름 = 배열이 시작하는 곳의 주소
    // 함수의 이름 = 함수가 시작하는 곳의 주소
    // ############# 이름 = 주소 #############
    // event listner를 붙이는 것

    while (true)
    {
        switch (state) // state는 OS가 알아서 해줌
        {
        case WM_RESIZE:
            func_resize();
            break;
        case WM_REDRAW:
            func_redraw(int cx, cy, x, y) case WM_QUIT : exit(0);
        }
    }
}
