#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main(void) {
	std::ifstream inStream;
	inStream.open("input.txt"); 
	if (inStream.fail()) 
	{
		std::cerr << "Input file opening failed.\n";
		return -1;
	}

	// read the number of test cases
	int numTestCases;
	inStream >> numTestCases;

	for (int i = 0; i < numTestCases; ++i) {
		ProblemSolving(inStream);
	}
	return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    // 삼각형 X : 0     정삼각형 : 1     직각삼각형 : 2 
    // 이등변삼각형 : 3    일반삼각형 : 4 
    
    // read the a, b, c
    int a, b, c;
    inStream >> a;
    inStream >> b;
    inStream >> c;

    int answer;

    if (a + b <= c || a + c <= b || b + c <= a) {
        answer = 0;
    } else if (a == b && b == c) {
        answer = 1;
    } else if (a * a + b * b == c * c ||
               a * a + c * c == b * b ||
               b * b + c * c == a * a)
    {
        answer = 2;
    } else if (a == b || b == c || c == a) {
        answer = 3;
    } else {
        answer = 4;
    }
    std::cout << answer << std::endl;
} 