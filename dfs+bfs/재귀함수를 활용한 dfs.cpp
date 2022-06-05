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

	dfs_recursive(graph, v, visited);

	return 0;
}
