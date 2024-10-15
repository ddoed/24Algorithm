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

void BubbleExample()
{
	int list[] = { 7,5,3,6,9 };
	bubbleSort(list, 5);

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
