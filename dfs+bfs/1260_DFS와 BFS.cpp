#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& g, int v, vector<bool>& visited) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < g[v].size(); i++) {
		if (visited[g[v][i]] == false) {
			dfs(g, g[v][i], visited);
		}
	}
}

void bfs(vector<vector<int>>& g, int v, vector<bool>& visited) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	int n;
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
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v; // 정점 개수 / 간선 개수 / 정점의 시작번호
	vector<pair<int, int>> vec(m + 1);
	for (int i = 1; i < m + 1; i++) {
		cin >> vec[i].first >> vec[i].second;
	} // 간선 그래프작성

	vector<vector<int>> graph(n + 1); // 정점 그래프작성
	for (int i = 1; i < m + 1; i++) {
		graph[vec[i].first].push_back(vec[i].second); // 인접한 정점 원소로 삽입
		graph[vec[i].second].push_back(vec[i].first); // 인접한 정점 원소로 삽입
	}
	for (int i = 1; i < n + 1; i++) {
		sort(graph[i].begin(), graph[i].end()); // 작은 노드부터 방문할 수 있도록 정렬
	} // 그래프 오름차순으로 정렬

	vector<bool> visited_dfs(n + 1, false);
	vector<bool> visited_bfs(n + 1, false);

	dfs(graph, v, visited_dfs);
	cout << '\n';
	bfs(graph, v, visited_bfs);

	return 0;
}