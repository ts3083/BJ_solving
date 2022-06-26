#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

vector<int> d(20001, INF);
vector<pair<int, int>> graph[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minheap
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) // 이미 저장된 거리가 더 짧다 == 이미 처리된 노드이다
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = d[now] + graph[now][i].second; // graph는 second가 가중치이다
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ cost, graph[now][i].first });
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int V, e, k, u, v, w; // v = 정점의 개수 / e = 간선의 개수 / k = 시작 정점의 번호
	cin >> V >> e >> k;

	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w; // 시작 노드 / 도착 노드 / 거리
		graph[u].push_back({ v, w });
	}

	dijkstra(k);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

	return 0;
}
