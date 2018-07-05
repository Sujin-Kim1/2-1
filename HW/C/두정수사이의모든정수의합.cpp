/*
probrlem:
	�־��� ������ �� ���ϱ�
*/

/* 
	���δ��б� ����Ʈ�������մ��� ����Ʈ�����к� 2�г�
									20171596 �����
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

