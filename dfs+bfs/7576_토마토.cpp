#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[1000][1000];
queue<pair<int, int>> q;
int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };
int cnt = 0;

void visit(int i, int j, int m, int n) { // 딱 하루만큼 토마토를 익게하는 함수
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (graph[nx][ny] == 0) {
			q.push({ nx, ny });
			graph[nx][ny] = graph[i][j] + 1;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				q.push({ i, j }); // 익은 토마토의 위치를 q에 push
			}
		}
	} // 그래프 입력받기 완료
	
	while (!q.empty()) { // 익힐 수 있는 토마토를 모두 익히도록 설정
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit(x, y, m, n);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0)
				max = 1001;
			if (graph[i][j] > max)
				max = graph[i][j];
		}
	}

	if (max == 1001) // 안 익힌 토마토가 존재한다면
		cout << -1 << '\n'; // -1 출력
	else // 그래프의 모든 토마토를 익힐 수 있다면
		cout << max - 1 << '\n'; // 며칠이 걸렸는지 출력

	return 0;
}