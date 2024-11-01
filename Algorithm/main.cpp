#include <iostream>
#include "Sort.h"
#include "InputReference.h"
#include "Pow.h"
#include "DivideAndConquer.h"

int main()
{
	//std::cout << "hello world" << std::endl;
	//BubbleExample();
	//SelectionSortExample();
	//InsertSortExample();
	//CountSort();
	//InputExample();

	//std::cout << Pow(3, 5);
	int list[8] = { 7,6,5,8,3,5,9,1 };
	MergeSort(list, 0, 7);

	for (int i = 0;i < 8;i++)
	{
		std::cout << list[i] << " ";
	}

}