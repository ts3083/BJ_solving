#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

vector<long long> d(501, INF);
bool negative_cycle;

bool bellman_ford(vector<vector<int>>& edges, int start, int n, int m) {
	d[start] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur = edges[j][0];
			int next_node = edges[j][1];
			int cost = edges[j][2];
			// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (d[cur] != INF && d[next_node] > d[cur] + cost) {
				d[next_node] = d[cur] + cost;
				// 만약 순환이 없다면 최대 n - 1번의 갱신이후 갱신되지 않는다(1번의 사이클)
				// 그런데 음의 순환이 계속된다면 n번째에도 갱신이 일어날 것이다(음수 간선의 순환)
				if (i == n - 1)
					return true; // 갱신이 일어난다면 바로 종료
			}
		}
	}
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, a, b, c;
	cin >> n >> m; // 도시의 개수 / 버스 노선의 개수
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({ a, b, c }); // a도시출발 b도시도착 c시간
	}

	negative_cycle = bellman_ford(edges, 1, n, m);

	if (negative_cycle == true)
		cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; i++) {
			if (d[i] == INF)
				cout << -1 << '\n';
			else
				cout << d[i] << '\n';
		}
	}
	return 0;
}