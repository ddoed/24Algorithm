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

// search Largest k'th number

int QuickSelect(std::vector<int>& nums, int k)
{
	int length = nums.size();

	// size가 1일 경우에는 nums[0] 값을 return
	if (length == 1) return nums[0];

	// 랜덤한 숫자를 선택해서 그 숫자를 기준이라고 잡는다
	// pivot에 해당하는 숫자를 가장 마지막으로 옮긴다
	int pivotIndex = rand()%length;
	int lastIndex = length - 1;

	std::swap(nums[pivotIndex], nums[lastIndex]);

	// 왼쪽은 항상 pivot보다 작고, 오른쪽은 항상 pivot보다 크다
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
		std::swap(nums[leftIdx], nums[rightIdx]);	// 인덱스가 움직이지 않음
	}
	std::swap(nums[leftIdx], nums[lastIndex]);

	if (leftIdx == length - k) // k번째 큰 수
	{
		return nums[leftIdx];
	}
	else if (leftIdx < length - k) // 피벗의 위치가 찾는 위치보다 작은 경우 (오른쪽 검색)
	{
		std::vector<int> rightPart(nums.begin() + leftIdx + 1, nums.end());
		return QuickSelect(rightPart, k);
	}
	else if (leftIdx > length - k)	// 피벗의 위치가 찾는 위치보다 큰 경우 (왼쪽 검색)
	{
		std::vector<int> leftPart(nums.begin(), nums.begin() + leftIdx);
		return QuickSelect(leftPart, k - (length - leftIdx));
	}
}

void QuickSort(std::vector<int>& nums, int begin, int end)
{
	// 사이즈가 1인 경우에는 nums[0]
	int length = end - begin + 1;
	if (length <= 1)
	{
		return;
	}

	// 랜덤한 숫자를 선택해서 그 숫자를 기준이라고 잡는다.
	// 그리고 피벗에 해당하는 숫자를 제일 마지막으로 옮긴다.
	int pivotIndex = rand() % length;
	int lastIdx = length - 1;
	std::swap(nums[pivotIndex], nums[lastIdx]);

	// 왼쪽은 항상 피벗보다 작고, 오른쪽은 항상 피벗보다 크다.
	int leftIdx = 0;
	int rightIdx = lastIdx - 1; // lastIndex - 1
	int pivot = nums[lastIdx];

	while (leftIdx <= rightIdx) //왼쪽 오른쪽보다 작거나 같으면 계속 반복하세요
	{
		if (nums[leftIdx] <= pivot) // 비교를 해서 피벗보다 작거나 같은 수 idx 변경
		{
			leftIdx++;
			continue;
		}
		if (pivot < nums[rightIdx]) // 오른쪽 수가 피벗보다 크면 idx 잘못된 것을 찾을 때까지 변경
		{
			rightIdx--;
			continue;
		}

		std::swap(nums[leftIdx], nums[rightIdx]); // left(피벗 기준 큰수), right(피벗 기준 작은 수) 교환 
	}

	std::swap(nums[leftIdx], nums[lastIdx]); // nums leftIdx와 lastIdx를 변경해라.

	// 피벗을 선택  좌,우를 나눈다. QuickSelect

	QuickSort(nums, leftIdx + 1, lastIdx);
	QuickSort(nums, begin, leftIdx - 1);
}
