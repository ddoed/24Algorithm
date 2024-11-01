#include "DivideAndConquer.h"
#include <iostream>
#include <vector>

void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(list, left, mid);		// 왼쪽 정렬
		MergeSort(list, mid + 1, right);	// 오른쪽 정렬
		Merge(list, left, mid, right);	// merge
	}
}

void Merge(int list[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	std::vector<int> sorted;

	// 왼쪽 파트와 오른쪽 파트를 비교해서 작은 수 부터 정렬된 공간에 저장을 한다
	while (leftIdx <= mid && rightIdx <= right)
	{
		// 비교하여서 왼쪽이 작은 경우에 sorted 현재 index 저장
		// 만약에 수가 중복이 되면 왼쪽 인덱스에서 출력한다
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

	

	// 남은 데이터가 있다면 출력해준다
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
