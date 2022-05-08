#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int graph[1001][1001];
int visit[1001][1001][2];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int n, int m) {
	queue<vector<int>> q; // 0: 행, 1: 열, 2: 벽을 뚫을 수 있는 기회의 횟수
	q.push({ 1, 1, 1 });
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int block = q.front()[2];
		q.pop();
		
		if (x == n && y == m)
			return visit[x][y][block] + 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 || ny < 1 || nx > n || ny > m)
				continue;
			if (graph[nx][ny] == 0 && visit[nx][ny][block] == 0) { // 지나갈 수 있는 곳이고 이미 지나간 곳이 아니면
				visit[nx][ny][block] = visit[x][y][block] + 1;
				q.push({ nx, ny, block });
			}
			if (graph[nx][ny] == 1 && block == 1) { // 벽을 만났고 벽을 뚫을 수 있다면
				visit[nx][ny][0] = visit[x][y][1] + 1;
				q.push({ nx, ny, block - 1 });
			}
		}
	}
	return -1;
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

	cout << bfs(n, m) << '\n';

	return 0;
}