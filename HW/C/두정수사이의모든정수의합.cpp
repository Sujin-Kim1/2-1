/*
probrlem:
	주어진 정수의 합 구하기
*/

/* 
	국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
									20171596 김수진
*/


#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main_(void) {
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

	for (int i = 0; i < numTestCases; ++i)
	{
		ProblemSolving(inStream);
	}
	return 0;
}

// print out the sum of integer
void ProblemSolving(std::ifstream& inStream)
{
	int m, n;
	int sum = 0;

	inStream >> m;
	inStream >> n;
	
	for (int i = m; i <= n; ++i)
	{
		sum += i;
	}

	std::cout << sum << std::endl;

}

