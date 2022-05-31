#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_queue(vector<vector<int>>& g, int v, vector<bool>& visited) {
	int n;
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		cout << n << " ";
		for (int i = 0; i < g[n].size(); i++) {
			if (visited[g[n][i]] == false) {
				q.push(g[n][i]);
				visited[g[n][i]] = true;
			}
		}
	}
}


int main()
{
	int v;
	cout << "시작노드 입력 : ";
	cin >> v; // 정점 개수 / 정점의 시작번호
	vector<bool> visited(9, false);

	vector<vector<int>> graph = {
		{},
		{2,3,8},
		{1,7},
		{1,4,5},
		{3,5},
		{3,4},
		{7},
		{2,6,8},
		{1,7}
	}; // 정점 그래프작성

	bfs_queue(graph, v, visited);

	return 0;
}
