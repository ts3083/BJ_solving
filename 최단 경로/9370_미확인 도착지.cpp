#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 2e9

vector<pair<int, int>> graph[2001];

void dijkstra(int start, vector<int>& d) {
	priority_queue<pair<int, int>> pq; // 우선순위 큐(최대 힙)선언
	pq.push({ -0, -start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = -pq.top().second;
		pq.pop();
		if (d[now] < dist) // 이미 처리된 노드라면 무시
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second; // 현재노드의 비용 + 검사하는 노드의 비용
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

	int T; // 테스트 케이스
	cin >> T;
	for (int k = 0; k < T; k++) {
		int n, m, t, s, g, h; // 교차로 / 도로 / 목적지후보 갯수 / 출발지 / g / h 
		cin >> n >> m >> t >> s >> g >> h;
		vector<int> d_direct(n + 1, INF);
		vector<int> d_g_start(n + 1, INF);
		vector<int> d_h_start(n + 1, INF);

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			graph[a].push_back({ b, d });
			graph[b].push_back({ a, d });
		}

		vector<int> destin; // 목적지 후보를 저장
		for (int i = 0; i < t; i++) {
			int num;
			cin >> num;
			destin.push_back(num);
		}

		// 각각의 목적지 후보에 대해서 알고리즘을 실행
		vector<int> arr;
		dijkstra(s, d_direct); // 각각의 후보지의 최단거리는 d_direct에 저장됨
		int way_startTog = d_direct[g];
		int way_startToh = d_direct[h];
		dijkstra(g, d_g_start);
		int via = d_g_start[h];
		dijkstra(h, d_h_start);
		for (int i = 0; i < t; i++) {
			int end = destin[i];
			int shortest = d_direct[end];
			int way_gToend = d_g_start[end];
			int way_hToend = d_h_start[end];
			
			int result1, result2;
			if (way_startTog == INF || via == INF || way_hToend == INF) {
				result1 = INF;
			}
			else {
				result1 = way_startTog + via + way_hToend;
			}
			if (way_startToh == INF || via == INF || way_gToend == INF) {
				result2 = INF;
			}
			else {
				result2 = way_startToh + via + way_gToend;
			}
			
			if (shortest != INF && result1 != INF ) {
				if (shortest == result1)
					arr.push_back(end);
			}
			if (shortest != INF && result2 != INF) {
				if (shortest == result2)
					arr.push_back(end);
			}
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
		}
	}
	return 0;
}