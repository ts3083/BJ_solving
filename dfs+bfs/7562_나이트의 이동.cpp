#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs(vector<vector<int>>& g, int l, pair<int, int>& start, pair<int, int>& end) {
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (q.front() == end)
			break;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l)
				continue;
			if (g[nx][ny] == 0) {
				pair<int, int> p;
				p.first = nx;
				p.second = ny;
				q.push(p);
				g[nx][ny] = g[x][y] + 1;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l;
		pair<int, int> start, end;
		cin >> l;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		
		vector<vector<int>> graph(l, vector<int>(l, 0));
		bfs(graph, l, start, end);

		cout << graph[end.first][end.second] << '\n';
	}

	return 0;
}