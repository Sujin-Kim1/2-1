#include <iostream>

// scope ~= life time    
int result; // 전역 변수 (global variable) -> file이 실행될 때 생성되고 file이 끝나면 사라짐


// function signature == function name + input parameters    
						// return type X

int ProblemSolving();
int ProblemSolving(int x, int y);
// int ProblemSolving(int a, int b); -> 위에 꺼랑 같은거임. 여기서 변수 이름을 짓는 것은 무쓸모
// int ProblemSolving(int, int) -> 이것도 똑같음. 그냥 int 형 인자를 받는 함수가 있을 것이라는 function declaration.에러 X
// float ProblemSolving(int, int); -> function signature가 같기 때문에 리턴 타입이 다르더라도 위에 꺼랑 같은 거.
										// return type만 같은 함수는 구현할 수 없도록 설정되어 있음.
int ProblemSolving(int, int, int); // 인자 갯수가 다르므로 가능
int ProblemSolving(double d = 1.0); // default parameter -> 선언 할 때만 assign을 하고, 구현할 땐 assign X
									// 밑에서 함수 구현할 때 int ProblemSolving(double d) {
									//														} 이런 식으로 구현해야 함

// function declaration을 하는 이유는 컴파일러가 한 번만 소스를 스캔하기 때문에 나중에 result = ProblemSolving() 이런 식으로
// 적으면 에러가 남. 자바 같은 후대에 나온 건 컴파일러가 두 번씩 소스를 스캔하기 때문에 result를 선언 한 후 함수를 나중에 
// 구현해도 문제가 생기지 않음. function declaration이 너무 많아지면 더러워지니까 헤더 파일로 함수 선언만 모아둔 걸 만들어서
// include "" 이렇게 끌어모음

int main()
{
	float f;
	int result;   // 지역 변수 (local variable) -> {}안에서만 생성되고 {}끝나면 사라짐
	static int result1; // local scope 장점 + global lifetime 장점 : 프로그램이 실행될 때 생성, 프로그램이 죽으면 소멸 
	int x, y;

	for (;;)
		result = ProblemSolving(x, y); 
		f = ProblemSolving(x, y);  // int ProblemSolving으로 갈 지, float ProblemSolving으로 갈 지 못정함
								   // 따라서 리턴값만 다르고 function signature가 같은 것은 불가능
}





int ProblemSolving()
{
	static float f;  // global 변수니까 함수가 실행되든 안되든 무조건 한 번 생성됨. 
	                 // static은 오직 scope만 local임.
	f = 3.4f;  // 함수가 실행되면 f가 3.4 

	f = f + 1.0;
	std::cout << f << std::endl;

	int i = 3;   // i라는 변수가 선언됨과 동시에 3을 가지고 태어남
	
	int i;  // i라는 변수가 쓰레기 값을 가지고 태어남
	i = 3;  // i 에 3이라는 값을 대입함
	
	return 0;
}

int ProblemSolving(int x, int y)
{
	// 구현할 때는 int x, int y 처럼 반드시 이름을 지어줘야 함.
	return 0;
}