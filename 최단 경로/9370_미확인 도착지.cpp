#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 2e9

vector<pair<int, int>> graph[2001];

void dijkstra(int start, vector<int>& d) {
	priority_queue<pair<int, int>> pq; // �켱���� ť(�ִ� ��)����
	pq.push({ -0, -start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = -pq.top().second;
		pq.pop();
		if (d[now] < dist) // �̹� ó���� ����� ����
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second; // �������� ��� + �˻��ϴ� ����� ���
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

	int T; // �׽�Ʈ ���̽�
	cin >> T;
	for (int k = 0; k < T; k++) {
		int n, m, t, s, g, h; // ������ / ���� / �������ĺ� ���� / ����� / g / h 
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

		vector<int> destin; // ������ �ĺ��� ����
		for (int i = 0; i < t; i++) {
			int num;
			cin >> num;
			destin.push_back(num);
		}

		// ������ ������ �ĺ��� ���ؼ� �˰����� ����
		vector<int> arr;
		dijkstra(s, d_direct); // ������ �ĺ����� �ִܰŸ��� d_direct�� �����
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