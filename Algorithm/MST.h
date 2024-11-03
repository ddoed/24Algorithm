#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace InputWeight
{
	vector<pair<pair<int,int>,int>> edges;

	void Show()
	{

		edges.push_back({{1,2},10});
		edges.push_back({{2,3},5});
		edges.push_back({{1,3},15});
		edges.push_back({{2,4},5});
		edges.push_back({{3,4},25});

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first.first << ", " << edge.first.second << "), weight : " << edge.second << endl;
		}

	}

	class Edge
	{
	private:
		int node[2];
		int distance;

	public:
		Edge(int node1, int node2, int _distance)
		{
			node[0] = node1;
			node[1] = node2;
			distance = _distance;
		}

		int first_node() const { return node[0]; }
		
		int second_node() const { return node[1]; }

		int getDistance() const { return distance; }

		// 연산자 오버로딩
		bool operator<(Edge& edge)
		{
			return this->distance < edge.distance;
		}
	};

	void Show2()
	{
		vector<Edge> edges;
		edges.push_back(Edge(1,2,10));
		edges.push_back(Edge(1,3,15));
		edges.push_back(Edge(2,3,5));
		edges.push_back(Edge(2,4,5));
		edges.push_back(Edge(3,4,25));

		sort(edges.begin(), edges.end());


		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first_node() << ", " << edge.second_node() << "), weight : " << edge.getDistance() << endl;
		}

		

		
	}
}

namespace Union_Find
{
	int getParent(int arr[], int x)	// 그래프가 주어졌을 때 루트 노드 찾기
	{
		if (x = arr[x]) return x;

		return getParent(arr, arr[x]);
	}

	void UnionParent(int arr[], int a, int b)		// 두개의 그래프를 하나로 합친다
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		if (a < b) arr[b] = a;
		else
		{
			arr[a] = b;
		}
	}

	bool findParent(int arr[], int a, int b)	// 부모가 같은지 아닌지
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		if (a == b)
			return true;
		else
			return false;
	}
}
