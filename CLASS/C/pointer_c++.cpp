#include <iostream>

// pointer -> scope을 깨버리고 싶을 때 사용, 모듈화 가능케 함.


void ProblemSolving(int& p);
// 실체를 가리키는 reference 사용
// & : 실체를 넘긴다는 뜻

int main()
{
	int x, y;

	x = 3;

	ProblemSolving(x);

	std::cout << x << std::endl;
	
	return 0;
}

void ProblemSolving(int& p)
{
	p = 4; // 바깥쪽 실체 그냥 쓰면 됨
	std::cout << p << std::endl;
}