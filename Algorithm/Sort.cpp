#include <algorithm>
#include <iostream>
#include "Sort.h"

void bubbleSort(int list[], int n)
{
	for (int i = n-1; i >0; i--) // n사이클 진행
	{
		for (int j = 0; j < i; j++) 
		{
			if (list[j] > list[j+1])
			{
				std::swap(list[j], list[j + 1]);
			}
		}
	}
}

void bubbleSort2(int list[], int n)
{
	for (int i = 0; i < n-1; i++) // n사이클 진행
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (list[j] > list[j + 1])
			{
				std::swap(list[j], list[j + 1]);
			}
		}
	}
}

void BubbleExample()
{
	int list[] = { 7,5,3,6,9 };
	bubbleSort2(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void SelectionSort(int list[], int n)
{
	int least;

	for (int i = 0; i < n; i++)
	{
		least = i;
		for (int j = i+1; j < n; j++)
		{
			if (list[least] > list[j])
			{
				least = j;
			}
		}

		if (least != i)
		{
			std::swap(list[i], list[least]);
		}
	}
	

}

void SelectionSortExample()
{
	int list[] = { 7,5,3,6,9 };
	SelectionSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void InsertionSort(int list[], int n)
{
	int j;
	for (int i = 0;i < n-1;i++)
	{
		j = i;
		while (list[j] > list[j+1] && j >= 0)
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
		
	}

	for (int i = 0; i < n;i++)
	{
		std::cout << list[i] << " ";
	}
}

void InsertSortExample()
{
	int list[7] = { 1,10,5,4,7,6,3 };
	InsertionSort(list, 7);
}

void CountSort()
{
	int array[6] = { 3,0,4,2,0,4 };

	int count[5];

	for (int i = 0;i < 5;i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < 6;i++)
	{
		count[array[i]]++;
	}

	// count 인덱스 번호 숫자, 값 크기

	for (int i = 0;i < 5;i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0;j < count[i];j++)
			{
				std::cout << i << " ";
			}
		}
	}
}


