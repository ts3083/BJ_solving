#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[100001];
bool visited[100001];

int solve(int n, int k) {
	priority_queue<pair<int, int>> pq;
	int now, nx, weight;
	pq.push({ -0, -n });
	graph[n] = 0;
	visited[n] = true;
	while (!pq.empty()) {
		now = -pq.top().second;
		weight = -pq.top().first;
		pq.pop();
		if (now == k)
			break;

		for (int i = 0; i < 3; i++) {
			if (i == 0) 
				nx = now * 2;
			else if (i == 1) 
				nx = now + 1;
			else 
				nx = now - 1;
			if (nx < 0 || nx > 100000 || visited[nx] == true)
				continue;

			if (i == 0) {
				pq.push({ -weight, -nx });
				visited[nx] = true;
				graph[nx] = graph[now];
			}
			else {
				pq.push({ -weight-1, -nx });
				visited[nx] = true;
				graph[nx] = graph[now] + 1;
			}
		}
	}
	return graph[k];
}

int main()
{
	int n, k; // 수빈의 위치, 동생의 위치
	cin >> n >> k;

	cout << solve(n, k) << '\n';

	return 0;
}