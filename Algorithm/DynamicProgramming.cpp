#include "DynamicProgramming.h"
std::vector<int> stairDP;

int Fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci_DP(int n)
{
	int* dp = new int[n + 1];// 중복되는 사항을 저장하고 필요할 떄 마다 사용한다.

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2;i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	return dp[n];
}

int max_stair_recursive(int i, std::vector<int> stairs)
{
	// stairDP 데이터가 -1이 아니면 (데이터가 메모가 되어있으면)
	// 해당 데이터를 리턴
	if (stairDP[i] != -1)
	{
		return stairDP[i];
	}
	
	// 계단을 오르는 아이디어
	// 계단 1층
	if (i == 0)
	{
		return stairs[0];
	}

	if (i == 1)
	{
		return stairs[0] + stairs[1];
	}

	if (i == 2)
	{
		return std::max(stairs[0] + stairs[i], stairs[1]);
	}
	
	else 
		return stairDP[i] = std::max(max_stair_recursive(i - 2, stairs),
			max_stair_recursive(i - 3, stairs) + stairs[i - 1]) + stairs[i];
}

int StairCount(std::vector<int> stairs)
{
	int size = stairs.size();

	stairDP.assign(size, DEFAULT);
	return max_stair_recursive(size - 1, stairs);
}
