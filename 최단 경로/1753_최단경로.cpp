#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
#define INF INT_MAX

vector<int> d(20001, INF); // �ִܰŸ��� �����ϴ� ���̺�
vector<pair<int, int>> graph[20001]; // �� ����� ������ ����� ������ ��� ����Ʈ ����

void dijkstra(int start) {
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

	int V, e, k, u, v, w; // v = ������ ���� / e = ������ ���� / k = ���� ������ ��ȣ
	cin >> V >> e >> k;
	
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w; // ���� ��� / ���� ��� / �Ÿ�
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