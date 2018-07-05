#include <iostream>

    static int j;  

    void func();     // forward declaration
    int ffff(int* p);   // 그곳에 가면 integer가 있다는 것을 알려줌.
    int ref_func(int& k);

    struct VERYBIGMEM
    {
        int a, b, c;
    }

    int main()
    {
        typedef VERYBIGMEM VM;
        VM i;   // 만약 i가 100메가면

        func(i);  // 여기에도 i가 100메가
        func(&i);   // 100메가 그대로를 복사한 게 아니라 주소 값만 받음

        int i;
        int& a = i;  // 여기서의 &는 reference type. 밑의 &와 다름

        ffff(&i);  // & : i가 있는 곳의 주소를 알려줌
                //     위의 ffff(int* p)와 동일

        j = 3;

        return 0;
    }

    void func(const int* p)  // 위치를 알고 있지만 컨텐츠는 업데이트 하지 않기로 컴파일러에게 부탁 
    {
        int i;   // 위에 있는 i 알 수 없다.
        j = 6;
        static int k;   // local 변수지만 life time은 global. 프로그램 시작되자마자 생성됨.
        // * p = 3; // error
        std::cout << *p << std:endl;  // 내용을 업데이트 하지 않으므로 에러 X
    }

    int ffff(int* p)
    {    
    /* 
    p는 i가 있는 곳의 주소를 갖고 있음.
    p : 주소값을 가진 변수 
    */

        *p = 3;
        // p에 주소가 써있는데 그 주소로 가서 진짜 그 실체가 된다. 진짜 i. 변수 그 자체

    }

    void ref_func(int& k)
    {
        k = 3;  // 기본적으로 다른언어들은 다른 함수로 인자를 넘길때 reference로 넘기도록 설정되어 있음.

        
    }



    /*
    struct verybig(int a, int b; int c); main에서 verybig을 i 생성
    C언어에서 메모리가 큰 변수를 넘길 때, 주소를 통해 넘긴다. (&) 
    읽기 전용 const를 써서 compiler에게 값을 변경하려고 하면 에러가 나도록 부탁

    C에서는 call by reference를 흉내내려고 포인터를 사용 -> C++에서 해결
    동적할당을 쓰기 위해서 C++에서도 포인터 사용
    자바에선 동적할당은 new .    reference type
    */