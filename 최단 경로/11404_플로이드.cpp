#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9

vector<vector<int>> graph(101, vector<int>(101, INF));

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, m, a, b, c;
	cin >> n >> m; // 도시의 개수 / 버스의 개수
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)
				graph[a][b] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; // 출발 도시 / 도착 도시 / 비용
		if (graph[a][b] > c)
			graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF)
				cout << 0 << ' ';
			else
				cout << graph[a][b] << ' ';
		}
		cout << '\n';
	}

	return 0;
}