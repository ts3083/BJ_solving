#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9

vector<vector<int>> graph(401, vector<int>(401, INF));

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int v, e, a, b, c;
	cin >> v >> e; // 마을 개수 / 도로 개수
	for (int a = 1; a <= v; a++) {
		for (int b = 1; b <= v; b++) {
			if (a == b)
				graph[a][b] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c; // 출발 마을 / 도착 마을 / 거리
		if (graph[a][b] > c)
			graph[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int a = 1; a <= v; a++) {
			for (int b = 1; b <= v; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	vector<int> list(v + 1, INF);
	int temp1, temp2;
	for (int a = 1; a <= v; a++) {
		for (int k = 1; k <= v; k++) {
			if (a != k) {
				temp1 = graph[a][k]; temp2 = graph[k][a];
				if (temp1 == INF || temp2 == INF)
					continue;
				list[a] = min(list[a], temp1 + temp2);
			}
		}
	}

	int min = INF;
	for (int i = 1; i <= v; i++) {
		if (list[i] < min)
			min = list[i];
	}

	if (min == INF)
		cout << -1 << '\n';
	else
		cout << min << '\n';

	return 0;
}