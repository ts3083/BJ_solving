#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define INF INT_MAX

int n, e, a, b, c, v1, v2;
vector<pair<int, int>> graph[801];

int dijkstra(int start, int end) {
	vector<int> d(n + 1, INF);
	priority_queue<pair<int, int>> pq; // �ִ� ��
	pq.push({ -0, -start }); // ���۳�忡�� ���۳����� �Ÿ��� 0
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first; // �������� �Ÿ�
		int now = -pq.top().second; // ������
		pq.pop();
		if (d[now] < dist) // �̹� ó���� ����� ����
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			// ������� ������ ������ �ִܰŸ��� ������ �� ������ �����ϰ�
			// ���ŵǾ��ٸ� �� ����� ������ pq�� push�Ѵ�
			int cost = dist + graph[now][i].second; // �������� ��� + ������������ ���
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, -graph[now][i].first });
			}
		}
	}
	return d[end];
}

void solve() {
	int result1, result2;
	int a1 = dijkstra(1, v1);
	int a2 = dijkstra(v1, v2);
	int a3 = dijkstra(v2, n);
	int b1 = dijkstra(1, v2);
	int b2 = dijkstra(v2, v1);
	int b3 = dijkstra(v1, n);

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
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> e; // ������ ���� n / ������ ���� e
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c; // ���� ��� / ���� ��� / �Ÿ�
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	solve();
	
	return 0;
}