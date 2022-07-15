#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> graph(101, false);
vector<pair<int, int>> snake(101);
vector<bool> snake_visited(101, false);
vector<pair<int, int>> ladder(101);
vector<bool> ladder_visited(101, false);
int n, m, x, y, u, v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y; // 사다리 출발 x, 도착 y
		ladder[x] = { x, y };
		ladder_visited[x] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v; // 뱀 출발 u, 도착 v
		snake[u] = { u, v };
		snake_visited[u] = true;
	}

	int now = 1, next, count = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 1 });
	while (!q.empty()) {
		now = q.front().second;
		count = q.front().first;
		q.pop();
		if (now == 100)
			break;
		for (int i = 1; i <= 6; i++) {
			next = now + i;
			if (next > 100 || graph[next])
				continue;
			if (ladder_visited[next]) {
				next = ladder[next].second;
			}
			if (snake_visited[next]) {
				next = snake[next].second;
			}
			if (graph[next] == false) {
				graph[next] = true;
				q.push({ count + 1, next });
			}
		}
	}

	cout << count << '\n';

	return 0;
}
