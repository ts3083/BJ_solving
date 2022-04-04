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
			// ���� ������ ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (d[cur] != INF && d[next_node] > d[cur] + cost) {
				d[next_node] = d[cur] + cost;
				// ���� ��ȯ�� ���ٸ� �ִ� n - 1���� �������� ���ŵ��� �ʴ´�(1���� ����Ŭ)
				// �׷��� ���� ��ȯ�� ��ӵȴٸ� n��°���� ������ �Ͼ ���̴�(���� ������ ��ȯ)
				if (i == n - 1)
					return true; // ������ �Ͼ�ٸ� �ٷ� ����
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
	cin >> n >> m; // ������ ���� / ���� �뼱�� ����
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({ a, b, c }); // a������� b���õ��� c�ð�
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