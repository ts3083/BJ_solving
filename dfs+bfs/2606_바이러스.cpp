#include <iostream>
#include <vector>
using namespace std;

int c = -1; // 1번 컴퓨터도 세기 때문에 -1부터 시작

void dfs(vector<vector<int>>& g, int start, vector<bool>& visited) {
	visited[start] = true; // 방문표시
	c++; // 컴퓨터수 하나 증가
	for (int i = 0; i < g[start].size(); i++) {
		if (visited[g[start][i]] == false) { // 방문하지 않은 노드라면
			dfs(g, g[start][i], visited);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m; // 컴퓨터 개수 / 간선의 개수
	vector<pair<int, int>> vec(m + 1);
	vector<vector<int>> graph(n + 1);

	for (int i = 1; i < m + 1; i++) {
		cin >> vec[i].first >> vec[i].second;
	} // 간선그래프 작성
	for (int i = 1; i < m + 1; i++) {
		graph[vec[i].first].push_back(vec[i].second);
		graph[vec[i].second].push_back(vec[i].first);
	} // 정점그래프로 다시 작성

	vector<bool> visited_dfs(n + 1, false);

	dfs(graph, 1, visited_dfs);
	cout << c << '\n';

	return 0;
}