#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace virus
{
	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	int n, m;	// n : vertex, m : edge
	int count = 0;

	void DFS(int node)
	{
		for (int i = 0;i < graph[node].size();i++)
		{
			int current = graph[node][i];

			if (visited[current]) continue;
			
			visited[current] = true;
			count++;
			DFS(current);
		}
	}

	void Example01()
	{
		cin >> n >> m;
		for (int i = 0;i < m;i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 컴퓨터 1감염
		visited[1] = true;
		DFS(1);

		cout << count;
	}
}

namespace nQueen
{
	vector<vector<int>> board;

	int n;
	int count = 0;

	bool isSafe(int y, int x)
	{
		// 같은 열
		for (int i = 0;i < y;i++)
		{
			if (board[i][x] == 1) return false;
		}

		// 왼쪽 대각선 위
		for (int i = y - 1, j = x - 1;i >= 0 && j >= 0;i--, j--)
		{
			if (board[i][j] == 1) return false;
		}

		// 오른쪽 대각선 위에 퀸이 있나요
		for (int i = y - 1, j = x + 1;i >= 0 && j < n;i--, j++)
		{
			if (board[i][j] == 1) return false;
		}
		return true;
	}

	void nQueen(int y)
	{
		if (y == n)
		{
			count++;
			return;
		}

		// 퀸을 x위치에 배치했을 때
		for (int x = 0;x < n;x++)
		{
			if (isSafe(y,x)) // 다른 퀸이랑 겹치지 않는다면
			{
				board[y][x] = 1;
				nQueen(y + 1);

				board[y][x] = 0;
			}
			
		}
		
		
	}
	void Example02()
	{
		cin >> n;

		board = vector<vector<int>>(n, vector<int>(n, 0));

		nQueen(0); // y가 0번째일때 퀸을 어디에 배치해야 하는가

		cout << count;
	}
}

namespace GraphVec
{
	int n, m;	// n은 세로의 개수, m은 가로의 개수
	vector<vector<int>> graph;

	void Print()
	{
		n = 6, m = 4;
		graph = vector<vector<int>>(n);

		for (int i = 0;i < m;i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 정렬
		for (int i = 0;i < n;i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}

		// 출력

		for (int i = 0;i < n;i++)
		{
			cout << "[" << i << "] : ";
			for (int j = 0;j < m;j++)
			{
				// graph[i].연결된 데이터가 없을 때 접근할 방법
				if (j < graph[i].size())
				{
					cout << graph[i][j] << ' ';
				}
				else
				{
					cout << "0 "; 
				}
			}
			cout << '\n';
		}

	}
}
