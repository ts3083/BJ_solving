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
	cout << "���۳�� �Է� : ";
	cin >> v; // ���� ���� / ������ ���۹�ȣ
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
	}; // ���� �׷����ۼ�

	bfs_queue(graph, v, visited);

	return 0;
}
