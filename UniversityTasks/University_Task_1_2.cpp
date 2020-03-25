#include "University_Task_1_2.h"
#include <iostream>

using namespace std;
int ut1_2::calculateNOD(int M, int N)
{
	if (M % N == 0)
	{
		return N;
	}
	else if (M == N)
	{
		return M;
	}
	else
	return calculateNOD(N,M%N);
}

void ut1_2::test()
{
	int M = 99;
	int N = 3;
	int result = calculateNOD(M, N);
	cout << "Result: " << result<<endl;
}

