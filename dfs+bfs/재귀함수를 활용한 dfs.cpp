#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_recursive(vector<vector<int>>& g, int v, vector<bool>& visited) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < g[v].size(); i++) {
		if (visited[g[v][i]] == false) {
			dfs_recursive(g, g[v][i], visited);
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

	dfs_recursive(graph, v, visited);

	return 0;
}
