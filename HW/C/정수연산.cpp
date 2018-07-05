/*
	problem : ���� ����
*/

/*
	���δ��б� ����Ʈ�������մ��� ����Ʈ�����к� 2�г�
									20171596 �����
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

void problemSolving(std::ifstream& inStream);

int main(void)
{
	std::ifstream inStream;

	// open the file
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
		problemSolving(inStream);
	}
	return 0;
}


void problemSolving(std::ifstream& inStream)
{
	// store the input data
	int m, n;
	inStream >> m;
	inStream >> n;

	// a larger number
	int largerNum = n;
	if (m - n >= 0)
	{
		largerNum = m;
	}

	// identification of the same number
	int same = 0;
	if (m == n)
	{
		same = 1;
	}
	
	// print out the result
	std::cout << m + n << " " << m - n << " " << std::abs(m - n) << " " <<
		m * n << " " << m / n << " " << m % n << " " << largerNum << " "
		<< same << std::endl;

}