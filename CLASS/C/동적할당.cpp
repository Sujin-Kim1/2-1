#include <iostream>
#include <string>

static int CUSTIM_DATA[1000000000];

void set_array_values(int arr[], in size);

int main()
{
    int i; // main이 시작될 때 '{' 만들어지고 끝날 때 '}' 사라짐
    func(&i);

    void *p = malloc(4 * 100);       // integer를 100개 쓰고 싶었음
    int *p = (int *)malloc(4 * 100); // 프로그래머의 의도
    // malloc은 그냥 400byte만 할당해주는 애임.
    int *p = (int *)malloc(sizeof(int) * 100);
    int *P = new int[100]; // C++은 동적할당 이렇게 함.위에꺼랑 같은 코드

    double *d = (double *)p;
    d[0];
    d[1];
    d[49]; // int로 동적할당 했지만 double로 50개 쓸 수 있음.
    // void pointer이기 때문에 메모리는 내가 아무렇게나 나눠서 쓸 수 있음.

    int arr[30]; // stack에 쌓이는 local 변수

    int *p = &arr[0]; // arr[0]의 주소 알려줌
    // 배열의 이름 == 시작하는 곳의 위치

    set_array_values(arr, 30); // 배열 30개가 있는 곳의 위치를 알려줌.

    return 0;
}

void func(const int *p)
{
    /*
    p는 포인터 변수. 주소를 채울 수 있는 변수.
    func 가 끝나면 메모리에서 사라짐.
    */
}

void set_array_values(int arr[], int size)
{
    arr[0] = 3;
    arr[1] = 3;
    arr[2] = -1; // 배열은 메모리에 아무렇게나 있지 않고 차례대로 쌓이듯이 만들어줌
}