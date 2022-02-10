#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
#define INF INT_MAX

vector<int> d(20001, INF); // 최단거리를 저장하는 테이블
vector<pair<int, int>> graph[20001]; // 각 노드의 인접한 노드의 정보를 담는 리스트 선언

void dijkstra(int start) {
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
				pq.push({ -cost, -graph[now][i].first});
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