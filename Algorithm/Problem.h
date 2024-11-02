#pragma once
#include <iostream>

// 20���� ī�尡 �������� �ִ�
// ī�带 ��� �ո����� ������ ���
// �� �̹� �ո��� ī��� ������ �� ����
// ���� ���� ī�带 ������ Ƚ����? -> n(n+1)/2

void hanoi_tower(int n, int ox, int mx, int tx)
{
	if (n <= 1)
		std::cout << ox << " " << tx << std::endl;

	hanoi_tower(n - 1, ox, tx, mx);
	std::cout << ox << " " << tx << std::endl;
	hanoi_tower(n - 1, mx, tx, ox);
}