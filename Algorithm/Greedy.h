#pragma once
#include <iostream>]
#include <algorithm>

// �Ž����� ����
// n���� 5���� 2������ �Ž����ִµ�
// 5������ �Ž����� ��, ���� ���� 2������ �Ž����ְ�, ���࿡ �ܵ��� ������ -1, �ܵ��� �� ���� ����Ѵ�

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

// 14916 �Ž�����
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

