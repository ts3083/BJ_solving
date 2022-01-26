#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> graph(101, vector<int>(101, 0));
int dx[] = { -1, 1, 0, 0 }; // »óÇÏÁÂ¿ì
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y, int n, int m) {
	queue<pair<int, int>> q;
	pair<int, int> p;
	p.first = x;
	p.second = y;
	q.push(p);
	while (!q.empty()) {
		pair<int, int> pp;
		pp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pp.first + dx[i];
			int ny = pp.second + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m)
				continue;
			if (graph[nx][ny] == 1) {
				p.first = nx;
				p.second = ny;
				q.push(p);
				graph[nx][ny] = graph[pp.first][pp.second] + 1;
			}
		}
	}	
}

int main()
{
	int n, m;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			graph[i][j] = str[j - 1] - '0';
		}
	}

	bfs(1, 1, n, m);
	cout << graph[n][m] << '\n';

	return 0;
}