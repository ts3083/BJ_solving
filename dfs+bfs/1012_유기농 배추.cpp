#include <iostream>
using namespace std;

int graph[50][50] = { };
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };

void dfs(int r, int c, int m, int n) {
	graph[r][c] = 0; // 1을 0으로 변환
	// 상화좌우 확인하면서 인접한 배추를 재귀적으로 dfs실행
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (graph[nx][ny] == 1)
			dfs(nx, ny, m, n);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t; // 테스트 케이스 입력받음

	for (int i = 0; i < t; i++) { // t번 실행
		int m, n, total; // 가로, 세로, 배추 총 개수
		int x, y;
		int count = 0;
		cin >> m >> n >> total;
		for (int j = 0; j < total; j++) {
			cin >> x >> y;
			graph[x][y] = 1;
		} // 배추가 심어져있는 땅 지도 완성

		// 인접한 배추의 단지가 몇 인지 카운트
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				if (graph[row][col] == 1) {
					dfs(row, col, m, n);
					count++;
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}