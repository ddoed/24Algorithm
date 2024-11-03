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

		// ��ǻ�� 1����
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
		// ���� ��
		for (int i = 0;i < y;i++)
		{
			if (board[i][x] == 1) return false;
		}

		// ���� �밢�� ��
		for (int i = y - 1, j = x - 1;i >= 0 && j >= 0;i--, j--)
		{
			if (board[i][j] == 1) return false;
		}

		// ������ �밢�� ���� ���� �ֳ���
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

		// ���� x��ġ�� ��ġ���� ��
		for (int x = 0;x < n;x++)
		{
			if (isSafe(y,x)) // �ٸ� ���̶� ��ġ�� �ʴ´ٸ�
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

		nQueen(0); // y�� 0��°�϶� ���� ��� ��ġ�ؾ� �ϴ°�

		cout << count;
	}
}

namespace GraphVec
{
	int n, m;	// n�� ������ ����, m�� ������ ����
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

		// ����
		for (int i = 0;i < n;i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}

		// ���

		for (int i = 0;i < n;i++)
		{
			cout << "[" << i << "] : ";
			for (int j = 0;j < m;j++)
			{
				// graph[i].����� �����Ͱ� ���� �� ������ ���
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
