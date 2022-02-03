#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int graph[101][101][101];
queue<tuple<int, int, int>> q;
int dh[] = { 1, -1, 0, 0, 0, 0 }; // 위 아래 상하죄우
int di[] = { 0, 0, -1, 1, 0, 0 };
int dj[] = { 0, 0, 0, 0, -1, 1 };

// H 높이, M 가로, N 세로
void visit(int h, int i, int j, int H, int N, int M) {
	for (int k = 0; k < 6; k++) {
		int nh = h + dh[k];
		int ni = i + di[k];
		int nj = j + dj[k];
		if (nh < 0 || ni < 0 || nj < 0 || nh >= H || ni >= N || nj >= M) {
			continue;
		}
		if (graph[nh][ni][nj] == 0) {
			q.push({ nh, ni, nj });
			graph[nh][ni][nj] = graph[h][i][j] + 1;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int H, M, N;
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[h][i][j];
				if (graph[h][i][j] == 1) {
					q.push({ h, i, j }); // 익은 토마토의 위치를 q에 저장
				}
			}
		}
	} // graph 입력받기 완료

	while (!q.empty()) {
		tuple<int, int, int>  t;
		t = q.front();
		int h = get<0>(t);
		int i = get<1>(t);
		int j = get<2>(t);
		q.pop();
		visit(h, i, j, H, N, M);
	}

	int max = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[h][i][j] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (graph[h][i][j] > max)
					max = graph[h][i][j];
			}
		}
	}

	cout << max - 1 << '\n';

	return 0;
}