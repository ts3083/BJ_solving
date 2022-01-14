#include <iostream>
#include <vector>
using namespace std;

int c = -1; // 1�� ��ǻ�͵� ���� ������ -1���� ����

void dfs(vector<vector<int>>& g, int start, vector<bool>& visited) {
	visited[start] = true; // �湮ǥ��
	c++; // ��ǻ�ͼ� �ϳ� ����
	for (int i = 0; i < g[start].size(); i++) {
		if (visited[g[start][i]] == false) { // �湮���� ���� �����
			dfs(g, g[start][i], visited);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m; // ��ǻ�� ���� / ������ ����
	vector<pair<int, int>> vec(m + 1);
	vector<vector<int>> graph(n + 1);

	for (int i = 1; i < m + 1; i++) {
		cin >> vec[i].first >> vec[i].second;
	} // �����׷��� �ۼ�
	for (int i = 1; i < m + 1; i++) {
		graph[vec[i].first].push_back(vec[i].second);
		graph[vec[i].second].push_back(vec[i].first);
	} // �����׷����� �ٽ� �ۼ�

	vector<bool> visited_dfs(n + 1, false);

	dfs(graph, 1, visited_dfs);
	cout << c << '\n';

	return 0;
}