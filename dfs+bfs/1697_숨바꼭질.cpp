#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph(100001, 0);

void bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		// 3번의 연산 1칸이동 + 2배이동
		if (index == end)
			break;

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0)
				nx = index + 1;
			else if (i == 1)
				nx = index - 1;
			else
				nx = index * 2;

			if (nx < 0 || nx > 100000)
				continue;
			// 범위 안에 있고 그 위치에 처음가는 것이라면 큐 안에 삽입
			if (graph[nx] == 0) {
				q.push(nx);
				graph[nx] = graph[index] + 1;
			}
		}
	}
}

int main()
{
	int n, k; // 수빈의 위치 / 동생의 위치
	cin >> n >> k;

	bfs(n, k);

	cout << graph[k] << '\n';

	return 0;
}