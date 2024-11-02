#pragma once
#include <iostream>

// 20개의 카드가 뒤집어져 있다
// 카드를 모두 앞면으로 뒤집는 경우
// 단 이미 앞면인 카드는 뒤집을 수 없다
// 가장 많이 카드를 돌리는 횟수는? -> n(n+1)/2

void hanoi_tower(int n, int ox, int mx, int tx)
{
	if (n <= 1)
		std::cout << ox << " " << tx << std::endl;

	hanoi_tower(n - 1, ox, tx, mx);
	std::cout << ox << " " << tx << std::endl;
	hanoi_tower(n - 1, mx, tx, ox);
}