#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace Permutation
{
	// n개의 자료가 주어진다. 1부터 시작해서 n까지 원소를 이루고 있다.
	// arr {1,2,3}
	// 2개 {1,2} {1,3} {2,1} {2,3} {3,1} {3,2}
	// 같은 숫자가 중복이 안되게 나오게 하는 것
	
	int n = 3;
	int m = 2;
	int arr[3];
	bool visited[3] = { 0 };

	vector<int> vec;

	void Print()
	{
		for (int i = 0;i < vec.size();i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length)
	{
		if (length == m)	// 출력 조건
		{
			Print();
			return;
		}
		
		for (int i = 0;i < n;i++)
		{
			// 이미 방문했으면 패스해라 continue
			if (visited[i]) continue;
			
			visited[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1);
			visited[i] = false;
			vec.pop_back();
		}

	}

	void Case01()
	{
		for (int i = 0;i < n;i++)
		{
			arr[i] = i+1;
		}

		BT(0);
		
	}
}

namespace Combination
{
	int n = 3;
	int m = 2;
	int arr[3];
	bool visited[3];

	vector<int> vec;

	void Print()
	{
		for (int i = 0;i < vec.size();i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length, int start)
	{
		if (length == m)	// 출력 조건
		{
			Print();
			return;
		}

		for (int i = start;i < n;i++)
		{
			// 이미 방문했으면 패스해라 continue
			if (visited[i]) continue;

			visited[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1,i+1);
			visited[i] = false;
			vec.pop_back();
		}

	}

	void Case02()
	{
		for (int i = 0;i < n;i++)
		{
			arr[i] = i + 1;
		}

		BT(0,0);
	}
}

