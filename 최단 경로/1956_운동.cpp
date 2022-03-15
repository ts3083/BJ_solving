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
	cin >> v >> e; // ���� ���� / ���� ����
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c; // ��� ���� / ���� ���� / �Ÿ�
		graph[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int a = 1; a <= v; a++) {
			for (int b = 1; b <= v; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int result = INF;
	for (int a = 1; a <= v; a++) {
		result = min(result, graph[a][a]);
	}
		
	if (result == INF)
		cout << -1 << '\n';
	else
		cout << result << '\n';

	return 0;
}