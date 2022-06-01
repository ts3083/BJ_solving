#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_stack(vector<vector<int>>& graph, int v, vector<bool>& visited) {
	int node;
	stack<int> s;
	s.push(v);
	while (!s.empty()) {
		node = s.top();
		s.pop();
		if (visited[node] == false) { // �湮���� ���� �����
			cout << node << ' ';
			visited[node] = true;
			for (int i = 0; i < graph[node].size(); i++) {
				if (visited[graph[node][i]] == false) {
					s.push(graph[node][i]);
				}
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

	dfs_stack(graph, v, visited);

	return 0;
}
