#include "DynamicProgramming.h"

int Fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci_DP(int n)
{
	int* dp = new int[n + 1];// �ߺ��Ǵ� ������ �����ϰ� �ʿ��� �� ���� ����Ѵ�.

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2;i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	return dp[n];
}