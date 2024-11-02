#pragma once
#include <vector>

void MergeSort(int list[], int left, int right);
void Merge(int list[], int left, int mid, int right);

int QuickSelect(std::vector<int>& nums, int k);
void QuickSort(std::vector<int>& nums, int begin, int end);
