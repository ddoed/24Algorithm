#pragma once
#include <iostream>]
#include <algorithm>

// 거스름돈 문제
// n원을 5원과 2원으로 거슬러주는데
// 5원으로 거슬러준 후, 남은 돈을 2원으로 거슬러주고, 만약에 잔돈이 남으면 -1, 잔돈의 총 수를 출력한다

int CountRemainCoin(int n)
{
	int money = n;
	for (int i = 0;i * 5 <= n;i++)
	{
		int remain = n - i * 5;

		if (remain % 2 == 0)
		{
			int totalCoins = i + remain / 2;
			money = std::min(money, totalCoins);
		}
	}
	return money == n ? -1 : money;
	
}

// 14916 거스름돈
void Case001()
{
	int n;
	std::cin >> n;
	std::cout << CountRemainCoin(n);
}

// 
void Case002()
{

}

// 11399 ATM
void Case003()
{

}

