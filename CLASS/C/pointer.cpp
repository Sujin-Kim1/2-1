        #include <iostream>

        // pointer -> scope을 깨버리고 싶을 때 사용, 모듈화 가능케 함.


        void ProblemSolving(int *);
        // ProblemSolving에 가면 int가 있음을 알려줌


        int main()
        {
        int x, y;

        ProblemSolving(&x);
        // 실체의 위치를 알려주려면 &를 붙이면 됨
        // 7호관 617호

        x = 3; // x를 main에서만 다루고 싶다. 할 땐 그냥 이렇게 선언하면 됨. 포인터 쓸 필요X
        }

        void ProblemSolving(int* p) // 그곳을 가면 int가 있고 그것을 p에 저장한다는 뜻
                // 7호관 617호에 김준호 교수님이 있다고 종이에 적었을 때, 적은 건 위치를 알려주는 * 종이는 p
        {
        *p = 3; // x를 건드릴 수 없는 scope에서도 x를 쓰거나 읽고 싶을 때 포인터 사용.
        // 그곳의 실체 즉 여기선 x
        // 7호관 617호라는 방

        }