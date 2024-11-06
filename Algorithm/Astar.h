#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

namespace FoundPath
{
	struct Node
	{
		int x, y;
		int g, h, f;
		Node* parent;

		Node(int x, int y, int g = 0, int h = 0, Node* parent = nullptr)
			: x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
	};

	int Huristic(int x1,int y1, int x2, int y2)
	{
		// 목표 좌표, 이동한 거리 x y
		return abs(x1 - x2) + abs(y1 - y2);
	}

	struct CompareNode
	{
		bool operator()(Node* a, Node* b)
		{
			return a->f > b->f;
		}
	};

	vector<Node*> getNeighbors(Node* current, const vector<vector<int>>& graph)
	{
		vector<Node*> neighbors;

		int dx[] = {0,0,1,-1};	// 위 아래 오른쪽 왼쪽
		int dy[] = {-1,1,0,0};
		int n = graph.size();

		for (int i = 0;i < 4;i++)
		{
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && graph[nx][ny] != INT_MAX)
			{
				neighbors.push_back(new Node(nx, ny));
			}
		}
		return neighbors;
	}

	vector<Node*> FindPath(const vector<vector<int>>& graph, int startX, int startY, int goalX, int goalY)
	{
		int n = graph.size();
		priority_queue<Node*, vector<Node*>, CompareNode> openList;
		vector<vector<bool>> closedList(n, vector<bool>(n, false));

		// 1. 초기화
		Node* startNode = new Node(startX, startY);
		startNode->h = Huristic(startX, startY, goalX, goalY);
		startNode->f = startNode->g + startNode->h;
		openList.push(startNode);

		// 2. 탐색 Priority Queue (연결된 노드를 비교해서 작은 노드부터 실행)
		while (!openList.empty())
		{
			// 3. 큐 pop
			Node* current = openList.top();
			openList.pop();

			// 4. currentNode, targetNode 종료
			if (current->x == goalX && current->y == goalY)
			{
				vector<Node*> path;

				while (current)
				{
					path.push_back(current);
					current = current->parent;
				}

				reverse(path.begin(), path.end());
				return path;
			}

			closedList[current->x][current->y] = true;
			vector<Node*> neighbors = getNeighbors(current, graph);

			// 5. 다음 연결 노드를 Priority Queue 넣어준다
			for (Node* neighbor : neighbors)
			{
				if (closedList[neighbor->x][neighbor->y]) continue;

				neighbor->g = current->g + graph[neighbor->x][neighbor->y];
				neighbor->h = Huristic(neighbor->x, neighbor->y, goalX, goalY);
				neighbor->f = neighbor->g + neighbor->h;
				neighbor->parent = current;

				openList.push(neighbor);
			}
			return neighbors;
		}

		return vector<Node*>();

		

		
	}

	void SolveProblem()
	{
		vector<vector<int>> graph =
		{
			{1,1,1,1},
			{INT_MAX, INT_MAX, 1, INT_MAX},
			{1,1,1,INT_MAX},
			{1,INT_MAX,1,1}
		};

		int startX = 0, startY = 0;
		int goalX = 3, goalY = 3;

		vector<Node*> path = FindPath(graph, startX, startY, goalX, goalY);

		if (path.empty())
		{
			cout << "경로가 없습니다" << endl;
		}
		else
		{
			cout << "최단 경로 출력 : " << "출발 지점 : " << startX << " " << "->" << goalX << ", " << goalY << endl;

			for (auto node : path)
			{
				cout << "(" << node->x << "," << node->y << ") ";
			}
			cout << endl;
		}
	}
}