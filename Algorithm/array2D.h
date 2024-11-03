#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Board
{
	const int size = 2;

	// case 1. int[y][x] 
	int board1[size][size];

	vector<string> inputString(size);

	void Case1()
	{
		for (int i = 0;i < size;i++)
		{
			cin >> inputString[i];
		}

		for (int y = 0;y < size;y++)
		{
			for (int x = 0;x < size;x++)
			{
				board1[y][x] = inputString[y][x] - '0';
			}
		}

		for (int y = 0;y < size;y++)
		{
			for (int x = 0;x < size;x++)
			{
				cout << board1[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	void Print(const string& s)
	{
		for (int i = 0;i < s.size();i++)
		{
			cout << s[i] << ' ';
		}
		cout << '\n';
	}

	void Case2()
	{
		int first = 101111;
		string one = to_string(first);

		int second = 101010;
		string two = to_string(second);

		int third = 101011;
		string three = to_string(third);

		int fourth = 111000;
		string four = to_string(fourth);
		
		Print(one);
		Print(two);
		Print(three);
		Print(four);

	}
	vector<vector<int>> board2(size,vector<int>(size,0));
	
	vector<vector<int>> board3(size);

	void Case3()
	{
		for (int y=0;y < size;y++)
		{
			for (int x=0;x < size;x++)
			{
				cout << board2[y][x] << ' ';
			}
			cout << '\n';
		}

		cout << "push back 2차원 배열 추가" << '\n';

		for (int y = 0;y < size;y++)
		{
			board3[0].push_back(5);
			board3[0].push_back(1);
			board3[1].push_back(4);
			board3[1].push_back(0);
		}

		for (int y = 0;y < size;y++)
		{
			for (int x = 0;x < size;x++)
			{
				cout << board3[y][x] << ' ';
			}
			cout << '\n';
		}
	}
}
