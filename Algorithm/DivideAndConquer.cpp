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

// search Largest k'th number

int QuickSelect(std::vector<int>& nums, int k)
{
	int length = nums.size();

	// size�� 1�� ��쿡�� nums[0] ���� return
	if (length == 1) return nums[0];

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �����̶�� ��´�
	// pivot�� �ش��ϴ� ���ڸ� ���� ���������� �ű��
	int pivotIndex = rand()%length;
	int lastIndex = length - 1;

	std::swap(nums[pivotIndex], nums[lastIndex]);

	// ������ �׻� pivot���� �۰�, �������� �׻� pivot���� ũ��
	int leftIdx = 0;
	int rightIdx = lastIndex-1;
	int pivot = nums[lastIndex];

	while (leftIdx <= rightIdx)
	{
		if (nums[leftIdx] <= pivot)
		{
			leftIdx++;
			continue;
		}
		if (nums[rightIdx] > pivot)
		{
			rightIdx--;
			continue;
		}
		std::swap(nums[leftIdx], nums[rightIdx]);	// �ε����� �������� ����
	}
	std::swap(nums[leftIdx], nums[lastIndex]);

	if (leftIdx == length - k) // k��° ū ��
	{
		return nums[leftIdx];
	}
	else if (leftIdx < length - k) // �ǹ��� ��ġ�� ã�� ��ġ���� ���� ��� (������ �˻�)
	{
		std::vector<int> rightPart(nums.begin() + leftIdx + 1, nums.end());
		return QuickSelect(rightPart, k);
	}
	else if (leftIdx > length - k)	// �ǹ��� ��ġ�� ã�� ��ġ���� ū ��� (���� �˻�)
	{
		std::vector<int> leftPart(nums.begin(), nums.begin() + leftIdx);
		return QuickSelect(leftPart, k - (length - leftIdx));
	}
}

void QuickSort(std::vector<int>& nums, int begin, int end)
{
	// ����� 1�� ��쿡�� nums[0]
	int length = end - begin + 1;
	if (length <= 1)
	{
		return;
	}

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �����̶�� ��´�.
	// �׸��� �ǹ��� �ش��ϴ� ���ڸ� ���� ���������� �ű��.
	int pivotIndex = rand() % length;
	int lastIdx = length - 1;
	std::swap(nums[pivotIndex], nums[lastIdx]);

	// ������ �׻� �ǹ����� �۰�, �������� �׻� �ǹ����� ũ��.
	int leftIdx = 0;
	int rightIdx = lastIdx - 1; // lastIndex - 1
	int pivot = nums[lastIdx];

	while (leftIdx <= rightIdx) //���� �����ʺ��� �۰ų� ������ ��� �ݺ��ϼ���
	{
		if (nums[leftIdx] <= pivot) // �񱳸� �ؼ� �ǹ����� �۰ų� ���� �� idx ����
		{
			leftIdx++;
			continue;
		}
		if (pivot < nums[rightIdx]) // ������ ���� �ǹ����� ũ�� idx �߸��� ���� ã�� ������ ����
		{
			rightIdx--;
			continue;
		}

		std::swap(nums[leftIdx], nums[rightIdx]); // left(�ǹ� ���� ū��), right(�ǹ� ���� ���� ��) ��ȯ 
	}

	std::swap(nums[leftIdx], nums[lastIdx]); // nums leftIdx�� lastIdx�� �����ض�.

	// �ǹ��� ����  ��,�츦 ������. QuickSelect

	QuickSort(nums, leftIdx + 1, lastIdx);
	QuickSort(nums, begin, leftIdx - 1);
}
