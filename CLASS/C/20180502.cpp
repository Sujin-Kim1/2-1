//class -> struct
// C
strunct Person
{
    int age;
    char name[256];
};

Person a;

a.age;
a.neme;

Person *p = (Person *)malloc(sizeof(Person));
p->age;
p->name;

// C++
class Per
{
  private:
    int age;
    char name[256];

  public:
    int getAge() const { return age; }
    void setAge(int age_) { age= _age; }
    Person& operator=(const Person& other)
    {
        ____________;

        return *this;  // myself
    }
}


int main()
{
    // this->getAge();  // 클래스 내부 구현 시 자신이 지신을 가리켜야할 때 this 사용

    Person a;
    my_print(a);
}



/* this 활용법 */
// C
int i, j, k;
i = j = k = 5;

/* 
1. k = 5;
2. j = k;
3. i = j;
업데이트된 나를 return
 */


void my_print(const Person& n)
{
    int age;
    age = n.getAge();
}