#include "DivideAndConquer.h"
#include <iostream>
#include <vector>

void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(list, left, mid);		// ���� ����
		MergeSort(list, mid + 1, right);	// ������ ����
		Merge(list, left, mid, right);	// merge
	}
}

void Merge(int list[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	std::vector<int> sorted;

	// ���� ��Ʈ�� ������ ��Ʈ�� ���ؼ� ���� �� ���� ���ĵ� ������ ������ �Ѵ�
	while (leftIdx <= mid && rightIdx <= right)
	{
		// ���Ͽ��� ������ ���� ��쿡 sorted ���� index ����
		// ���࿡ ���� �ߺ��� �Ǹ� ���� �ε������� ����Ѵ�
		if (list[leftIdx] <= list[rightIdx])
		{
			sorted.push_back(list[leftIdx]);
			leftIdx++;
		}
		else if (list[leftIdx] > list[rightIdx])
		{
			sorted.push_back(list[rightIdx]);
			rightIdx++;
		}

	}

	if (rightIdx >= left)
	{
		for (int i = leftIdx; i <= mid;i++)
		{
			sorted.push_back(list[i]);
		}
	}
	else
	{
		for (int i = rightIdx; i <= right;i++)
		{
			sorted.push_back(list[i]);
		}
	}

	for (int i = 0;i < sorted.size();i++)
	{
		list[left + i] = sorted[i];
	}

	

	// ���� �����Ͱ� �ִٸ� ������ش�
	//while (leftIdx <= mid)
	//{
	//	sorted[key++] = list[leftIdx++];
	//}
	//
	//while (rightIdx <= right)
	//{
	//	sorted[key++] = list[rightIdx++];
	//}

	
}
