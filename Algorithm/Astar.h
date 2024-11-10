#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


namespace FoundPath
{
    const int N = 5;
    const int WALL = -1;
    const int START = 0;
    const int GOAL = N * N - 1;

    struct Node {
        int x, y;
        int f, g, h;
        Node* parent;

        Node(int x, int y, int g = 0, int h = 0, Node* parent = nullptr)
            : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
    };

    struct CompareNode {
        bool operator()(Node* a, Node* b) {
            return a->f > b->f;
        }
    };

    int heuristic(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
    }

    vector<vector<int>> generateRandomGrid(int n) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i != 0 || j != 0) && (i != n - 1 || j != n - 1)) {
                    grid[i][j] = (rand() % 3 == 0) ? WALL : 0;
                }
            }
        }
        return grid;
    }

    vector<Node*> getNeighbors(Node* current, vector<vector<int>>& grid) {
        vector<Node*> neighbors;
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; ++i) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] != WALL) {
                neighbors.push_back(new Node(nx, ny));
            }
        }
        return neighbors;
    }

    void printPath(Node* node) {
        vector<int> path;
        while (node) {
            path.push_back(node->x * N + node->y);
            node = node->parent;
        }
        reverse(path.begin(), path.end());
        for (int p : path) {
            cout << p << " ";
        }
        cout << endl;
    }

    int aStar(vector<vector<int>>& grid) {
        priority_queue<Node*, vector<Node*>, CompareNode> openList;
        vector<vector<bool>> closedList(N, vector<bool>(N, false));

        Node* start = new Node(0, 0);
        start->h = heuristic(0, 0, N - 1, N - 1);
        start->f = start->g + start->h;
        openList.push(start);

        while (!openList.empty()) {
            Node* current = openList.top();
            openList.pop();

            if (current->x == N - 1 && current->y == N - 1) {
                printPath(current);
                return 0;
            }

            closedList[current->x][current->y] = true;
            vector<Node*> neighbors = getNeighbors(current, grid);

            for (Node* neighbor : neighbors) {
                if (closedList[neighbor->x][neighbor->y]) continue;

                neighbor->g = current->g + 1;
                neighbor->h = heuristic(neighbor->x, neighbor->y, N - 1, N - 1);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;

                openList.push(neighbor);
            }
        }
        return -1;
    }

    int Print() {
        vector<vector<int>> grid = generateRandomGrid(N);
        cout << "Generated Grid (0: Free, -1: Wall):" << endl;
        for (const auto& row : grid) {
            for (int cell : row) {
                cout << (cell == WALL ? "#" : ".") << " ";
            }
            cout << endl;
        }

        cout << "Shortest Path from Start to Goal: ";
        if (aStar(grid) == -1) {
            cout << "-1 (No path found)" << endl;
            return -1;
        }
        return 0;

    }

    void GetBoard()
    {
        while (Print() == -1)
        {
            Print();
        }
    }
}
