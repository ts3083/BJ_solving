#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define INF INT_MAX

vector<pair<int, int>> graph[801];

void dijkstra(int start, vector<int>& d) {
	priority_queue<pair<int, int>> pq; // 최대 힙
	pq.push({ -0, -start }); // 시작노드에서 시작노드까지 거리는 0
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first; // 현재노드의 거리
		int now = -pq.top().second; // 현재노드
		pq.pop();
		if (d[now] < dist) // 이미 처리된 노드라면 무시
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			// 현재노드와 인접한 노드들의 최단거리를 갱신할 수 있으면 갱신하고
			// 갱신되었다면 그 노드의 정보를 pq에 push한다
			int cost = dist + graph[now][i].second; // 현재노드의 비용 + 인접노드까지의 비용
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, -graph[now][i].first });
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, e, a, b, c, v1, v2;
	cin >> n >> e; // 정점의 개수 n / 간선의 개수 e
	vector<int> d1(n + 1, INF);
	vector<int> d2(n + 1, INF);
	vector<int> d3(n + 1, INF);

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c; // 시작 노드 / 도착 노드 / 거리
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	
	int result1, result2;
	dijkstra(1, d1);
	int a1 = d1[v1];
	int b1 = d1[v2];
	dijkstra(v1, d2);
	int a2 = d2[v2];
	int b3 = d2[n];
	dijkstra(v2, d3);
	int a3 = d3[n];
	int b2 = d3[v1];

	if (a1 == INF || a2 == INF || a3 == INF)
		result1 = INF;
	else
		result1 = a1 + a2 + a3;

	if (b1 == INF || b2 == INF || b3 == INF)
		result2 = INF;
	else
		result2 = b1 + b2 + b3;

	if (result1 == INF && result2 == INF)
		cout << -1 << '\n';
	else
		cout << min(result1, result2) << '\n';

	return 0;
}